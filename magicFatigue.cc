#include "ascii_graphics.h"
#include "magicFatigue.h"
#include "minion.h"

using namespace std;

MagicFatigue::MagicFatigue() : Enchantment{"Magic Fatigue", 0,
                                           "Enchanted minion's activated ability costs 2 more"} {}

vector<string> MagicFatigue::getAscTemp()
{
    return display_enchantment(getName(), getCost(), getDescrip());
}

void MagicFatigue::use(shared_ptr<Minion> minion)
{
    minion->setACost(minion->getACost() + 2);
    minion->addEnchant(shared_from_this());
}
