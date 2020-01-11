#include "board.h"
#include "recharge.h"

using namespace std;

Recharge::Recharge() : Spell{"Recharge", 1, "Your ritual gains 3 charges"} {}

void Recharge::use(shared_ptr<Board> myBoard, int p, string t, shared_ptr<Board> oBoard)
{
    if (!myBoard->myRitual)
    {
        string msg = "You do not have a Ritual to recharge!";
        throw msg;
    }
    else
    {
        myBoard->gainCharge(3);
    }
}
