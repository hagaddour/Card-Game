#ifndef __ENRAGE_H__
#define __ENRAGE_H__
#include "enchantment.h"

class Enrage : public Enchantment, public std::enable_shared_from_this<Enrage>
{
    public:
    Enrage();
    void use(std::shared_ptr<Minion> minion) override;
    std::vector<std::string> getAscTemp() override;
};

#endif
