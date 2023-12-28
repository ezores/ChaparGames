//
// Created by CycleWSWin on 12/28/2023.
//

// Player.cpp
#include "../../includes/Player/Player.h"

Player::Player(string username, std::string gameName) : username(username), gameName(gameName), score(0) {}

std::string Player::getUsername() const {
    return username;
}

std::string Player::getGameName() const {
    return gameName;
}

int Player::getScore() const {
    return score;
}

void Player::updateScore(int points) {
    score += points;
}

