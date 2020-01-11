#include <exception>
#include <iostream>
#include <memory>
#include <sstream>
#include <string>
#include <vector>
#include "ascii_graphics.h"
#include "banish.h"
#include "card.h"
#include "enchantment.h"
#include "player.h"
#include "print.h"

using namespace std;

Player::Player(string name, int n) : name{name}, pnum{n},
                                     myDeck{make_shared<Deck>()},
                                     myBoard{std::make_shared<Board>(n)},
                                     tester{false} {}

Player::Player() : name{"NPC"}, pnum{1},
                   myDeck{make_shared<Deck>()},
                   myBoard{std::make_shared<Board>(1)},
                   tester{false} {}

void Player::draw()
{
    if (myHand.size() < 5)
    {
        try
        {
            myHand.emplace_back(myDeck->draw());
        }
        catch (string s)
        {
            cout << s << endl;
        }
    }
    else
    {
        cout << "Cannot draw. Your hand is full!" << endl;
    }
}

void Player::discard(int i)
{
    if (i > 5 || i < 1)
        cout << "Please pick a number between 1 and 5." << endl;
    else if (myHand.size() < i)
        cout << "Discard failed: you only have " << myHand.size() << " cards in your hand." << endl;
    else
    {
        myHand.erase(myHand.begin() + i - 1);
        cout << "You now have " << myHand.size() << " cards remaining." << endl;
    }
}

void Player::gainMagic(int i)
{
    MP = MP + i;
    cout << "Player " << pnum << ": " << name << endl;
    cout << "Magic Available: " << MP << endl;
}

void Player::play(int i)
{
    if (myHand.size() < i)
        cout << "Invalid card number. You have " << myHand.size() << " card(s) in your hand." << endl;
    else
    {
        if (tester || MP >= myHand[i - 1]->getCost())
        {
            shared_ptr<Card> playedCard = myHand[i - 1];

            if (playedCard->getType() == "Minion")
            {
                myBoard->summon(playedCard);
                summoned(static_pointer_cast<Minion>(myHand[i - 1]));
            }
            else if (playedCard->getType() == "Ritual")
                myBoard->actRitual(playedCard);
            else if (playedCard->getType() == "Spell")
            {
                try
                {
                    (static_pointer_cast<Spell>(myHand[i - 1]))->use(myBoard, 0, "", opponent->myBoard);
                }
                catch (string msg)
                {
                    cout << msg << endl;
                }
            }
            MP = MP - myHand[i - 1]->getCost();
            myHand.erase(myHand.begin() + i - 1);
        }
        else
        {
            cout << "You do not have enough magic to play this card." << endl;
        }
	cout << "Magic Available: " << MP << endl;
    }
}

void Player::play(int i, int p, int t)
{
    if (myHand.size() >= i || t == -1)
    {
        if (MP >= myHand[i - 1]->getCost() || tester)
        {
            MP = MP - myHand[i - 1]->getCost();
            if (myHand[i - 1]->getType() == "Enchantment")
            {
                cerr << pnum << endl;
                shared_ptr<Enchantment> ePlay = static_pointer_cast<Enchantment>(myHand[i - 1]);
                if (p == pnum)
                    ePlay->use(myBoard->minions[t - 1]);
                else
                    ePlay->use(opponent->myBoard->minions[t - 1]);
                myHand.erase(myHand.begin() + i - 1);
            }
            else if (myHand[i - 1]->getType() == "Spell")
            {
                try
                {
                    string st;
                    if (t == -1)
                        st = "r";
                    else
                    {
                        ostringstream oss;
                        oss << t;
                        st = oss.str();
                    }
                    shared_ptr<Spell> sPlay = (static_pointer_cast<Spell>(myHand[i - 1]));
                    sPlay->use(myBoard, p, st, opponent->myBoard);

                    if (sPlay->getName() == "Unsummon")
                    {
                        if (p == pnum)
                        {
                            if (myHand.size() < 5)
                            {
                                myHand.emplace_back(myBoard->minions[t - 1]);
                                myBoard->minions.erase(myBoard->minions.begin() + t - 1);
                            }
                        }
                        else
                        {
                            if (opponent->myHand.size() < 5)
                            {
                                opponent->myHand.emplace_back(opponent->myBoard->minions[t - 1]);
                                opponent->myBoard->minions.erase(opponent->myBoard->minions.begin() + t - 1);
                            }
                        }
                    }
                    if (sPlay->getName() == "Banish" && t != -1)
                        this->minionDied();

                    myHand.erase(myHand.begin() + i - 1);
                }
                catch (string msg)
                {
                    cout << msg << endl;
                }
            }
        }
        else
        {
            cout << "You do not have enough magic to play this card." << endl;
        }
	cout << "Magic Available: " << MP << endl;
    }
    else
        cout << "Invalid card number. You have " << myHand.size() << " card(s) in your hand." << endl;
}

//use ith minion owned by the player
void Player::use(int i)
{
    if (i < 1 || i > 5)
    {
        cout << "Please enter a minion number between 1 and 5." << endl;
        return;
    }
    else if (i > myBoard->minions.size())
    {
        cout << "You only have " << myBoard->minions.size() << " minions." << endl;
        return;
    }

    if (myBoard->minions[i - 1]->hasAbility)
    {
        if (MP >= myBoard->minions[i - 1]->ability->getCost())
        {
            if (myBoard->minions[i - 1]->getAct() != 0)
            {
                MP = MP - myHand[i - 1]->getCost();
                if (myBoard->minions[i - 1]->ability->getName() == "Apprentice Summoner")
                    myBoard->minions[i - 1]->ability->activate(nullptr, myBoard);
                else if (myBoard->minions[i - 1]->ability->getName() == "Master Summoner")
                    myBoard->minions[i - 1]->ability->activate(nullptr, myBoard);

                myBoard->minions[i - 1]->setAct(myBoard->minions[i - 1]->getAct() - 1);
            }
            else
                cout << myBoard->minions[i - 1]->getName() << " Does not have enough actions to use and ability." << endl;
        }
        else
        {
            cout << "You do not have enough magic to play this card." << endl;
        }
	cout << "Magic Available: " << MP << endl;
    }
    else
        cout << myBoard->minions[i - 1]->getName() << " does does not have an ability." << endl;
}

void Player::use(int i, shared_ptr<Player> p, int t)
{
    if (i < 1 || i > 5)
    {
        cout << "Please enter a minion number between 1 and 5." << endl;
        return;
    }
    else if (i > myBoard->minions.size())
    {
        cout << "You only have " << myBoard->minions.size() << " minions." << endl;
        return;
    }

    if (myBoard->minions[i - 1]->hasAbility)
    {
        if (MP >= myBoard->minions[i - 1]->ability->getCost())
        {
            if (myBoard->minions[i - 1]->getAct() != 0)
            {
                if (myBoard->minions[i - 1]->ability->getName() == "Novice Pyromancer")
                {
                    if (t == -1)
                        cout << "Novice Pyromancer can only target minions." << endl;
                    else
                    {
                        myBoard->minions[i - 1]->ability->activate(p->myBoard->minions[t - 1], nullptr);
                        myBoard->minions[i - 1]->setAct(myBoard->minions[i - 1]->getAct() - 1);
                        MP = MP - myHand[i - 1]->getCost();
                    }
                }
            }
            else
                cout << myBoard->minions[i - 1]->getName() << " Does not have enough actions to use ability." << endl;
        }
        else
        {
            cout << "You do not have enough magic to play this card." << endl;
        }
	cout << "Magic Available: " << MP << endl;
    }
    else
        cout << myBoard->minions[i - 1]->getName() << " does not have an ability." << endl;
}

void Player::inspect(int i)
{
    if (i < 1 || i > 5)
    {
        cout << "Please enter a minion number between 1 and 5." << endl;
        return;
    }
    else if (i > myBoard->minions.size())
    {
        cout << "You only have " << myBoard->minions.size() << " minions." << endl;
        return;
    }
    else
    {
        myBoard->minions[i - 1]->print(myBoard->minions[i - 1]->getAscTemp());
        myBoard->minions[i - 1]->printEnchants();
    }
}

//asciiHand is helper function for hand display
vector<string> asciiHand(vector<shared_ptr<Card>> hand)
{
    vector<string> handcards;
    vector<vector<string>> handAscii;
    for (int i = 0; i < hand.size(); ++i)
    {
        handAscii.emplace_back(hand[i]->getAscTemp());
    }

    for (int i = 0; i < 11; ++i)
    {
        string line;
        for (int j = 0; j < hand.size(); ++j)
        {
            line += handAscii[j][i];
        }
        handcards.emplace_back(line);
    }

    return handcards;
}

void Player::displayHand()
{
    int j = myHand.size();
    if (j != 0)
    {
        vector<string> display = asciiHand(myHand);
        print(display);
    }
    else
    {
        cout << "You do not have any cards in your hand." << endl;
    }
}

//asciiBack and asciiMinions are helper functions for board display
vector<string> asciiBack(shared_ptr<Card> rit, vector<string> p1,
                         shared_ptr<Board> myBoard)
{
    vector<string> backrow;
    vector<string> ritDisplay = CARD_TEMPLATE_BORDER;
    vector<string> graveDisplay = myBoard->graveFace();
    if (rit)
        ritDisplay = rit->getAscTemp();
    for (int i = 0; i < 11; i++)
    {
        string line;
        line += ritDisplay[i];
        line += CARD_TEMPLATE_BORDER[i];
        line += p1[i];
        line += CARD_TEMPLATE_BORDER[i];
        line += graveDisplay[i];
        backrow.emplace_back(line);
    }
    return backrow;
}

vector<string> asciiMinions(vector<shared_ptr<Minion>> minions)
{
    vector<string> minionRow;
    vector<vector<string>> minionAscii;
    for (int i = 0; i < minions.size(); ++i)
    {
        minionAscii.emplace_back(minions[i]->getAscTemp());
    }
    for (int i = minions.size(); i < 5; ++i)
    {
        minionAscii.emplace_back(CARD_TEMPLATE_BORDER);
    }

    for (int i = 0; i < 11; ++i)
    {
        string line;
        for (int j = 0; j < 5; ++j)
        {
            line += minionAscii[j][i];
        }
        minionRow.emplace_back(line);
    }
    return minionRow;
}

void Player::displayBoard()
{
    vector<string> playercard = display_player_card(pnum, name, HP, MP);
    print(asciiBack(myBoard->myRitual, playercard, myBoard));
    print(asciiMinions(myBoard->minions));
    cout << endl;
    print(CENTRE_GRAPHIC);
    cout << endl;
    print(asciiMinions(opponent->myBoard->minions));
    vector<string> oplayercard = display_player_card(opponent->pnum, opponent->name, opponent->HP, opponent->MP);
    print(asciiBack(opponent->myBoard->myRitual, oplayercard, opponent->myBoard));
}

int Player::takeDmg(int dmg)
{
    HP = HP - dmg;
    return HP;
}

//end of turn triggers
void Player::turnEnd()
{
    for (int i = 0; i < myBoard->minions.size(); ++i)
    {
        if (myBoard->minions[i]->getName() == "Potion Seller")
        {
            myBoard->minions[i]->ability->activate(nullptr, myBoard);
        }
    }
}

//start of turn triggers
void Player::turnStart()
{
    if (myBoard->myRitual && myBoard->myRitual->getName() == "Dark Ritual")
        myBoard->myRitual->activate(this);

    int len = myBoard->minions.size();
    for (int i = 0; i < myBoard->minions.size(); i++)
    {
        if (myBoard->minions[i]->getAct() == 0)
            myBoard->minions[i]->setAct(myBoard->minions[i]->getModAct());
    }
}

//summoned triggers
void Player::summoned(shared_ptr<Minion> minion)
{
    //ritual triggers
    if (myBoard->myRitual)
    {
        if (myBoard->myRitual->getName() == "Aura of Power")
            myBoard->myRitual->activate(nullptr, nullptr, minion);
        else if (myBoard->myRitual->getName() == "Standstill")
            myBoard->myRitual->activate(this, myBoard, minion);
    }
    if (opponent->myBoard->myRitual && opponent->myBoard->myRitual->getName() == "Standstill")
    {
        opponent->myBoard->myRitual->activate(this, nullptr, minion);
        this->minionDied();
    }

    //minion triggers
    for (int i = 0; i < opponent->myBoard->minions.size(); i++)
    {
        if (opponent->myBoard->minions[i]->getName() == "Fire Elemental" && opponent->myBoard->minions[i]->ability)
            opponent->myBoard->minions[i]->ability->activate(minion, nullptr);
    }
}

//minion death triggers
void Player::minionDied()
{
    //only bone golem has a minion death trigger
    for (int i = 0; i < myBoard->minions.size(); i++)
    {
        if (myBoard->minions[i]->getName() == "Bone Golem")
            myBoard->minions[i]->ability->activate(myBoard->minions[i], nullptr);
    }
    for (int i = 0; i < opponent->myBoard->minions.size(); i++)
    {
        if (opponent->myBoard->minions[i]->getName() == "Bone Golem")
            opponent->myBoard->minions[i]->ability->activate(opponent->myBoard->minions[i], nullptr);
    }
}
