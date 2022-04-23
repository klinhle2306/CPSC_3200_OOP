using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

/*
 * Linh Le
 * Revision date: 4/5/2022
 * gridFlea class design
*/

//Class invariants
/* gridFlea(int size, int x, int y): constructor
 * revive(): void
 * reset(): void
 * value(): int
*/

//Interface invariant
/* gridFlea(int size, int x, int y): constructor
 * revive(): re-activate flea
 * reset(): set flea back to initial starting point, reset all values and modes
 * value(): determine flea's reward and value
*/

namespace P1
{
    public class gridFlea
    {
        private int xInitial;      //initial starting point on x axis
        private int yInitial;      //initial starting point on y axis
        private int xPosition;     //current x position 
        private int yPosition;     //current y position
        private int numMove = 0;
        private int change = 0;    //change indicates how far object has moved
        private int gridSize;      
        private int gridBound;
        private int reward;        //reward decrease by number of square moved
        private bool xTurn = true; //boolen determines flea's moving dirention
        private bool energeticMode = true;
        private bool active = true;
        private bool permDeactivate = false;

        //PreCondition:  initializing gridFlea object with given size, x and y position
        //PostCondition: reward is double the size and reduced by number of squares moved
        //               if invalid size(negative or 0), set size to 10
        //               if x or y is negative, auto set x = y = 0
        public gridFlea(int size, int x, int y)
        {
            if (size <= 0) 
                gridSize = gridBound = 10;
            else
                gridSize = gridBound = size;

            if (x < 0 || y < 0) 
                x = y = 0;

            xInitial = x;
            yInitial = y;
            xPosition = x;
            yPosition = y;
            reward = 2 * size;
        }

        //PreCondition:  flea is inactived but not permenantly deactived
        //PostCondition: flea is activated and gridBound is double in size
        public void revive()
        {
            active = true;
            gridBound *= 2;
        }

        //PreCondition:  gridFlea is not permenantly deactivated
        //PostCondition: gridFlea is reset to its initial position
        //               reset starting direction to x direction
        //               reset all values back to 0
        //               re-activate gridFlea, turn on energetic mode
        public void reset()
        {
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

        //PreCondition:  gridFlea is active
        //PostCondition: increament numMove by 1 if flea is not energetic
        //               increase numMove by square number of move if flea is active and energetic
        //               x and y are alternating after each move
        //               if move exceed half of grid bound, deactivate flea
        //               if move out of bound, permenantly deactivate flea
        public void move(int square)
        {
            if (!active)
                return;

            if (!energeticMode)
                numMove++;
            else
                if (xTurn)
                    xPosition += square;
                else
                    yPosition += square;
                xTurn = !xTurn;
            numMove += square;

            if (numMove >= gridBound / 2) 
                active = false;
                energeticMode = false;
            if (xPosition > gridSize || yPosition > gridSize) 
                permDeactivate = true;
        }

        //PreCondition: none
        //PostCondition: return flea's value
        public int value()
        {
            change = (xPosition - xInitial) + (yPosition - yInitial);
            reward -= change;
            if (change > gridSize)
                active = false;
            return reward * gridSize * change;
        }

        //PreCondition: none
        //PostCondition: none
        public int getXPosition()
        {
            return xPosition;
        }

        //PreCondition: none
        //PostCondition: none 
        public int getYPosition()
        {
            return yPosition;
        }

        //PreCondition: none
        //PostCondition: none
        public int getFleaReward()
        {
            return reward;
        }

        //PreCondition: none
        //PostCondition: none
        public bool isActive()
        {
            return active;
        }

        //PreCondition: none
        //PostCondition: none
        public bool isEnergeticMode()
        {
            return energeticMode;
        }

        //PreCondition: none
        //PostCondition: none
        public bool isPermDeactivate()
        {
            return permDeactivate;
        }
    }
}

//Implementation variable
/* The grid only contain positive values
 * The flea cannot move backwards or have a negative starting position
 * The user have no control over the flea's position or movement
*/
