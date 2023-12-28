//
// Created by CycleWSWin on 12/28/2023.
//

#ifndef CHAPARABEOYUN_GUESSMOVIEGAME_H
#define CHAPARABEOYUN_GUESSMOVIEGAME_H

#include "Game.h"
#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

class GuessMovieGame : public Game {
public:
    GuessMovieGame(string playerName);

    // Override virtual methods
    void start() override;
    void end() override;
    void rules() const override;

private:
    vector<std::string> movies;
    string currentMovie;
    string maskedMovie;
    int maxAttempts;
};

#endif //CHAPARABEOYUN_GUESSMOVIEGAME_H
