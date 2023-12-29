//
// Created by CycleWSWin on 12/28/2023.
//

#include "../../includes/Games/SynonymGame.h"

SynonymGame::SynonymGame() : Game("Synonym Game", "Player Name"), maxAttempts(5) {
    synonyms = {"happy", "smart", "beautiful", "strong", "creative"};
}

SynonymGame::SynonymGame(std::string playerName) : Game("Synonym Game", playerName), maxAttempts(5) {
    synonyms = {"happy", "smart", "beautiful", "strong", "creative"};
}

void SynonymGame::start() {
    printf("TEST SYNONYM\n");
    srand(static_cast<unsigned>(time(nullptr))); //NEEDS TO BE CHANGED - We need to predict the word from the sentence
    currentWord = synonyms[rand() % synonyms.size()]; //NEEDS TO BE CHANGED - We need to predict the word from the sentence

    currentWord = synonyms[0];
    cout << "Guess the synonym of: " << currentWord << endl;

    // Game logic
    int attempts = 0;
    string userGuess;

    while (attempts < maxAttempts) {
        cout << "Attempt " << attempts + 1 << ": ";
        cin >> userGuess;

        if (userGuess == currentWord) {
            cout << "Correct! You guessed the synonym." << endl;
            score += (maxAttempts - attempts); // Update the score based on the number of attempts
            break;
        } else {
            cout << "Incorrect. Try again." << endl;
            attempts++;
        }
    }

    // Display the correct synonym
    cout << "The synonym was: " << currentWord << endl;

    end(); // End the game and display the final score
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


