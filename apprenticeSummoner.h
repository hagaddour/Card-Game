#ifndef __APPRENSUM_H__
#define __APPRENSUM_H__

#include <string>
#include <vector>
#include "card.h"
#include "minion.h"

class ApprenticeSummoner : public Minion
{
public:
    ApprenticeSummoner();
    std::vector<std::string> getAscTemp() override;
};

#endif
