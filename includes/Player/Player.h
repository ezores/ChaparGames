//
// Created by CycleWSWin on 12/28/2023.
//

#ifndef CHAPARABEOYUN_PLAYER_H
#define CHAPARABEOYUN_PLAYER_H

#include <string>
#include <utility>
using namespace std;

class Player {
public:
    Player(std::string username, std::string gameName);
    std::string getUsername() const;
    std::string getGameName() const;
    int getScore() const;
    void updateScore(int points);

private:
    std::string username;
    std::string gameName;
    int score;
};

#endif //CHAPARABEOYUN_PLAYER_H
