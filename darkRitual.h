#ifndef __DARKRITUAL_H__
#define __DARKRITUAL_H__

#include <memory>
#include "ritual.h"

class Board;
class Minion;
class Player;

class DarkRitual : public Ritual
{

public:
	DarkRitual();
	void activate(Player *player = nullptr,
				  std::shared_ptr<Board> board = nullptr,
				  std::shared_ptr<Minion> minion = nullptr);
};
#endif
