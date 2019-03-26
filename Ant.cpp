//
// Created by Sandybridge W10 on 1/2/2019.
//

#include "Ant.h"

Ant::Ant() {

    boardColor = 0;
    xCoord = 0;
    yCoord = 0;
    antDirection = 0;

}

int Ant::getXCoord() {

    return xCoord;

}

int Ant::getYCoord() {
    return yCoord;

}

int Ant::getAntDirection() {
    return antDirection;
}

int Ant::getBoardColor() {
    return boardColor;
}

void Ant::setAntDirection(int direction) {
    antDirection = direction;
}

void Ant::setBoardColor(int color) {
    boardColor = color;
}

void Ant::setXCoord(int x) {
    xCoord = x;
}

void Ant::setYCoord(int y) {
    yCoord = y;
}

