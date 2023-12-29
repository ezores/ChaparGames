//
// Created by CycleWSWin on 12/28/2023.
//

#ifndef CHAPARABEOYUN_PLAYER_H
#define CHAPARABEOYUN_PLAYER_H

#include <string>
#include <utility>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

class Player {
public:
    Player(std::string username, std::string gameName, int score = 0);
    std::string getUsername() const;
    std::string getGameName() const;
    int getScore() const;
    void updateScore(int points);

    static std::vector<Player> readFromTSV(const std::string& filename);
    static void writeToTSV(const std::vector<Player>& players, const std::string& filename);

private:
    std::string username;
    std::string gameName;
    int score;
};

#endif //CHAPARABEOYUN_PLAYER_H
