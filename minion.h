#ifndef __MINION_H__
#define __MINION_H__
#include <vector>
#include <string>
#include <memory>
#include "card.h"
#include "ability.h"

class Player;
class Enchantment;
class Board;

class Minion : public std::enable_shared_from_this<Minion>, public Card
{
    //actions
    int act = 0;
    int modact = 1;

    int atk;
    int def;
    int ACost;

public:
    //whether or not minion has an ability
    bool hasAbility;
    //abilities
    std::shared_ptr<Ability> ability;
    //enchantments
    std::vector<std::shared_ptr<Enchantment>> enchants;

    Minion(std::string name, int cost, std::string descrip, int atk, int def, int ACost);
    //getters
    int getAtk();
    int getDef();
    int getAct();
    int getModAct();
    int getACost();
    //setters
    void setAtk(int nAtk);
    void setDef(int nDef);
    void setAct(int nAct);
    void setModAct(int nModAct);
    void setACost(int nCost);

    std::vector<std::shared_ptr<Minion>> attack(std::shared_ptr<Minion> minion);
    void addEnchant(std::shared_ptr<Enchantment> newEnch);
    int attack(std::shared_ptr<Player> player);
    void printEnchants();

    int takeDmg(int dmg);
    //PV dtor to make class abstract
    virtual ~Minion() = 0;
};

#endif
