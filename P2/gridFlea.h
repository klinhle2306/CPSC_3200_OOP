/*
 * Linh Le
 * Revision date: 4/14/2022
 * gridFlea.h: gridFlea class design
*/

//Class invariants
/* gridFlea(int size, int x, int y): constructor
 * revive(): void
 * reset(): void
 * value(): int
*/

//Interface invariant
/* gridFlea(): default constructor
 * gridFlea(int size, int x, int y): constructor
 * revive(): re-activate flea
 * reset(): set flea back to initial starting point, reset all values and modes
 * value(): determine flea's reward and value
*/

#ifndef GRIDFLEA_H
#define GRIDFLEA_H

class gridFlea {
private:
  int xInitial;      //initial starting point on x-axis
  int yInitial;      //initial starting point on y-axis
  int xPosition;     //current x position
  int yPosition;     //current y position
  int numMove;
  int change;        //change indicates how far object has moved
  int gridSize;
  int gridBound;
  int reward;        //reward decrease by number of square moved
  bool xTurn;        //boolean determines flea's moving direction
  bool energeticMode;
  bool active;
  bool permDeactivate;
  
public:
  gridFlea(); // default constructor

  //PreCondition:  initializing gridFlea object with given size, x and y position
  //PostCondition: reward is double the size and reduced by number of squares moved
  //               if invalid size(negative or 0), set size to 10
  //               if x or y is negative, auto set x = y = 0
  gridFlea(int x, int y, int size);

  //PreCondition:  flea is inactived but not permenantly deactived
  //PostCondition: flea is activated and gridBound is double in size
  void revive();

  //PreCondition:  gridFlea is not permenantly deactivated
  //PostCondition: gridFlea is reset to its initial position
  //               reset starting direction to x direction
  //               reset all values back to 0
  //               re-activate gridFlea, turn on energetic mode
  void reset();

  //PreCondition:  gridFlea is active
  //PostCondition: increament numMove by 1 if flea is not energetic
  //               increase numMove by square number of move if flea is active and energetic
  //               x and y are alternating after each move
  //               if move exceed half of grid bound, deactivate flea
  //               if move out of bound, permenantly deactivate flea
  void move(int square);

  //PreCondition: none
  //PostCondition: return flea's value
  int value();
  
  bool isActive();
  bool isEnergeticMode();
  bool isPermDeactivate();
};

#endif //GRIDFLEA_H
