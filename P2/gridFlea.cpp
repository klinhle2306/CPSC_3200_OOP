/*
 * Linh Le
 * Revision date: 4/14/2022
 * gridFlea.cpp: gridFlea class implementation
*/

//Class invariants
/* gridFlea(int size, int x, int y): constructor
 * revive(): void
 * reset(): void
 * value(): int
*/

//Implementation variable
/* The grid only contain positive values
 * The flea cannot move backwards or have a negative starting position
 * The user have no control over the flea's position or movement
*/

#include "gridFlea.h"

gridFlea::gridFlea() {}     //default constructor

gridFlea::gridFlea(int x, int y, int size) {
    if (size <= 0) {
        gridSize = gridBound = 10;
    } else {
        gridSize = gridBound = size;
    }

    if (x < 0 || y < 0) {
        x = y = 0;
    }

    xInitial = x;
    yInitial = y;
    xPosition = x;
    yPosition = y;
    reward = 2 * size;
    numMove = 0;
    change = 0;
    xTurn = true;
    energeticMode = true;
    active = true;
    permDeactivate = false;
}

void gridFlea::revive() {
    active = true;
    gridBound *= 2;
}

void gridFlea::reset() {
    xPosition = xInitial;
    yPosition = yInitial;
    numMove = 0;
    change = 0;
    reward = 0;
    xTurn = true;
    energeticMode = true;
    active = true;
    permDeactivate = false;
}

void gridFlea::move(int square) {
    if (!active) {
        return;
    }

    if (!energeticMode) {
        numMove++;
    } else {
        if (xTurn) {
            xPosition += square;
        } else {
            yPosition += square;
        }
        xTurn = !xTurn;
    }
    numMove += square;

    if (numMove >= gridBound / 2) {
        active = false;
    }
    energeticMode = false;
    if (xPosition > gridSize || yPosition > gridSize) {
        permDeactivate = true;
    }
}

int gridFlea::value() {
    change = (xPosition - xInitial) + (yPosition - yInitial);
    reward -= change;
    if (change > gridSize) {
        active = false;
    }
    return reward * gridSize * change;
}

bool gridFlea::isActive() {
    return active;
}

bool gridFlea::isEnergeticMode() {
    return energeticMode;
}

bool gridFlea::isPermDeactivate() {
    return permDeactivate;
}

