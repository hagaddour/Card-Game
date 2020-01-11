#ifndef __RITUAL_H__
#define __RITUAL_H__
#include <memory>
#include "card.h"

class Board;
class Player;
class Minion;

class Ritual : public Card
{
public:
	int activationCost;
	int charges;
	Ritual(std::string name, int cost, std::string description,
		   int activationCost, int charges);

	std::vector<std::string> getAscTemp() override;
	//PV - abstract
	virtual void activate(Player *player = nullptr,
						  std::shared_ptr<Board> board = nullptr,
						  std::shared_ptr<Minion> minion = nullptr) = 0;
};
#endif
