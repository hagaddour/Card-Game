#include "spell.h"
#include "ascii_graphics.h"

using namespace std;

Spell::Spell(string name, int cost, string descrip) : Card{name, cost, "Spell", descrip} {}

vector<std::string> Spell::getAscTemp()
{
    return display_spell(this->getName(), this->getCost(), this->getDescrip());
}
