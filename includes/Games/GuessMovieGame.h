//
// Created by CycleWSWin on 12/28/2023.
//

#ifndef CHAPARABEOYUN_GUESSMOVIEGAME_H
#define CHAPARABEOYUN_GUESSMOVIEGAME_H

#include "Game.h"
#include <vector>

class GuessMovieGame : public Game {
public:
    GuessMovieGame(std::string playerName);

    // Override virtual methods
    void start() override;
    void end() override;
    void rules() const override;

private:
    std::vector<std::string> movies;
    std::string currentMovie;
    std::string maskedMovie;
    int maxAttempts;
};

#endif //CHAPARABEOYUN_GUESSMOVIEGAME_H
