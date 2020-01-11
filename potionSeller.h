#ifndef __POTIONSELLER_H__
#define __POTIONSELLER_H__

#include <memory>
#include "card.h"
#include "minion.h"

class PotionSeller : public Minion
{
public:
    PotionSeller();
    std::vector<std::string> getAscTemp() override;
};
#endif
