#ifndef __PLAYER_H__
#define __PLAYER_H__
#include <memory>
#include <string>
#include <vector>
#include "board.h"
#include "deck.h"
#include "minion.h"

class Player
{
public:
    std::string name;
    //player number
    int pnum;
    std::shared_ptr<Player> opponent;

    std::shared_ptr<Deck> myDeck = std::make_shared<Deck>();
    std::shared_ptr<Board> myBoard = std::make_shared<Board>(pnum);

    std::vector<std::shared_ptr<Card>> myHand;
    std::vector<std::shared_ptr<Card>> played;

    bool tester;

    int HP = 20;
    int MP = 3;

    Player();
    Player(std::string name, int n);

    void draw();
    void discard(int i);
    void gainMagic(int i);

    void play(int i);
    void play(int i, int p, int t);

    void use(int i);
    void use(int i, std::shared_ptr<Player> p, int t);

    void inspect(int i);
    void displayHand();
    void displayBoard();
    int takeDmg(int dmg);

    // function for start of turn triggers
    void turnStart();
    // function for end of turn triggers
    void turnEnd();
    // function for minion summoned triggers
    void summoned(std::shared_ptr<Minion> minion);
    // function for dead minion triggers
    void minionDied();
};
#endif
