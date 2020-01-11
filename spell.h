#ifndef __SPELL_H__
#define __SPELL_H__

#include <memory>
#include "card.h"

//forward decl of board, used in the use function
class Board;

class Spell : public Card
{
public:
    Spell(std::string name, int cost, std::string descrip);
    std::vector<std::string> getAscTemp() override;
    //PV - abstract
    virtual void use(std::shared_ptr<Board> myBoard,
                     int p, std::string t,
                     std::shared_ptr<Board> oppBoard) = 0;
};

#endif
