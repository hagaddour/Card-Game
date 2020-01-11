#ifndef _GIANTSTRENGTH_H__
#define _GIANTSTRENGTH_H__
#include <memory>
#include "card.h"
#include "enchantment.h"

class Minion;

class GiantStrength : public Enchantment, public std::enable_shared_from_this<GiantStrength>
{
public:
    GiantStrength();
    void use(std::shared_ptr<Minion> minion) override;
    std::vector<std::string> getAscTemp() override;
};
#endif
