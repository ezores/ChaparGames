//
// Created by CycleWSWin on 12/28/2023.
//

#include "../../includes/Games/GuessMovieGame.h"

GuessMovieGame::GuessMovieGame() : Game("Guess Movie Game", "Player Name"), maxAttempts(5) {
    movies = {"The Godfather", "Inception", "Titanic", "Forrest Gump", "Avatar"};
}

GuessMovieGame::GuessMovieGame(std::string playerName) : Game("Guess Movie Game", playerName), maxAttempts(5) {
    movies = {"The Godfather", "Inception", "Titanic", "Forrest Gump", "Avatar"};
}

void GuessMovieGame::start() {
    // Select a random movie for the game
    srand(static_cast<unsigned>(time(nullptr)));
    currentMovie = movies[rand() % movies.size()];

    // Mask the movie name
    maskedMovie = currentMovie;
    std::replace_if(maskedMovie.begin(), maskedMovie.end(), ::isalpha, '*');
    printf("TEST GUESMOVIEGAME\n");
    // Game logic
    // ...
}

void GuessMovieGame::end() {
    // Display final score
    std::cout << "Game Over! " << getPlayerName() << "'s score: " << getScore() << std::endl;
}

void GuessMovieGame::rules() const {
    // Display game rules
    std::cout << "Guess Movie Game Rules:" << std::endl;
    std::cout << "Try to guess the name of the hidden movie." << std::endl;
    std::cout << "You have a maximum of " << maxAttempts << " attempts." << std::endl;
}
