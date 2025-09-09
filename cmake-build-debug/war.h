#pragma once

#include <vector>
#include "deck.h"
#include "card.h"

class War {
public:
    War();
    ~War();

    void play();

private:
    void splitCards();
    void battleCards();
    void playWar();
    bool checkWin();
    void showScore();
    bool continueGame();

    std::vector<Card*> humanDeck;
    std::vector<Card*> computerDeck;
    std::vector<Card*> warPile;
    std::vector<Card*> allCards;

    bool isGameOver;
};
