#ifndef __BANISH_H__
#define __BANISH_H__

#include <memory>
#include <string>
#include <vector>
#include "card.h"
#include "spell.h"

class Banish : public Spell
{
public:
    Banish();
    void use(std::shared_ptr<Board> myBoard, int p, std::string t,
             std::shared_ptr<Board> oBoard) override;
};
#endif
