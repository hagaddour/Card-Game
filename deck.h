#ifndef __DECK_H__
#define __DECK_H__

#include "card.h"
#include <memory>

class Deck
{
    std::string name;
    std::vector<std::shared_ptr<Card>> cards;

public:
    Deck();
    Deck(std::string file);
    void init(std::string filename);
    void shuffle(int p);
    int decksize();
    std::shared_ptr<Card> draw();
};

#endif
