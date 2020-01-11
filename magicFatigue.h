#ifndef __MAGICFATIGUE_H__
#define __MAGICFATIGUE_H__
#include <memory>
#include "card.h"
#include "enchantment.h"

class Minion;

class MagicFatigue : public Enchantment, public std::enable_shared_from_this<MagicFatigue>
{
public:
    MagicFatigue();
    void use(std::shared_ptr<Minion> minion);
    std::vector<std::string> getAscTemp() override;
};
#endif
