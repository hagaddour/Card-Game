#ifndef GRAPHICSDISPLAY_H
#define GRAPHICSDISPLAY_H
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "window.h"
#include "card.h"
using namespace std;

class Player;

class GraphicsDisplay {
  Xwindow Display{1000 , 1000}; //a graphic display of the game
 public:
//  GraphicsDisplay(); // the ctor for the class
  void GraphicsDisplayHand(vector<shared_ptr<Card>> hand);
  void displayTheBoard(shared_ptr<Player> p);



};
#endif
