//
// Created by CycleWSWin on 12/28/2023.
//

#include "../../includes/Games/Game.h"

Game::Game(std::string gameName, std::string playerName) : gameName(gameName), playerName(playerName), score(0) {}

Game::~Game() {}

std::string Game::getGameName() const {
    return gameName;
}

void Game::setGameName(std::string name) {
    gameName = name;
}

std::string Game::getPlayerName() const {
    return playerName;
}

void Game::setPlayerName(std::string name) {
    playerName = name;
}

int Game::getScore() const {
    return score;
}

void Game::setScore(int score) {
    this->score = score;
}