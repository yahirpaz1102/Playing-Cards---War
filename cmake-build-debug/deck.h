#pragma once

#include <vector>
#include <stack>
#include "card.h"

class Deck {
public:
    Deck();
    ~Deck();

    void shuffle();
    Card* draw();

protected:
    std::vector<Card*> full_deck;
    std::stack<Card*> draw_deck;
};
