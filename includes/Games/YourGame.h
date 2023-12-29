//
// Created by CycleWSWin on 12/28/2023.
//

#ifndef CHAPARABEOYUN_YOURGAME_H
#define CHAPARABEOYUN_YOURGAME_H

#include "Game.h"

class YourGame : public Game {
public:
    YourGame(basic_string<char> basicString);  // Yapıcı fonksiyonun bildirimi
    void start() override;
    void end() override;
    void rules() const override;

private:
    // Spesifik veri üyeleri ve fonksiyonlar
};

#endif //CHAPARABEOYUN_YOURGAME_H
