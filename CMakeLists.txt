cmake_minimum_required(VERSION 3.27)
project(ChaparAbeOyun)

set(CMAKE_CXX_STANDARD 17)

add_executable(ChaparAbeOyun src/main.cpp
        includes/Games/Game.h
        includes/Games/GuessMovieGame.h
        includes/Games/YourGame.h
        includes/Games/SynonymGame.h
        includes/Player/Player.h
        src/Player/Player.cpp
        src/Games/YourGame.cpp
        src/Games/SynonymGame.cpp
        src/Games/Game.cpp
        src/Games/GuessMovieGame.cpp
)
