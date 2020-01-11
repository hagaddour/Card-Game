#include "graphicsdisplay.h"
#include "ascii_graphics.h"
#include "player.h"
#include "window.h"
#include <iostream>
using namespace std;


vector<string> asciiBack2(shared_ptr<Card> rit, vector<string> p1,
                         shared_ptr<Board> myBoard)
{
    vector<string> backrow;
    vector<string> ritDisplay = CARD_TEMPLATE_BORDER;
    vector<string> graveDisplay = myBoard->graveFace();
    if (rit)
        ritDisplay = rit->getAscTemp();
    for (int i = 0; i < 11; i++)
    {
        string line;
        line += ritDisplay[i];
        line += CARD_TEMPLATE_BORDER[i];
        line += p1[i];
        line += CARD_TEMPLATE_BORDER[i];
        line += graveDisplay[i];
        backrow.emplace_back(line);
    }
    return backrow;
}

vector<string> asciiMinions2(vector<shared_ptr<Minion>> minions)
{
    vector<string> minionRow;
    vector<vector<string>> minionAscii;
    for (int i = 0; i < minions.size(); ++i)
    {
        minionAscii.emplace_back(minions[i]->getAscTemp());
    }
    for (int i = minions.size(); i < 5; ++i)
    {
        minionAscii.emplace_back(CARD_TEMPLATE_BORDER);
    }

    for (int i = 0; i < 11; ++i)
    {
        string line;
        for (int j = 0; j < 5; ++j)
        {
            line += minionAscii[j][i];
        }
        minionRow.emplace_back(line);
    }
    return minionRow;
}

void GraphicsDisplay::displayTheBoard(shared_ptr<Player> p)
{
    vector<string> playercard = display_player_card(p->pnum, p->name, p->HP, p->MP);
    vector<string> displaytext = asciiBack2(p->myBoard->myRitual, playercard, p->myBoard);
    for (int i = 0 ; i < displaytext.size(); ++i) {
    Display.drawString(0, i*15 + 150, displaytext[i], Xwindow::Blue);
    }
    vector<string> displaytext2 =  asciiMinions2(p->myBoard->minions);
   // Display.fillRectangle(0, 400, 1000, 400, Xwindow::White);
    for (int i = 0 ; i < displaytext2.size(); ++i) {
    Display.drawString(0, i*15 + 300, displaytext2[i], Xwindow::Blue);
    }
   // cout << endl;
   // print(CENTRE_GRAPHIC);
    vector<string> displaytext3 =  CENTRE_GRAPHIC;
   // Display.fillRectangle(0, 400, 1000, 400, Xwindow::White);
    for (int i = 0 ; i < displaytext3.size(); ++i) {
    Display.drawString(0, i*15 + 450, displaytext3[i], Xwindow::Blue);
    }
    //cout << endl;
   vector<string> displaytext4 = asciiMinions2(p->opponent->myBoard->minions);
        for (int i = 0 ; i < displaytext4.size(); ++i) {
    Display.drawString(0, i*15 + 600, displaytext4[i], Xwindow::Blue);
    }
    vector<string> oplayercard = display_player_card(p->opponent->pnum, p->opponent->name, p->opponent->HP, p->opponent->MP);
   vector<string> displaytext5 = asciiBack2(p->opponent->myBoard->myRitual, oplayercard, p->opponent->myBoard);
    for (int i = 0 ; i < displaytext5.size(); ++i) {
    Display.drawString(0, i*15 + 750, displaytext5[i], Xwindow::Blue);
    }
}

vector<string> asciitheHand(vector<shared_ptr<Card>> hand)
{
    vector<string> handcards;
    vector<vector<string>> handAscii;
    for (int i = 0; i < hand.size(); ++i)
    {
        handAscii.emplace_back(hand[i]->getAscTemp());
    }

    for (int i = 0; i < 11; ++i)
    {
        string line;
        for (int j = 0; j < hand.size(); ++j)
        {
            line += handAscii[j][i];
        }
        handcards.emplace_back(line);
    }

    return handcards;
}

void GraphicsDisplay::GraphicsDisplayHand(vector<shared_ptr<Card>> hand) {
  vector<string> displaytext = asciitheHand(hand);
  Display.fillRectangle(0, 0, 1000, 1000, Xwindow::White);
  for (int i = 0 ; i < displaytext.size(); ++i) {
    Display.drawString(0, i*15, displaytext[i], Xwindow::Blue);
  }
}

// GraphicsDisplay::GraphicsDisplay() {}
  //int vol = 500/n;
  //for (size_t i = 0; i < n; ++i) {
    //for (size_t j = 0; j < n; ++j) {
   // Display.fillRectangle(vol*i, vol*j, vol, vol, Xwindow::Blue);
  //  }

/*
void GraphicsDisplay::notify(Subject<Info, State> &whoFrom) {
  Info in = whoFrom.getInfo();
  int vol = 500/gridSize;
  if (in.colour == Colour::White) {
    Display.fillRectangle(vol*in.col, vol*in.row, vol, vol, Xwindow::White);
  }
  else {
    Display.fillRectangle(vol*in.col, vol*in.row, vol, vol, Xwindow::Black);
  }
}

*/
