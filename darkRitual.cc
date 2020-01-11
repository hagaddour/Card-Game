#include <iostream>
#include <string>
#include "board.h"
#include "darkRitual.h"
#include "minion.h"
#include "player.h"

using namespace std;

DarkRitual::DarkRitual() : Ritual{"Dark Ritual", 0,
                                  "At the start of your turn, gain 1 magic",
                                  1, 5} {}

void DarkRitual::activate(Player *player, shared_ptr<Board> board, shared_ptr<Minion> minion)
{
    if (charges >= activationCost)
    {
        cout << "Dark Ritual has been triggered! " << player->name << " has gained 1 magic!" << endl;
        player->MP += 1;
    }
}
