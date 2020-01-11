#include <iostream>
#include "ascii_graphics.h"
#include "minion.h"
#include "silence.h"

using namespace std;

Silence::Silence() : Enchantment{"Silence", 1, "Enchanted minion cannot use abilities"} {}

vector<string> Silence::getAscTemp()
{
    return display_enchantment(getName(), getCost(), getDescrip());
}

void Silence::use(shared_ptr<Minion> minion)
{
    minion->hasAbility = false;
    minion->addEnchant(shared_from_this());
}
