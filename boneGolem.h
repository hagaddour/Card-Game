#ifndef __BONEGOLEM_H__
#define __BONEGOLEM_H__

#include <memory>
#include <string>
#include <vector>
#include "card.h"
#include "minion.h"

class BoneGolem : public Minion
{
public:
    BoneGolem();
    std::vector<std::string> getAscTemp() override;
};

#endif
