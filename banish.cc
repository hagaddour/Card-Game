#include <iostream>
#include <sstream>
#include "banish.h"
#include "board.h"

using namespace std;

Banish::Banish() : Spell{"Banish", 2, "Destroy target minion or ritual"} {}

void Banish::use(shared_ptr<Board> myBoard, int p, string t, shared_ptr<Board> oBoard)
{
    if (t == "r")
    {
        if (p == myBoard->owner)
            myBoard->myRitual = nullptr;
        else
            oBoard->myRitual = nullptr;
    }
    else
    {
        istringstream iss{t};
        int i;
        iss >> i;
        if (p == myBoard->owner)
        {
            myBoard->sendGrave(myBoard->minions[i - 1]);
            myBoard->minions.erase(myBoard->minions.begin() + i - 1);
        }
        else
        {
            oBoard->sendGrave(oBoard->minions[i - 1]);
            oBoard->minions.erase(oBoard->minions.begin() + i - 1);
        }
    }
}
