#include <vector>
#include "ascii_graphics.h"
#include "giantStrength.h"
#include "minion.h"
using namespace std;

GiantStrength::GiantStrength() : Enchantment{"Giant Strength", 1, ""} {}

std::vector<std::string> GiantStrength::getAscTemp()
{
	return display_enchantment_attack_defence(getName(), getCost(), "", "+2", "+2");
}

void GiantStrength::use(std::shared_ptr<Minion> minion)
{
	minion->setAtk(minion->getAtk() + 2);
	minion->setDef(minion->getDef() + 2);
	minion->addEnchant(shared_from_this());
}
