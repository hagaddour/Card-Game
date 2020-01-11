#include "ascii_graphics.h"
#include "masterSummoner.h"

using namespace std;

MasterSummoner::MasterSummoner() : Minion{"Master Summoner", 3,
                                          "Summon up to three 1/1 air elementals",
                                          2, 3, 2}
{
    hasAbility = true;
}

vector<string> MasterSummoner::getAscTemp()
{
    return display_minion_activated_ability(getName(), getCost(), getAtk(), getDef(), getACost(), getDescrip());
}
