#ifndef __FIREELEMENTAL_H__
#define __FIREELEMENTAL_H__

#include <memory>
#include <string>
#include <vector>
#include "card.h"
#include "minion.h"

class FireElemental : public Minion
{
public:
    FireElemental();
    std::vector<std::string> getAscTemp() override;
};
#endif
