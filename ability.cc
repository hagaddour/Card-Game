#include <iostream>
#include "ability.h"
//airElemental required for Apprentice/Master Summoner
#include "airElemental.h"
#include "board.h"
#include "minion.h"
#include "player.h"

using namespace std;

Ability::Ability(string name, int cost) : name{name}, cost{cost} {}

void Ability::setCost(int nCost)
{
    cost = nCost;
}

int Ability::getCost()
{
    return cost;
}

string Ability::getName()
{
    return name;
}

void Ability::activate(shared_ptr<Minion> minion, shared_ptr<Board> board)
{
    if (name == "Bone Golem")
    {
        cout << "Bone Golem ability has been triggered!" << endl;
        minion->setAtk(minion->getAtk() + 1);
        minion->setDef(minion->getDef() + 1);
    }
    else if (name == "Fire Elemental")
    {
        cout << "Fire Elemental ability used on: " << minion->getName() << "."<<endl;
        minion->setDef(minion->getDef() - 1);
    }
    else if (name == "Potion Seller")
    {
        cout << "Potion Seller ability has been triggered!" << endl;
        for (unsigned int i = 0; i < board->minions.size(); i++)
        {
            board->minions[i]->setDef(board->minions[i]->getDef() + 1);
        }
    }
    else if (name == "Novice Pyromancer")
    {
        cout << "Novice Pyromancer ability used on: " << minion->getName() << "."<<endl;
        minion->setDef(minion->getDef() - 1);
    }
    else if (name == "Apprentice Summoner")
    {
        if (board->minions.size() < 5)
        {
            cout << "Apprentice Summoner ability used: summoned Air Elemental" << endl;
            board->minions.emplace_back(make_shared<AirElemental>());
        }
        else
            cout << "Apprentice Summoner ability failed due to lack of minion slots." << endl;
    }
    else if (name == "Master Summoner")
    {
        int summoned = 0;
        if (3 < 5 - board->minions.size())
        {
            summoned = 3;
            cout << "Master Summoner ability used: summoned " << 3 << " Air Elemental(s)." << endl;
            for (unsigned int i = 0; i < 3; ++i)
            {
                board->minions.emplace_back(make_shared<AirElemental>());
            }
        }
        else if (5 - board->minions.size() > 0)
        {
            summoned = 5 - board->minions.size();
            cout << "Master Summoner ability used: summoned " << summoned << " Air Elemental(s)." << endl;
            for (unsigned int i = 0; i < 5 - board->minions.size(); ++i)
            {
                board->minions.emplace_back(make_shared<AirElemental>());
            }
        }
        else
            cout << "Master Summoner ability failed due to lack of minion slots." << endl;
    }
}
