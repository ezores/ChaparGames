//
// Created by CycleWSWin on 12/28/2023.
//

#ifndef CHAPARABEOYUN_SYNONYMGAME_H
#define CHAPARABEOYUN_SYNONYMGAME_H

#include "Game.h"
#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class SynonymGame : public Game {
public:
    SynonymGame(std::string playerName);

    // Override virtual methods
    void start() override;
    void end() override;
    void rules() const override;

private:
    std::vector<std::string> synonyms;
    std::string currentWord;
    int maxAttempts;
};

#endif //CHAPARABEOYUN_SYNONYMGAME_H
