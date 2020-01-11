#ifndef __EARTHELE_H__
#define __EARTHELE_H__
#include "card.h"
#include "minion.h"

class EarthElemental : public Minion
{
public:
    EarthElemental();
    std::vector<std::string> getAscTemp() override;
};

#endif
