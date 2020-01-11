#include "apprenticeSummoner.h"
#include "ascii_graphics.h"

using namespace std;

ApprenticeSummoner::ApprenticeSummoner() : Minion{"Apprentice Summoner", 1,
                                                  "Summon a 1/1 air elemental",
                                                  1, 1, 1}
{
    hasAbility = true;
}

vector<string> ApprenticeSummoner::getAscTemp()
{
    return display_minion_activated_ability(getName(), getCost(), getAtk(), getDef(), getACost(), getDescrip());
}
