#ifndef __AIRELE_H__
#define __AIRELE_H__

#include <string>
#include <vector>
#include "card.h"
#include "minion.h"

class AirElemental : public Minion
{
public:
    AirElemental();
    std::vector<std::string> getAscTemp() override;
};

#endif
