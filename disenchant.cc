#include <iostream>
#include <sstream>
#include "board.h"
#include "disenchant.h"
#include "enchantment.h"

using namespace std;

Disenchant::Disenchant() : Spell{"Disenchant", 1,
                                 "Destroy the top enchantment on target minion"} {}
void Disenchant::use(shared_ptr<Board> myBoard, int p, string t, shared_ptr<Board> oBoard)
{
    std::istringstream iss{t};
    int i;
    iss >> i;
    if (p == myBoard->owner)
    {
        if (myBoard->minions[i - 1]->enchants.empty())
            return;
        std::shared_ptr<Minion> aminion = myBoard->minions[i - 1];
        std::shared_ptr<Enchantment> enchant = static_pointer_cast<Enchantment>(myBoard->minions[i - 1]->enchants.back());
        if (enchant->getName() == "Giant Strength")
        {
            aminion->setAtk(aminion->getAtk() - 2);
            aminion->setDef(aminion->getDef() - 2);
        }
        else if (enchant->getName() == "Haste")
        {
            aminion->setModAct(aminion->getModAct() - 1);
            aminion->setAct(aminion->getAct() - 1);
        }
        else if (enchant->getName() == "Enrage")
        {
            aminion->setAtk(aminion->getAtk() / 2);
            aminion->setDef(aminion->getDef() / 2);
        }
        else if (enchant->getName() == "Magic Fatigue")
        {
            cerr << "here is good?" << endl;
            aminion->setACost(aminion->getACost() - 2);
        }
        else if (enchant->getName() == "Silence")
        {
            aminion->hasAbility = true;
        }
        myBoard->minions[i - 1]->enchants.pop_back();
    }
    else
    {
        if (oBoard->minions[i - 1]->enchants.empty())
            return;
        std::shared_ptr<Minion> otherMinion = oBoard->minions[i - 1];
        std::shared_ptr<Enchantment> otherEnchant = static_pointer_cast<Enchantment>(oBoard->minions[i - 1]->enchants.back());
        if (otherEnchant->getName() == "Giant Strength")
        {
            otherMinion->setAtk(otherMinion->getAtk() - 2);
            otherMinion->setDef(otherMinion->getDef() - 2);
        }
        else if (otherEnchant->getName() == "Haste")
        {
            otherMinion->setModAct(otherMinion->getModAct() - 1);
            otherMinion->setAct(otherMinion->getAct() - 1);
        }
        else if (otherEnchant->getName() == "Enrage")
        {
            otherMinion->setAtk(otherMinion->getAtk() / 2);
            otherMinion->setDef(otherMinion->getDef() / 2);
        }
        else if (otherEnchant->getName() == "Magic Fatigue")
        {
            otherMinion->setACost(otherMinion->getACost() - 2);
        }
        else if (otherEnchant->getName() == "Silence")
        {
            otherMinion->hasAbility = true;
        }
        oBoard->minions[i - 1]->enchants.pop_back();
    }
}
