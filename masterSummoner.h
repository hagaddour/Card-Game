#ifndef __MASTERSUM_H__
#define __MASTERSUM_H__
#include <memory>
#include "card.h"
#include "minion.h"

class MasterSummoner : public Minion
{
public:
    MasterSummoner();
    std::vector<std::string> getAscTemp() override;
};
#endif
