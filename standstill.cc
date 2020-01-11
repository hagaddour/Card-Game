#include <iostream>
#include "board.h"
#include "standstill.h"
using namespace std;

Standstill::Standstill() : Ritual{"Standstill", 3,
								  "Whenever a minion enters play, destroy it",
								  2, 4} {}

void Standstill::activate(Player *player, shared_ptr<Board> board, shared_ptr<Minion> minion)
{
	if (charges >= activationCost)
	{
		charges -= activationCost;
		int len = player->myBoard->minions.size();
		int Opplen = player->opponent->myBoard->minions.size();
		for (int i = 0; i < len; i++)
		{
			if (minion == player->myBoard->minions[i])
			{
				player->myBoard->sendGrave(player->myBoard->minions[i]);
				player->myBoard->minions.erase(player->myBoard->minions.begin() + i);
			}
		}
		for (int i = 0; i < Opplen; i++)
		{
			if (minion == player->opponent->myBoard->minions[i])
			{
				player->opponent->myBoard->sendGrave(player->opponent->myBoard->minions[i]);
				player->opponent->myBoard->minions.erase(player->opponent->myBoard->minions.begin() + i);
			}
		}
	}
}
