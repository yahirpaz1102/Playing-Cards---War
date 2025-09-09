# C++ War Card Game

A command-line implementation of the classic card game "War," written in C++. This project simulates a standard 52-card deck, shuffles it, and splits it between a human player and a computer opponent.

## Features

-   **Automatic Deck Generation**: Creates a standard 52-card deck.
-   **Randomized Shuffling**: The deck is thoroughly shuffled before each game.
-   **Player vs. Computer Gameplay**: Play against an AI opponent.
-   **"War" Scenario Handling**: Correctly manages tie-breakers where both players draw cards of the same value.
-   **Interactive Gameplay**: Prompts the player to continue to the next round.
-   **Clear Score Tracking**: Displays the number of cards each player holds.

## Getting Started

To compile and run this project, you will need a C++ compiler like G++/Clang.

### Prerequisites

-   A C++ compiler that supports the C++11 standard or later (for `std::shuffle`).

### Compilation & Running

1.  **Organize Files:** Ensure all source (`.cpp`) and header (`.h`) files are in the same directory.
    -   `card.h`, `card.cpp`
    -   `deck.h`, `deck.cpp`
    -   `war.h`, `war.cpp`
    -   `main.cpp`

2.  **Compile:** Open your terminal and run the following command to create an executable file named `war`.

    ```sh
    g++ main.cpp war.cpp deck.cpp card.cpp -o war -std=c++11
    ```

3.  **Run:** Execute the compiled program from your terminal.
    ```sh
    ./war
    ```

## Code Overview

The project is structured using Object-Oriented principles and is broken down into three main classes.

### `Card` Class (`card.h`, `card.cpp`)

-   **Responsibility:** Represents a single playing card.
-   **Details:** Contains two `enum`s: `Suit` (Clubs, Diamonds, Hearts, Spades) and `Value` (Two through Ace). It provides methods to `print()` the card's name (e.g., "Ace of Spades") and `compareValue()` against another card.

### `Deck` Class (`deck.h`, `deck.cpp`)

-   **Responsibility:** Represents a collection of 52 `Card` objects.
-   **Details:** The constructor populates a `full_deck` with all 52 unique cards. The `shuffle()` method randomizes the deck, and `draw()` returns the top card. Note: This class creates the card objects, but memory management is handled by the `War` class.

### `War` Class (`war.h`, `war.cpp`)

-   **Responsibility:** Contains the main game logic and manages the flow of the game.
-   **Details:** Manages the decks for the human and computer players. The `play()` method contains the main game loop, which calls other methods to `splitCards()`, handle a `battleCards()` round, and resolve ties with `playWar()`.

### `main.cpp`

-   **Responsibility:** The entry point for the application.
-   **Details:** It creates an instance of the `War` class and starts the game by calling the `play()` method.
