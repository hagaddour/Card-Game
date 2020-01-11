
#ifndef __UNSUMMON_H__
#define __UNSUMMON_H__

#include <memory>
#include "card.h"
#include "spell.h"

class Unsummon : public Spell
{
public:
    Unsummon();
    void use(std::shared_ptr<Board> myBoard, int p,
             std::string t, std::shared_ptr<Board> oppBoard) override;
};

#endif
