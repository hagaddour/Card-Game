#include "ascii_graphics.h"
#include "earthElemental.h"
using namespace std;

EarthElemental::EarthElemental() : Minion{"Earth Elemental", 3, "", 4, 4, 0} {}

std::vector<std::string> EarthElemental::getAscTemp()
{
    return display_minion_no_ability(getName(), getCost(), getAtk(), getDef());
}
