#include "minion.h"
#include "auraOfPower.h"
#include "board.h"
#include <iostream>

using namespace std;

AuraOfPower::AuraOfPower() : Ritual{"Aura of Power", 1,
                                    "Whenever a minion enter a play under your control, it gains +1/+1",
                                    1, 4} {}

void AuraOfPower::activate(Player *player, shared_ptr<Board> board, shared_ptr<Minion> minion)
{
    if (charges >= activationCost)
    {
        charges -= activationCost;
        minion->setAtk(minion->getAtk() + 1);
        minion->setDef(minion->getDef() + 1);
        cout << "Aura Of Power has been triggered! " << minion->getName() << " has gained +1/+1!" << endl;
    }
}
