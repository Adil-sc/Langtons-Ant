cmake_minimum_required(VERSION 3.12)
project(LangtonsAnt)

set(CMAKE_CXX_STANDARD 11)

add_executable(LangtonsAnt main.cpp Ant.cpp Ant.h printBoard.cpp printBoard.h moveAnt.cpp moveAnt.h Menu.h Menu.cpp inputValidation.cpp inputValidation.h)