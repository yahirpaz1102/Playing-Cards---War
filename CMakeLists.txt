cmake_minimum_required(VERSION 3.30)
project(PlayingCardClass)

set(CMAKE_CXX_STANDARD 20)

add_executable(PlayingCardClass
        cmake-build-debug/card.h
        cmake-build-debug/card.cpp
        cmake-build-debug/main.cpp
        cmake-build-debug/deck.h
        cmake-build-debug/deck.cpp
        cmake-build-debug/war.h
        cmake-build-debug/war.cpp
)
