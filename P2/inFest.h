/*
 * Linh Le
 * Revision date: 4/14/2022
 * inFest.h: inFest class design
*/

//Class invariants
/* inFest(int x, int y, int z): constructor
 * inFest(const inFest &obj): copy constructor
 * inFest& operator=(const inFest &obj): overload assignment operator
 * inFest(inFest&& obj): move constructor
 * inFest& operator=(inFest&& obj): move assignment operator
 * ~inFest(): destructor
 *
 * move(int squares): void
 * getMax(): int
 * getMin(): int
 * resetAll(): void
*/

//Interface invariant
/* gridFlea(): default constructor
 * gridFlea(int size, int x, int y): constructor
 * inFest(const inFest &obj): copy constructor
 * inFest& operator=(const inFest &obj): overload assignment operator
 * inFest(inFest&& obj): move constructor
 * inFest& operator=(inFest&& obj): move assignment operator
 * ~inFest(): destructor
 *
 * move(int squares): move function triggers fridFlea's move function
 * getMax(): return the max value from the gridFlea array
 * getMin(): return the min value from the gridFlea array
 * resetAll(): manage and response appropriately to the gridFlea array when half of the flea are inactive
*/

#ifndef INFEST_H
#define INFEST_H
#include "gridFlea.h"

class inFest {
public:
  
  //precondition: none
  //postcondition: allocate dyanamic array that contains gridFlea objects
  inFest(int x, int y, int z);
  inFest(const inFest &obj);     
  inFest& operator=(const inFest &obj);
  inFest(inFest&& obj);
  inFest& operator=(inFest&& obj);
  ~inFest();

  //precondition: inFest move triggers gridFlea move
  //postcondition: move every sub object gridFlea in the gridFlea array
  void move(int squares);

  int getMax();
  int getMin();

  //precondition: half of the gridFlea sub object in the gridFlea array are inactive 
  //postcondition: reset every sub obj gridFlea
  void checkResetAll();
private:
  
  //precondition: none
  //postcondition: search for min value in gridFlea array
  int minVal();

  //precondition: none
  //postcondition: search for max valua in gridFlea array
  int maxVal();
  void copy(const inFest &obj);
  
  gridFlea *fleaArray;    //gridFLea array
  int arrSize;
  int min;
  int max;
};

#endif //INFEST_H
