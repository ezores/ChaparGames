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
    // Select a random synonym for the game
    std::map <std::string, std::vector<std::string>> synonymMap = {
            {"happy", {"glad", "joyful", "merry", "cheerful", "delighted"}},
            {"smart", {"clever", "intelligent", "bright", "brilliant", "sharp"}},
            {"beautiful", {"pretty", "lovely", "handsome", "attractive", "gorgeous"}},
            {"strong", {"powerful", "mighty", "tough", "solid", "firm"}},
            {"creative", {"imaginative", "inventive", "innovative", "original", "artistic"}}
    };

    // Select a random synonym for the game
    auto iterator = synonymMap.begin();
    std::advance(iterator, rand() % synonymMap.size());
    std::string selectedWord = iterator->first;
    std::vector<std::string> selectedSynonyms = iterator->second;

    // Select a random synonym for the game
    std::string correctSynonym = selectedSynonyms[rand() % selectedSynonyms.size()];

    // Now use 'selectedWord' and 'correctSynonym' in your game logic
    std::cout << "Guess the synonym of the word: " << selectedWord << std::endl;

    int attempts = 0;
    std::string guess;
    while (attempts < maxAttempts) {
        std::cout << "Attempt " << attempts + 1 << ": ";
        std::cin >> guess;

        if (guess == correctSynonym) {
            std::cout << "Correct! The synonym is " << correctSynonym << "." << std::endl;
            score += (maxAttempts - attempts); // For example, 5 - number of attempts
            break;
        } else {
            std::cout << "Incorrect. Try again." << std::endl;
        }
        attempts++;

    }

    if (attempts == maxAttempts) {
        std::cout << "Out of attempts. The synonym was: " << correctSynonym << std::endl;
    }
    setScore(score);

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


