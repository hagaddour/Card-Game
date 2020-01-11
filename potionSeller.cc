#include <vector>
#include "ascii_graphics.h"
#include "potionSeller.h"

using namespace std;

PotionSeller::PotionSeller() : Minion{"Potion Seller", 2,
                                      "At the end of your turn, all your minion gain +0/+1",
                                      1, 3, 0} {}

vector<string> PotionSeller::getAscTemp()
{
    return display_minion_triggered_ability(getName(), getCost(), getAtk(), getDef(), getDescrip());
}
