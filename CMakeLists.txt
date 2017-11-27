cmake_minimum_required(VERSION 3.8)
project(ex2)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        Board.cpp
        Board.h
        Game.cpp
        Game.h
        GameLogic.cpp
        GameLogic.h
        HumanPlayer.cpp
        HumanPlayer.h
        InPutTest.cpp
        InPutTest.h
        main.cpp
        Player.cpp
        Player.h
        Point.cpp
        Point.h
        RegularLogic.cpp
        RegularLogic.h)

add_executable(ex2 ${SOURCE_FILES})