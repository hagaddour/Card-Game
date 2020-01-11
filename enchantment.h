#ifndef __ENCHANTMENT_H__
#define __ENCHANTMENT_H__
#include "card.h"
#include "minion.h"

class Enchantment : public Card
{
public:
    Enchantment(std::string name, int cost, std::string descrip);
    virtual std::vector<std::string> getAscTemp() = 0;
    virtual void use(std::shared_ptr<Minion> minion) = 0;
};

#endif
