#ifndef __ABILITY_H__
#define __ABILITY_H__

#include <memory>
#include <string>
#include <vector>

//forward decl of classes used
class Minion;
class Board;
class Player;

class Ability
{
    std::string name;
    int cost;

public:
    Ability(std::string name, int cost);
    //setters/getters
    void setCost(int nCost);
    int getCost();
    std::string getName();

    void activate(std::shared_ptr<Minion> minion, std::shared_ptr<Board> board);
};

#endif
