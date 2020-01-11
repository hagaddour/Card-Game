#include "ascii_graphics.h"
#include "enrage.h"
using namespace std;

Enrage::Enrage() : Enchantment{"Enrage", 2, ""} {}

void Enrage::use(shared_ptr<Minion> minion)
{
    minion->setAtk(minion->getAtk() * 2);
    minion->setDef(minion->getDef() * 2);
    minion->addEnchant(shared_from_this());
}

vector<string> Enrage::getAscTemp()
{
    return display_enchantment_attack_defence(getName(), getCost(), "", "*2", "*2");
}
