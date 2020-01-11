#include "blizzard.h"
#include "board.h"

using namespace std;

Blizzard::Blizzard() : Spell{"Blizzard", 3, "Deal 2 damage to all minions"} {}

void Blizzard::use(shared_ptr<Board> myBoard, int p, string t, shared_ptr<Board> oBoard)
{
    for (unsigned int i = 0; i < myBoard->minions.size(); i++)
    {
        myBoard->minions[i]->takeDmg(2);
    }

    for (unsigned int i = 0; i < oBoard->minions.size(); i++)
    {
        oBoard->minions[i]->takeDmg(2);
    }
}
