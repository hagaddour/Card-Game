#ifndef __NOVICEPYRO_H__
#define __NOVICEPYRO_H__

#include <memory>
#include "card.h"
#include "minion.h"
using namespace std;

class NovicePyromancer : public Minion
{
public:
    NovicePyromancer();
    std::vector<std::string> getAscTemp() override;
};
#endif
