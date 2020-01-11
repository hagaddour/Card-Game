#ifndef __RECHARGE_H__
#define __RECHARGE_H__

#include <memory>
#include "card.h"
#include "spell.h"

class Recharge : public Spell
{
public:
    Recharge();
    void use(std::shared_ptr<Board> myBoard, int p, std::string t,
             std::shared_ptr<Board> oBoard) override;
};
#endif
