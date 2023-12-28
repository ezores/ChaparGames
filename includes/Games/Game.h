//
// Created by CycleWSWin on 12/28/2023.
//

#ifndef CHAPARABEOYUN_GAME_H
#define CHAPARABEOYUN_GAME_H

#include <string>

class Game {
public:
    Game(std::string gameName, std::string playerName);
    virtual ~Game();

    std::string getGameName() const;
    void setGameName(std::string name);
    std::string getPlayerName() const;
    void setPlayerName(std::string name);
    int getScore() const;
    void setScore(int score);

    virtual void start() = 0;
    virtual void end() = 0;
    virtual void rules() const = 0;

private:
    std::string gameName;
    std::string playerName;
    int score;
};

#endif //CHAPARABEOYUN_GAME_H
