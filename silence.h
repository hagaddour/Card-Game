#ifndef __SILENCE_H__
#define __SILENCE_H__
#include <memory>
#include "card.h"
#include "enchantment.h"

class Minion;

class Silence : public Enchantment, public std::enable_shared_from_this<Silence>
{
public:
    Silence();
    std::vector<std::string> getAscTemp() override;
    void use(std::shared_ptr<Minion> minion);
};
#endif
