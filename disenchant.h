#ifndef __DISENCHANT_H__
#define __DISENCHANT_H__

#include <memory>
#include <string>
#include <vector>
#include "card.h"
#include "spell.h"

class Disenchant : public Spell
{
public:
    Disenchant();
    void use(std::shared_ptr<Board> myBoard,
             int p, std::string t,
             std::shared_ptr<Board> oppBoard) override;
};
#endif
