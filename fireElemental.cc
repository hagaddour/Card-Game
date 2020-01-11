#include "ascii_graphics.h"
#include "fireElemental.h"
using namespace std;

FireElemental::FireElemental() : Minion{"Fire Elemental", 2,
                                        "Whenever an opponent's minion enters play, deal 1 damage to it.",
                                        2, 2, 0} {}

std::vector<std::string> FireElemental::getAscTemp()
{
    return display_minion_triggered_ability(getName(), getCost(), getAtk(), getDef(), getDescrip());
}
