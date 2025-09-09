#include <iostream>
#include "war.h"

War::War() : isGameOver(false) {}

War::~War() {
    for (Card* card : allCards) {
        delete card;
    }
}

void War::play() {
    std::cout << "Welcome to War!" << std::endl;
    std::cout << "The deck will be split among players. Highest card wins the round." << std::endl;
    std::cout << "If both players draw equal value, it's a war." << std::endl << std::endl;

    splitCards();

    while (!isGameOver) {
        showScore();

        if (!continueGame()) {
            std::cout << "\nYou chose to end the game early." << std::endl;
            break;
        }

        battleCards();

        isGameOver = checkWin();
    }

    showScore();

    if (isGameOver) {
        if (humanDeck.empty())
            std::cout << "Computer wins the game" << std::endl;
        else
            std::cout << "You win the game" << std::endl;
    }
}

void War::splitCards() {
    Deck* deck = new Deck();
    deck->shuffle();

    for (int i = 0; i < 52; ++i) {
        Card* card = deck->draw();
        if (card) {
            allCards.push_back(card);
            if (i % 2 == 0)
                humanDeck.push_back(card);
            else
                computerDeck.push_back(card);
        }
    }

    delete deck;

    std::cout << "Cards have been handed. You have " << humanDeck.size()
              << " cards and the computer has " << computerDeck.size() << " cards." << std::endl;
}

void War::battleCards() {
    std::cout << "\n--- New Round ---" << std::endl;

    if (humanDeck.empty() || computerDeck.empty()) {
        isGameOver = true;
        return;
    }

    Card* playerCard = humanDeck.front();
    humanDeck.erase(humanDeck.begin());

    Card* computerCard = computerDeck.front();
    computerDeck.erase(computerDeck.begin());

    std::cout << "Your card: " << playerCard->print() << std::endl;
    std::cout << "Computer's card: " << computerCard->print() << std::endl;

    int comparison = playerCard->compareValue(*computerCard);

    if (comparison > 0) {
        std::cout << "Congratulations, you win this round" << std::endl;
        humanDeck.push_back(playerCard);
        humanDeck.push_back(computerCard);
    } else if (comparison < 0) {
        std::cout << "Computer wins this round" << std::endl;
        computerDeck.push_back(playerCard);
        computerDeck.push_back(computerCard);
    } else {
        std::cout << "There is a tie. Time for war." << std::endl;
        warPile.push_back(playerCard);
        warPile.push_back(computerCard);
        playWar();
    }
}

void War::playWar() {
    std::cout << "\n--- WAR ---" << std::endl;

    while (true) {
        if (humanDeck.size() < 2 || computerDeck.size() < 2) {
            std::cout << "Not enough cards to continue war. Game ends." << std::endl;
            isGameOver = true;
            return;
        }

        // Face-down cards
        warPile.push_back(humanDeck.front());
        humanDeck.erase(humanDeck.begin());

        warPile.push_back(computerDeck.front());
        computerDeck.erase(computerDeck.begin());

        std::cout << "Each player places a card face down." << std::endl;

        // Face-up cards
        Card* playerUpCard = humanDeck.front();
        humanDeck.erase(humanDeck.begin());

        Card* computerUpCard = computerDeck.front();
        computerDeck.erase(computerDeck.begin());

        warPile.push_back(playerUpCard);
        warPile.push_back(computerUpCard);

        std::cout << "Your card: " << playerUpCard->print() << std::endl;
        std::cout << "Computer's card: " << computerUpCard->print() << std::endl;

        int comparison = playerUpCard->compareValue(*computerUpCard);

        if (comparison > 0) {
            std::cout << "You win the war. Collecting " << warPile.size() << " cards." << std::endl;
            humanDeck.insert(humanDeck.end(), warPile.begin(), warPile.end());
            warPile.clear();
            return;
        } else if (comparison < 0) {
            std::cout << "Computer wins the war. Collecting " << warPile.size() << " cards." << std::endl;
            computerDeck.insert(computerDeck.end(), warPile.begin(), warPile.end());
            warPile.clear();
            return;
        } else {
            std::cout << "There is another tie, war continues." << std::endl;
            // Loop continues to next war round
        }
    }
}

bool War::checkWin() {
    return humanDeck.empty() || computerDeck.empty();
}

void War::showScore() {
    std::cout << "\nCurrent score:" << std::endl;
    std::cout << "You have: " << humanDeck.size() << " cards" << std::endl;
    std::cout << "Computer has: " << computerDeck.size() << " cards" << std::endl;
}

bool War::continueGame() {
    char response;
    std::cout << "\nDo you want to continue playing? (y/n): ";
    std::cin >> response;
    std::cin.ignore(10000, '\n');
    return (response == 'y' || response == 'Y');
}
