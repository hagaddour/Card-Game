#include "ascii_graphics.h"
#include "novicePyromancer.h"

using namespace std;

NovicePyromancer::NovicePyromancer() : Minion{"Novice Pyromancer", 1,
                                              "Deal 1 damage to target minion",
                                              0, 1, 1}
{
    hasAbility = true;
}

vector<string> NovicePyromancer::getAscTemp()
{
    return display_minion_activated_ability(getName(), getCost(), getAtk(), getDef(), getACost(), getDescrip());
}
