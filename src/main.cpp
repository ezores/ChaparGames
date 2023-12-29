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

    //Read players from file
    std::string filename = "../DB/Players.tsv";
    std::vector<Player> players = Player::readFromTSV(filename);

    // Create a vector of Game pointers to store the different game types
    std::vector<std::unique_ptr<Game>> games;
    games.push_back(std::make_unique<SynonymGame>(std::string("Player Name")));
    games.push_back(std::make_unique<GuessMovieGame>(std::string("Player Name")));
    games.push_back(std::make_unique<YourGame>(std::string("Player Name")));

    //Main game loop
    while(!exitGame) {

        displayMainMenu(choice);

        switch(choice) {
            case 1:
                games[0]->start();
                break;
            case 2:
                games[1]->start();
                break;
            case 3:
                games[2]->start();
                break;
            case 4:
                exitGame = true;
                break;
            default:
                std::cout <<"Invalid choice. Please try again." << std::endl;
        }
    }

    std::cout <<"Thank you for playing!" << std::endl;
    return 0;
}


