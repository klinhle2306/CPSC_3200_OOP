/*
 * Linh Le
 * Revision date: 4/14/2022
 * inFest.cpp: inFest class implementation
*/

//Class invariants
/* inFest(int x, int y, int z): constructor
 * inFest(const inFest &obj): copy constructor
 * inFest& operator=(const inFest &obj): overload assignment operator
 * inFest(inFest&& obj): move constructor
 * inFest& operator=(inFest&& obj): move assignment operator
 * ~inFest(): destructor
 * move(int squares): void
 * getMax(): int
 * getMin(): int
 * resetAll(): void
*/

//Implementation variable
/* inFest object contain a dynamically allocated array of sub-object gridFlea
 * inFest object manage the gridFlea's moves and values
 * inFest object also reset every gridFlea sub objects if half of gridFlea are inactive
 * The user have no control over the flea's position or movement
*/

#include "inFest.h"
#include "gridFlea.h"

inFest::inFest(int x, int y, int z) {
    arrSize = z;
    fleaArray = new gridFlea[arrSize];
    for (int i = 0; i < arrSize; i++) {
        fleaArray[i] = gridFlea(x + i, y + i, z + i);
    }
    max = min = fleaArray[0].value();
}

inFest::inFest(const inFest &obj) {
    copy(obj);
}

inFest& inFest::operator=(const inFest &obj) {
    if (this != &obj) {
        delete [] fleaArray;
        copy(obj);
    }
    return *this;
}

void inFest::copy(const inFest &obj) {
    min = obj.min;
    max = obj.max;
    arrSize = obj.arrSize;
    fleaArray = new gridFlea[arrSize];
    for (int i = 0; i < arrSize; i++) {
        fleaArray[i] = obj.fleaArray[i];
    }
}

inFest::inFest(inFest&& obj) {
    copy(obj);
    obj.min = 0;
    obj.max = 0;
    obj.arrSize = 0;
    obj.fleaArray = nullptr;
}

inFest& inFest::operator=(inFest&& obj) {
    delete[] fleaArray;
    min = obj.min;
    max = obj.max;
    arrSize = obj.arrSize;
    fleaArray = obj.fleaArray;

    obj.min = 0;
    obj.max = 0;
    obj.fleaArray = nullptr;
    obj.arrSize = 0;
    return *this;
}

inFest::~inFest() {
    delete [] fleaArray;
}

void inFest::move(int squares) {
    for (int  i = 0; i < arrSize; i++) {
        fleaArray[i].move(squares);
        checkResetAll();
    }
}

int inFest::minVal() {
    int currVal = 0;
    for (int i = 0; i < arrSize; i++) {
        currVal = fleaArray[i].value();
        if (currVal < min) {
            min = currVal;
        }
    }
    return min;
}

int inFest::maxVal() {
    int currVal = 0;
    for (int i = 0; i < arrSize; i++) {
        currVal = fleaArray[i].value();
        if (currVal > max) {
            max = currVal;
        }
    }
    return max;
}

int inFest::getMax() {
    return maxVal();
}

int inFest::getMin() {
    return minVal();
}

void inFest::checkResetAll() {
    int count = 0;

    for (int i = 0; i < arrSize; i++) {
        if (!fleaArray[i].isPermDeactivate()) {
            if (!fleaArray[i].isActive()) {
                count += 1;
            }
        }
    }

    if (count >= arrSize/2) {
        for (int i = 0; i < arrSize; i++) {
            fleaArray[i].reset();
        }
    }
}
