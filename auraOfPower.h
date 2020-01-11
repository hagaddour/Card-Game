#ifndef __AURAOFP_H__
#define __AURAOFP_H__

#include <memory>
#include "player.h"
#include "ritual.h"

class Board;
class Minion;

class AuraOfPower : public Ritual
{
public:
	AuraOfPower();
	void activate(Player *player = nullptr,
				  std::shared_ptr<Board> board = nullptr,
				  std::shared_ptr<Minion> minion = nullptr);
};

#endif
