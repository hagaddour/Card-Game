#ifndef __BOARD_H__
#define __BOARD_H__

#include <exception>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include "ability.h"
#include "card.h"
#include "minion.h"
#include "player.h"
#include "ritual.h"

class Board
{
public:
    //player who owns the board: 1 or 2
    int owner;
    //minions on the board
    std::vector<std::shared_ptr<Minion>> minions;
    //graveyard for minions
    std::vector<std::shared_ptr<Minion>> graveyard;
    std::shared_ptr<Ritual> myRitual = nullptr;
    Board(int owner);
    //summon a minion
    void summon(std::shared_ptr<Card> m);
    //sends a minion to the graveyard
    void sendGrave(std::shared_ptr<Minion> m);
    //returns the display of the top card in the graveyard
    std::vector<std::string> graveFace();
    //check if any minions have <= 0 def.
    //returns true and send the minion to the graveyard if any are found
    bool checkDead();
    //revive a minion
    void resurrect();
    //activate ritual
    void actRitual(std::shared_ptr<Card> r);
    void gainCharge(int i);
};

#endif
