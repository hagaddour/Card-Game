#ifndef __STANDSTILL_H__
#define __STANDSTILL_H__
#include <memory>
#include "ritual.h"
#include "player.h"

class Board;
class Minion;

class Standstill : public Ritual
{

public:
	Standstill();
	void activate(Player *player = nullptr, std::shared_ptr<Board> board = nullptr,
				  std::shared_ptr<Minion> minion = nullptr);
};
#endif
