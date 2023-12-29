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
    SynonymGame();

    SynonymGame(string playerName);

    // Override virtual methods
    void start() override;
    void end() override;
    void rules() const override;

private:
    vector<string> synonyms;
    string currentWord;
    int maxAttempts;
};

#endif //CHAPARABEOYUN_SYNONYMGAME_H
