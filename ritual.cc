#include "ascii_graphics.h"
#include "ritual.h"

using namespace std;

Ritual::Ritual(string name, int cost,
               string description,
               int activationCost, int charges) : Card{name, cost, "Ritual", description},
                                                  activationCost{activationCost},
                                                  charges{charges} {}

vector<string> Ritual::getAscTemp()
{
    return display_ritual(getName(), getCost(), activationCost, getDescrip(), charges);
}
