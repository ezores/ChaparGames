//
// Created by CycleWSWin on 12/28/2023.
//

#include "../../includes/Games/SynonymGame.h"

SynonymGame::SynonymGame(std::string playerName) : Game("Synonym Game", playerName), maxAttempts(5) {
    synonyms = {"happy", "smart", "beautiful", "strong", "creative"};
}

void SynonymGame::start() {
    // Select a random synonym for the game
    srand(static_cast<unsigned>(time(nullptr)));
    currentWord = synonyms[rand() % synonyms.size()];

    // Game logic
    // ...
}

void SynonymGame::end() {
    // Display final score
    std::cout << "Game Over! " << getPlayerName() << "'s score: " << getScore() << std::endl;
}

void SynonymGame::rules() const {
    // Display game rules
    std::cout << "Synonym Game Rules:" << std::endl;
    std::cout << "Try to guess the synonym of the given word." << std::endl;
    std::cout << "You have a maximum of " << maxAttempts << " attempts." << std::endl;
}


