#ifndef __HASTE_H__
#define __HASTE_H__
#include "card.h"
#include "enchantment.h"

class Haste : public std::enable_shared_from_this<Haste>, public Enchantment
{
	public:
    Haste();
    std::vector<std::string> getAscTemp() override;
    void use(std::shared_ptr<Minion> minion) override;
};

#endif
