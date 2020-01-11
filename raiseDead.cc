#include "board.h"
#include "raiseDead.h"

using namespace std;

RaiseDead::RaiseDead() : Spell{"Raise Dead", 1,
                               "Resurrect the top minion in your graveyard"} {}

void RaiseDead::use(shared_ptr<Board> myBoard, int p, string t, shared_ptr<Board> oppBoard)
{
    myBoard->resurrect();
}
