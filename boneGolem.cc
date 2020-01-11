#include "ascii_graphics.h"
#include "boneGolem.h"
using namespace std;

BoneGolem::BoneGolem() : Minion{"Bone Golem", 2,
                                "Gain +1/+1 whenever a minion leaves play.",
                                1, 3, 0} {}

std::vector<std::string> BoneGolem::getAscTemp()
{
    return display_minion_triggered_ability(getName(), getCost(), getAtk(), getDef(), getDescrip());
}
