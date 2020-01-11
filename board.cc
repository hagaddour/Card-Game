#include <iostream>
#include <memory>

#include "airElemental.h"
#include "apprenticeSummoner.h"
#include "ascii_graphics.h"
#include "board.h"
#include "boneGolem.h"
#include "card.h"
#include "earthElemental.h"
#include "fireElemental.h"
#include "masterSummoner.h"
#include "novicePyromancer.h"
#include "potionSeller.h"

using namespace std;

Board::Board(int owner) : owner{owner} {}

void Board::summon(shared_ptr<Card> m)
{
    if (minions.size() >= 5)
        cout << "No available boardspace." << endl;
    else
    {
        m->print(m->getAscTemp());
        minions.emplace_back(static_pointer_cast<Minion>(m));
        cout << "You have " << minions.size() << " minions on the board." << endl;
    }
}

void Board::sendGrave(shared_ptr<Minion> m)
{
    cout << m->getName() << " was sent to the graveyard!" << endl;
    graveyard.emplace_back(m);
    cout << "There are now " << graveyard.size() << " minions in the graveyard." << endl;
}

void Board::resurrect()
{
    if (minions.size() >= 5)
    {
        string err = "No minion space";
        throw err;
    }
    else if (!graveyard.empty())
    {
        shared_ptr<Minion> newMinion = graveyard.back();
        newMinion->setDef(1);
        graveyard.pop_back();
        cout << "You resurrected " << newMinion->getName() << ": " << endl;
        newMinion->print(newMinion->getAscTemp());
        summon(newMinion);
        cout << "There are " << graveyard.size() << " cards in the graveyard" << endl;
    }
    else
    {
        string err = "There are no minions in the graveyard.";
        throw err;
    }
}

vector<string> Board::graveFace()
{
    string name;
    if (!graveyard.empty())
        name = graveyard.back()->getName();
    else
    {
        return CARD_TEMPLATE_BORDER;
    }

    shared_ptr<Card> newMin = nullptr;

    if (name == "Air Elemental")
        newMin = make_shared<AirElemental>();
    else if (name == "Earth Elemental")
        newMin = make_shared<EarthElemental>();
    else if (name == "Bone Golem")
        newMin = make_shared<BoneGolem>();
    else if (name == "Fire Elemental")
        newMin = make_shared<FireElemental>();
    else if (name == "Potion Seller")
        newMin = make_shared<PotionSeller>();
    else if (name == "Novice Pyromancer")
        newMin = make_shared<NovicePyromancer>();
    else if (name == "Apprentice Summoner")
        newMin = make_shared<ApprenticeSummoner>();
    else if (name == "Master Summoner")
        newMin = make_shared<MasterSummoner>();
    else
        newMin = make_shared<AirElemental>();

    return newMin->getAscTemp();
}

bool Board::checkDead()
{
    bool died = false;
    for (int i = minions.size() - 1; i >= 0; --i)
    {
        if (minions[i]->getDef() <= 0)
        {
            sendGrave(minions[i]);
            minions.erase(minions.begin() + i);
            died = true;
        }
    }
    return died;
}

void Board::actRitual(shared_ptr<Card> r)
{
    myRitual = static_pointer_cast<Ritual>(r);
    cout << "Ritual played: " << endl;
    myRitual->print(myRitual->getAscTemp());
}

void Board::gainCharge(int i)
{
    myRitual->charges = myRitual->charges + i;
    cout << "Charges increased to " << myRitual->charges << endl;
}
