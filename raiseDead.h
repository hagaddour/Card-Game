#ifndef __RAISEDEAD_H__
#define __RAISEDEAD_H__
#include <memory>
#include "card.h"
#include "spell.h"

class RaiseDead : public Spell
{
public:
    RaiseDead();
    void use(std::shared_ptr<Board> myBoard, int p, std::string t,
             std::shared_ptr<Board> oppBoard) override;
};

#endif
