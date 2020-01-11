#include "airElemental.h"
#include "ascii_graphics.h"

using namespace std;

AirElemental::AirElemental() : Minion{"Air Elemental", 0, "", 1, 1, 0} {}

vector<string> AirElemental::getAscTemp()
{
    return display_minion_no_ability(getName(), getCost(), getAtk(), getDef());
}
