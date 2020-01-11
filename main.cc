#include <fstream>
#include <iostream>
#include <memory>
#include <sstream>
#include <string>
#include <utility>
#include "graphicsdisplay.h"
#include "window.h"
#include "ascii_graphics.h"
#include "auraOfPower.h"
#include "banish.h"
#include "board.h"
#include "card.h"
#include "darkRitual.h"
#include "deck.h"
#include "earthElemental.h"
#include "fireElemental.h"
#include "player.h"
#include "print.h"
#include "standstill.h"

using namespace std;

int main(int argc, char *argv[])
{
	auto p1 = make_shared<Player>();
	auto p2 = make_shared<Player>();
	p1->opponent = p2;
	p2->opponent = p1;
	vector<shared_ptr<Player>> players;
	players.emplace_back(p1);
	players.emplace_back(p2);
	std::shared_ptr<GraphicsDisplay> gd = nullptr;
	bool testing = false;
	bool init = false;
	bool done = false;
	bool graphic = false;
	int turn = 1;
	shared_ptr<Player> curPlayer = p1;
	shared_ptr<Player> otherPlayer = p2;

	string input;

	for (int i = 1; i < argc; i++)
	{
		string arg = argv[i];
		if (arg == "-deck1")
		{
			i++;
			p1->myDeck = make_shared<Deck>(argv[i]);
		}
		if (arg == "-deck2")
		{
			i++;
			p2->myDeck = make_shared<Deck>(argv[i]);
		}
		if (arg == "-init")
		{
			init = true;
			ifstream initFile;
			++i;
			initFile.open(argv[i]);
			string in;
			if (initFile.is_open())
			{
				initFile >> p1->name;
				p1->pnum = 1;
				p1->myBoard->owner = 1;
				p1->myDeck->shuffle(0);
				initFile >> p2->name;
				p2->pnum = 2;
				p2->myBoard->owner = 2;
				for (int i = 0; i < 5; i++)
				{
					p1->draw();
					p2->draw();
				}
				while (!initFile.eof())
				{
					getline(initFile, input);
					istringstream iss(input);
					string command;
					iss >> command;
					if (command == "end")
					{
						curPlayer->turnEnd();
						turn == 1 ? turn = 2 : turn = 1;
						using std::swap;
						swap(otherPlayer, curPlayer);
						curPlayer->turnStart();
						if (!testing)
						{
							curPlayer->gainMagic(1);
							curPlayer->draw();
							curPlayer->MP = curPlayer->MP;
						}
					}
					else if (command == "quit")
					{
						done = true;
					}
					else if (command == "draw")
					{
						if (testing)
						{
							turn == 1 ? p1->draw() : p2->draw();
						}
					}
					else if (command == "discard")
					{
						if (testing)
						{
							int i;
							if (iss >> i)
							{
								turn == 1 ? p1->discard(i) : p2->discard(i);
							}
							else
							{
								cout << "Please enter a number between 1 and 5" << endl;
							}
						}
					}
					else if (command == "attack")
					{
						int i, j;
						iss >> i;
						shared_ptr<Minion> myMinion = curPlayer->myBoard->minions[i - 1];
						if (iss >> j)
						{
							cout << "attacking enemy minion" << endl;
							shared_ptr<Minion> oppMinion = otherPlayer->myBoard->minions[j - 1];
							myMinion->attack(oppMinion);
							if (p1->myBoard->checkDead() || p2->myBoard->checkDead())
							{
								p1->myBoard->checkDead();
								p2->myBoard->checkDead();
								p1->minionDied();
								p2->minionDied();
							}
						}
						else
						{
							cout << "attacking enemy player " << endl;
							int otherHP = myMinion->attack(otherPlayer);
							cout << otherPlayer->name << " has " << otherHP << " HP left!" << endl;
							if (otherHP <= 0)
							{
								cout << "____________________________________________________" << endl;
								cout << "____________________________________________________" << endl;
								cout << "____________________________________________________" << endl;
								cout << otherPlayer->name << "'s life points have been reduced to 0." << endl;
								cout << curPlayer->name << " has won!" << endl;
								return 0;
							}
						}
					}
					else if (command == "play")
					{
						int i, p, t;
						string temp;
						if (iss >> i)
						{
							if (iss >> p)
							{
								iss >> temp;
								if (temp == "r")
								{
									turn == 1 ? p1->play(i, p, 'r') : p2->play(i, p, 'r');
								}
								else if (stringstream(temp) >> t)
								{
									turn == 1 ? p1->play(i, p, t) : p2->play(i, p, t);
								}
								else
								{
									turn == 1 ? p1->play(i) : p2->play(i);
								}
							}
							else
							{
								turn == 1 ? p1->play(i) : p2->play(i);
							}
						}
						if (p1->myBoard->checkDead() || p2->myBoard->checkDead())
						{
							p1->myBoard->checkDead();
							p2->myBoard->checkDead();
							p1->minionDied();
							p2->minionDied();
						}
					}
					else if (command == "use")
					{
						int i, p, t;
						string temp;
						if (iss >> i)
						{
							if (iss >> p)
							{
								iss >> temp;
								if (temp == "r")
								{
									p == 1 ? curPlayer->use(i, p1, -1) : curPlayer->use(i, p2, -1);
								}
								else if (stringstream(temp) >> t)
								{
									p == 1 ? curPlayer->use(i, p1, t) : curPlayer->use(i, p2, t);
								}
								else
								{
									turn == 1 ? p1->use(i) : p2->use(i);
								}
							}
							else
							{
								turn == 1 ? p1->use(i) : p2->use(i);
							}
						}
						if (p1->myBoard->checkDead() || p2->myBoard->checkDead())
						{
							p1->myBoard->checkDead();
							p2->myBoard->checkDead();
							p1->minionDied();
							p2->minionDied();
						}
					}
					else if (command == "inspect")
					{
						int i;
						iss >> i;
						turn == 1 ? p1->inspect(i) : p2->inspect(i);
					}
					else if (command == "hand")
					{
						turn == 1 ? p1->displayHand() : p2->displayHand();
					}
					else if (command == "board")
					{
						p1->displayBoard();
					}
				}
			}
		}
		if (arg == "-testing")
		{
			p1->tester = true;
			p2->tester = true;
			testing = true;
		}
		if (arg == "-graphics")
		{
			graphic = true;
		}
	}
	cout << endl;

	if (!testing)
	{
		p1->myDeck->shuffle(0);
		p2->myDeck->shuffle(1);
	}
	if (!init)
	{
		cout << "Enter name of player 1: ";
		cin >> p1->name;
		p1->pnum = 1;
		p1->myBoard->owner = 1;
		cout << "Enter name of player 2: ";
		cin >> p2->name;
		p2->pnum = 2;
		p2->myBoard->owner = 2;
		for (int i = 0; i < 4; i++)
		{
			p1->draw();
			p2->draw();
		}
		p1->draw();
	}
	if (graphic)
	{
		gd = std::make_shared<GraphicsDisplay>();
		gd->GraphicsDisplayHand(p1->myHand);
	}

	turn == 1 ? cout << "Your Turn: " << p1->name << endl : cout << "Your Turn: " << p2->name << endl;

	while (!done)
	{
		getline(cin, input);
		istringstream iss(input);
		string command;
		iss >> command;
		if (cin.eof())
			break;

		if (command == "help")
		{
			cout << "Commands: help-- Display this message." << endl;
			cout << "\t end -- End the current player's turn." << endl;
			cout << "\t quit -- End the game." << endl;
			cout << "\t attack minion other-minion -- Orders minion to attack other-minion." << endl;
			cout << "\t attack minion -- Orders minion to attack the opponent." << endl;
			cout << "\t play card [target-player target-card] -- Play card, optionally targeting target-card owned by target-player" << endl;
			cout << "\t use minion [target-player target-card] -- Use minion's special ability, optionally targeting target-card owned by target-player." << endl;
			cout << "\t inspect minion -- View a minion's card and all enchantments on that minion." << endl;
			cout << "\t hand -- Describe all cards in your hand." << endl;
			cout << "\t board -- Describe all cards on the board." << endl;
		}

		else if (command == "end")
		{
			curPlayer->turnEnd();
			turn == 1 ? turn = 2 : turn = 1;
			using std::swap;
			swap(otherPlayer, curPlayer);
			curPlayer->turnStart();
			curPlayer->gainMagic(1);
			curPlayer->draw();
			curPlayer->MP = curPlayer->MP;
			if (graphic)
				turn == 1 ? gd->GraphicsDisplayHand(p1->myHand) : gd->GraphicsDisplayHand(p2->myHand);
		}

		else if (command == "quit")
		{
			done = true;
		}

		else if (command == "draw")
		{
			if (testing)
			{
				turn == 1 ? p1->draw() : p2->draw();
			}
		}

		else if (command == "discard")
		{
			if (testing)
			{
				int i;
				if (iss >> i)
				{
					turn == 1 ? p1->discard(i) : p2->discard(i);
				}
				else
				{
					cout << "Needs to be a number between 1 and 5" << endl;
				}
			}
		}

		else if (command == "attack")
		{
			int i, j;
			iss >> i;
			shared_ptr<Minion> myMinion = curPlayer->myBoard->minions[i - 1];
			if (myMinion)
			{
				if (myMinion->getAct() == 0)
				{
					cout << myMinion->getName() << " Does not have enough actions to attack" << endl;
				}
				else
				{
					if (iss >> j)
					{
						shared_ptr<Minion> oppMinion = otherPlayer->myBoard->minions[j - 1];
						cout << curPlayer->name << "'s " << myMinion->getName() << " attacks " << otherPlayer->name << "'s " << oppMinion->getName() << "!" << endl;
						if (oppMinion)
						{
							myMinion->attack(oppMinion);
							myMinion->setAct(myMinion->getAct() - 1);
							if (p1->myBoard->checkDead() || p2->myBoard->checkDead())
							{
								p1->myBoard->checkDead();
								p2->myBoard->checkDead();
								p1->minionDied();
								p2->minionDied();
							}
						}
						else
						{
							cout << "Your opponent doesn't have minion in position " << j << endl;
						}
					}
					else
					{
						cout << curPlayer->name << "'s " << myMinion->getName() << " attacks " << otherPlayer->name << "!" << endl;
						int otherHP = myMinion->attack(otherPlayer);
						myMinion->setAct(myMinion->getAct() - 1);
						cout << otherPlayer->name << " has " << otherHP << " HP left!" << endl;
						if (otherHP <= 0)
						{
							cout << "____________________________________________________" << endl;
							cout << "____________________________________________________" << endl;
							cout << "____________________________________________________" << endl;
							cout << otherPlayer->name << "'s life points have been reduced to 0." << endl;
							cout << curPlayer->name << " has won!" << endl;
							return 0;
						}
					}
				}
			}
			else
			{
				cout << "You don't have minion in position " << i << "." << endl;
			}
		}
		else if (command == "play")
		{
			int i, p, t;
			string temp;
			if (iss >> i)
			{
				if (iss >> p)
				{
					iss >> temp;
					if (temp == "r")
					{
						turn == 1 ? p1->play(i, p, -1) : p2->play(i, p, -1);
					}
					else if (stringstream(temp) >> t)
					{
						turn == 1 ? p1->play(i, p, t) : p2->play(i, p, t);
					}
					else
					{
						turn == 1 ? p1->play(i) : p2->play(i);
					}
				}
				else
				{
					turn == 1 ? p1->play(i) : p2->play(i);
				}
			}
			if (p1->myBoard->checkDead() || p2->myBoard->checkDead())
			{
				p1->myBoard->checkDead();
				p2->myBoard->checkDead();
				p1->minionDied();
				p2->minionDied();
			}
			if (graphic)
				turn == 1 ? gd->GraphicsDisplayHand(p1->myHand) : gd->GraphicsDisplayHand(p2->myHand);
		}

		else if (command == "use")
		{
			int i, p, t;
			string temp;
			if (iss >> i)
			{
				if (iss >> p)
				{
					iss >> temp;
					if (temp == "r")
					{
						p == 1 ? curPlayer->use(i, p1, -1) : curPlayer->use(i, p2, -1);
					}
					else if (stringstream(temp) >> t)
					{
						p == 1 ? curPlayer->use(i, p1, t) : curPlayer->use(i, p2, t);
					}
					else
					{
						turn == 1 ? p1->use(i) : p2->use(i);
					}
				}
				else
				{
					turn == 1 ? p1->use(i) : p2->use(i);
				}
			}
			else
			{
				cout << "Proper Usage: use minion [target-player target-card] -- Use a minion's special ability, optionally targetting target-card owned by target-player." << endl;
			}

			if (p1->myBoard->checkDead() || p2->myBoard->checkDead())
			{
				p1->myBoard->checkDead();
				p2->myBoard->checkDead();
				p1->minionDied();
				p2->minionDied();
			}
		}

		else if (command == "inspect")
		{
			int i;
			iss >> i;
			turn == 1 ? p1->inspect(i) : p2->inspect(i);
		}

		else if (command == "hand")
		{
			turn == 1 ? p1->displayHand() : p2->displayHand();
		}

		else if (command == "board")
		{
			p1->displayBoard();
			if (graphic)
			{
				gd->displayTheBoard(p1);
			}
		}
	}
}
