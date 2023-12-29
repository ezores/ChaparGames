//
// Created by CycleWSWin on 12/28/2023.
//

// Player.cpp
#include "../../includes/Player/Player.h"

//Player::Player(std::string username, std::string gameName) : username(username), gameName(gameName), score(0) {}
Player::Player(string username, std::string gameName,int score) : username(username), gameName(gameName), score(score) {}

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

std::vector<Player> Player::readFromTSV(const std::string& filename) {
    std::vector<Player> players;
    std::ifstream file(filename);
    std::string line;

    while (std::getline(file, line)) {

        if (line.empty()) {
            continue;
        }

        std::istringstream iss(line);
        std::string username, gameName, scoreStr;
        std::getline(iss, username, '\t');
        std::getline(iss, gameName, '\t');
        std::getline(iss, scoreStr, '\t');

        try {
            int scoreInt = std::stoi(scoreStr);
            players.emplace_back(username, gameName, scoreInt);
        } catch (const std::invalid_argument& e) {
            std::cerr << "Invalid score format: " << scoreStr << std::endl;
            // Handle the error or continue
        }
    }
    return players;
}

void Player::writeToTSV(const vector<Player> &players, const string &filename) {
    std::ofstream file(filename);
    for (const auto& player : players) {
        file << player.getUsername() << '\t'
        << player.getGameName() << '\t'
        << player.getScore() << '\n';
    }
}



