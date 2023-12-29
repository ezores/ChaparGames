#include <iostream>
#include <vector>
#include <memory> //std:unique_ptr

#include "../includes/Games/Game.h"
#include "../includes/Games/GuessMovieGame.h"
#include "../includes/Games/SynonymGame.h"
#include "../includes/Games/YourGame.h"
#include "../includes/Player/Player.h"

/**
 * Shows the main menu options of the game
 * @param
 * @return choice
 */
int displayMainMenu(int& choice){
    std::cout << "Welcome to the Game Center!" << std::endl;
    std::cout << "Please select a game to play:" << std::endl;
    std::cout << "1. Synonym Game" << std::endl;
    std::cout << "2. Guess the Movie Game" << std::endl;
    std::cout << "3. Your Game" << std::endl;
    std::cout << "4. Exit" << std::endl;
    std::cout << "Enter your choice: ";
    std::cin >> choice;
    return choice;
}

/**
 * Main function
 * @return
 * params:
 */
int main() {
    // Implement the main menu and game loop here
    // Create a vector of Game pointers to store the different game types
    // Create a vector of Player objects to store the players
    // Read the games.txt file to populate the vector of Game pointers
    // Read the players.txt file to populate the vector of Player objects
    // Use polymorphism to create instances of different game types
    // Allow the player to choose a game, view rules, set difficulty, and play
    // After each game, display the player's score and return to the main menu

    bool exitGame = false;
    int choice=0;
    std::string filename = "../DB/Players.tsv";

    //Read players from file
    std::vector<Player> players = Player::readFromTSV(filename);

    // Enter player name
    std::string playerName;
    std::cout << "Enter your name: ";
    std::cin >> playerName;

    // Create a vector of Game pointers to store the different game types
    std::vector<std::unique_ptr<Game>> games;
    games.push_back(std::make_unique<SynonymGame>(playerName));
    games.push_back(std::make_unique<GuessMovieGame>(playerName));
    games.push_back(std::make_unique<YourGame>(playerName));

    //Main game loop
    while(!exitGame) {

        displayMainMenu(choice);

        if(choice >= 1 && choice <= 3) {
            //Display rules
            games[choice - 1]->rules();

            //Start game
            games[choice - 1]->start();
            players.emplace_back(playerName, games[choice - 1]->getGameName(), games[choice - 1]->getScore());

            //Find player by name and update their score
            auto playerIt = std::find_if(players.begin(), players.end(),
                                         [&](const Player& p) { return p.getUsername() == playerName; });
            if (playerIt != players.end()) {
                playerIt->updateScore(games[choice - 1]->getScore());
                std::cout << "Game Over! " << playerIt->getUsername()
                          << "'s score: " << playerIt->getScore()
                          << std::endl;
            }
        } else if(choice == 4){
            exitGame = true;
        } else {
            std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }
    //Player::writeToTSV(players, "../DB/Players.tsv");
    //test players data
//    std::vector<Player> My_players;
//    My_players.emplace_back("Player1", "Synonym Game", 10);
//    My_players.emplace_back("Player2", "Guess Movie Game", 15);
//    My_players.emplace_back("Player3", "Your Game", 20);

    // Write updated players data back to the file
    Player::writeToTSV(players, filename);
    std::cout << "Thank you for playing!" << std::endl;
    return 0;
}


