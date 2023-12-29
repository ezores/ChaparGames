//
// Created by CycleWSWin on 12/28/2023.
//

#ifndef CHAPARABEOYUN_GAME_H
#define CHAPARABEOYUN_GAME_H

#include <string>
using namespace std;
class Game {
public:
    Game(string gameName, string playerName);
    virtual ~Game();

    string getGameName() const;
    void setGameName(std::string name);
    string getPlayerName() const;
    void setPlayerName(std::string name);
    int getScore() const;
    void setScore(int score);

    virtual void start() = 0;
    virtual void end() = 0;
    virtual void rules() const = 0;

private:
    string gameName;
    string playerName;
protected:
    int score;
};

#endif //CHAPARABEOYUN_GAME_H
