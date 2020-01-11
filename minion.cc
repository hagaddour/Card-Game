#include "minion.h"
#include "player.h"
#include "enchantment.h"
#include "ascii_graphics.h"

using namespace std;

Minion::Minion(string name, int cost,
               string descrip, int atk,
               int def, int ACost) : Card{name, cost, "Minion", descrip},
                                     atk{atk}, def{def},
                                     ACost{ACost}, hasAbility{false},
                                     ability{make_shared<Ability>(name, ACost)} {}

int Minion::getAtk()
{
    return atk;
}

int Minion::getDef()
{
    return def;
}

int Minion::getAct()
{
    return act;
}

int Minion::getModAct()
{
    return modact;
}

int Minion::getACost()
{
    return ACost;
}

void Minion::setAtk(int nAtk)
{
    atk = nAtk;
}

void Minion::setModAct(int nModAct)
{
    modact = nModAct;
}

void Minion::setDef(int nDef)
{
    def = nDef;
}

void Minion::setAct(int nAct)
{
    act = nAct;
}

void Minion::setACost(int nCost)
{
    ACost = nCost;
}

void Minion::addEnchant(shared_ptr<Enchantment> newEnch)
{
    enchants.push_back(newEnch);
}

vector<shared_ptr<Minion>> Minion::attack(shared_ptr<Minion> minion)
{
    int targetHP = minion->takeDmg(atk);
    int myHP = takeDmg(minion->atk);
    vector<shared_ptr<Minion>> died;

    if (myHP <= 0)
    {
        died.push_back(shared_from_this());
    }
    else
    {
        died.push_back(nullptr);
    }

    if (targetHP <= 0)
    {
        died.push_back(minion);
    }
    else
    {
        died.push_back(nullptr);
    }

    return died;
}

int Minion::attack(shared_ptr<Player> player)
{
    return player->takeDmg(atk);
}

void Minion::printEnchants()
{
    vector<string> pEnchants;
    vector<vector<string>> enchantsAscii;
    for (int i = 0; i < enchants.size(); ++i)
    {
        enchantsAscii.emplace_back(enchants[i]->getAscTemp());
    }

    for (int k = 0; k < enchants.size(); k = k + 5)
    {
        for (int i = 0; i < 11; ++i)
        {
            string line;
            for (int j = 0; j + k < enchants.size() && j < 5; ++j)
            {
                line += enchantsAscii[j + k][i];
            }
            pEnchants.emplace_back(line);
        }
        print(pEnchants);
        pEnchants.clear();
    }
}

int Minion::takeDmg(int dmg)
{
    def -= dmg;
    return def;
}

Minion::~Minion() {}
