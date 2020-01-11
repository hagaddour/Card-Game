#ifndef __BLIZZARD_H__
#define __BLIZZARD_H__

#include <memory>
#include <string>
#include <vector>
#include "card.h"
#include "spell.h"

class Blizzard : public Spell
{

public:
    Blizzard();
    void use(std::shared_ptr<Board> myBoard,
             int p, std::string t,
             std::shared_ptr<Board> oBoard) override;
};

#endif
