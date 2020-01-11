#include "enchantment.h"

using namespace std;

Enchantment::Enchantment(string name, int cost, string descrip) : Card{name,
                                                                       cost,
                                                                       "Enchantment",
                                                                       descrip} {}
