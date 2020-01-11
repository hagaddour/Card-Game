#include "ascii_graphics.h"
#include "haste.h"

using namespace std;

Haste::Haste() : Enchantment{"Haste", 1, "Enchanted minion gains +1 action each turn"} {}

vector<string> Haste::getAscTemp()
{
	return display_enchantment(getName(), getCost(), getDescrip());
}

void Haste::use(shared_ptr<Minion> minion)
{
	minion->setModAct(minion->getModAct() + 1);
	minion->setAct(minion->getAct() + 1);
	minion->addEnchant(shared_from_this());
}
