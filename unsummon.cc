#include "unsummon.h"

using namespace std;

Unsummon::Unsummon() : Spell{"Unsummon", 1, "Return target minion to its owner's hand"} {}

void Unsummon::use(shared_ptr<Board> myBoard, int p, string t, shared_ptr<Board> oppBoard)
{
    //unsummon implemented in main
}
