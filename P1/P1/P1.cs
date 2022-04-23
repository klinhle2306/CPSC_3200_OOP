using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

/*
 * Linh Le
 * Revision date: 4/5/2022 
 * Driver file
 * Description: This driver file uses gridFlea class to populate an array of gridFlea object
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

namespace P1
{
    class P1
    {
        const int SIZE = 10;
        
        static void Main(string[] arg)
        {
            gridFlea[] fleaArray = new gridFlea[SIZE];
            populateFlea(fleaArray);
            moveFlea(fleaArray);
            modeReport(fleaArray);
            reviveOrResetFlea(fleaArray);
        }
        
        static void populateFlea(gridFlea[] array)
        {
            Random rnd = new Random();
            int randomSize, randomX, randomY;
            Console.WriteLine("Now starting to populate gridFlea objects: ");
            for (int i = 0; i < SIZE; i++)
            {
                randomSize = rnd.Next(0, 15);
                randomX = rnd.Next(0, 15);
                randomY = rnd.Next(0, 15);
                array[i] = new gridFlea(randomSize, randomX, randomY);
            }
        }

        static void moveFlea(gridFlea[] array)
        {
            Console.WriteLine("Now starting to move gridFlea objects: ");
            var rnd = new Random();
            int randomP;
            for (int i = 0; i < array.Length; i++)
            {
                randomP = rnd.Next(0, 10);
                array[i].move(randomP);
                Console.WriteLine("Object's X postion: " + array[i].getXPosition());
                Console.WriteLine("Object's Y postion: " + array[i].getYPosition());
                Console.WriteLine('\n');
            }
        }

        static void reviveOrResetFlea(gridFlea[] array)
        {
            Console.WriteLine("Now starting to revive or reset gridFlea objects: " + '\n');
            Random rnd = new Random();
            for (int i = 0; i < array.Length; i++)
            {
                int turn = rnd.Next(0, 2);
                if (!array[i].isPermDeactivate() && turn == 0)
                    array[i].revive();
                else if (!array[i].isPermDeactivate() && turn == 1)
                    array[i].reset();
            }
            modeReport(array);
            Console.WriteLine('\n');
        }

        static void modeReport(gridFlea[] array)
        {
            Console.WriteLine("Now starting to report gridFlea objects's statuses: ");
            for (int i = 0; i < array.Length; i++)
            {
                Console.Write("Object's current state:" + '\n');
                Console.WriteLine("Active: " + array[i].isActive());
                Console.WriteLine("Energetic: " + array[i].isEnergeticMode());
                Console.WriteLine("Permanentally Deactivated: " + array[i].isPermDeactivate());
                Console.WriteLine("Current Value: " + array[i].value());
                Console.WriteLine("Reward: " + array[i].getFleaReward());
                Console.WriteLine('\n');
            }
        }
    }
}
