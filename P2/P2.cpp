/*
 * Linh Le
 * Revision date: 4/14/2022
 * P2.cpp: drivers file
 *
 * Description: This driver file uses inFest class and gridFlea class to populate an array of gridFlea object
 *              Each inFest object contains a dynamically allocated array of gridFlea sub objects
 *              inFest object manage the gridFlea's moves and values
 *              inFest object also reset every gridFlea sub objects if half of gridFlea are inactive
 *              The user have no control over the flea's position or movement
 *              Each gridFlea object has a random size and a random (x,y) position to start
 *              Each gridFlea object will then be moved by a random number of squares
 *              X and Y will be alternating after each move
 *              After being moved, each gridFlea have changing states of active, energetic, or deactivated
 *              The flea will be revived or reset randomly
 *              These states depend on the number of moves that each gridFlea object has
 *              Each gridFlea's reward and value will also change based on their movements
 *              These states and values will be reported to the clients for each gridFlea object
 *
 * Statement of assumptions: The grid only contain positive values
 *                           The flea cannot move backwards or have a negative starting position
 *                           The user have no control over the flea's position or movement
*/

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "inFest.h"
using namespace std;

void getVal(inFest obj) {
    cout << "Max value: " << obj.getMax() << endl;
    cout << "Min value: " << obj.getMin() << endl;
}


int main() {
    srand (time(NULL));
    int xPos = rand() % 10 + 1;
    int yPos = rand() % 10 + 1;
    int size = rand() % 10 + 1;
    int squares = rand() % 10 + 1;

    cout << endl << "x position: " << xPos << endl;
    cout << "y position: " << yPos << endl;
    cout << "size: " << size << endl;
    cout << "squares: " << squares << endl << endl;
    
    inFest inFestObj(xPos, yPos, size);
    cout << "inFest Object 1 value: " << endl;
    getVal(inFestObj);
    cout << endl;

    inFestObj.move(squares);
    cout << "inFest Object 1 value after moving fleas: " << endl;
    getVal(inFestObj);
    
    cout << endl << endl;
    
    inFest inFestObj2(inFestObj);   // call copy constructor
    cout << "inFest Object 2 value: " << endl;
    getVal(inFestObj2);
    cout << endl;

    inFestObj2.move(squares);
    cout << "inFest Object 2 value after moving fleas: " << endl;
    getVal(inFestObj2);
  
    cout << endl << endl;
    
    inFest inFestObj3(0,0,0);
    inFestObj3 = inFestObj;      // call assignment operator

    cout << "inFest Object 3 value: " << endl;
    getVal(inFestObj3);
    cout << endl;

    inFestObj3.move(squares);
    cout << "inFest Object 3 value after moving fleas: " << endl;
    getVal(inFestObj3);
    cout << endl;

    //inFestObj.resetAll();
    //inFestObj2.resetAll();
    //inFestObj3.resetAll();
   
    inFestObj.~inFest();
    inFestObj2.~inFest();
    inFestObj3.~inFest();
}

