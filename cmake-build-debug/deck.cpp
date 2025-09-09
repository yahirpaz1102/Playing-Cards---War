#include <random>
#include "deck.h"

static std::random_device rd;
static std::mt19937 rng(rd());

Deck::Deck() {
    for (int suit = Card::CLUB; suit <= Card::SPADE; suit++) {
        for (int value = Card::TWO; value <= Card::ACE; value++) {
            Card* card = new Card((Card::Suit)suit, (Card::Value)value);
            this->full_deck.push_back(card);
        }
    }
}

Deck::~Deck() {
    // Do not delete cards here!
    // Card memory is managed by War class via allCards[]
}

void Deck::shuffle() {
    while (!this->draw_deck.empty()) {
        this->draw_deck.pop();
    }

    std::shuffle(this->full_deck.begin(), this->full_deck.end(), rng);

    for (Card* card : this->full_deck) {
        this->draw_deck.push(card);
    }
}

Card* Deck::draw() {
    if (this->draw_deck.empty()) {
        return nullptr;
    }
    Card* draw_card = this->draw_deck.top();
    this->draw_deck.pop();
    return draw_card;
}
