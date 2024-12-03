#include "Food.h"

Food::Food(GameMechs* thisGMRef) //Constructor
{   
    foodPos = new objPosArrayList; //Allocated memory for food bucket list
    for(int i = 0; i < FOOD_CAP; i++)
    {
        foodPos->insertHead(objPos(-50,-50,36));  //Initializes food with amount FOOD_CAP, outside of gameboard
    }

    GMRef = thisGMRef; //reference to Game
}

void Food::generateFood(objPosArrayList* blockOff) // Generates new food position without 
                                                   // Putting any on top of snake or previous food objects
{
    for(int i = 0; i <FOOD_CAP; i++){foodPos->removeTail();} //Removes all food objects
    
    bool meetsCriteria; // Checks if food generated is valid
    int attempts = 0;
    int specialAmt = rand()%2 + 1; // Amount of special food created (1 or 2)

    for(int i = 0; i < FOOD_CAP; i++)
    {
        do {       
            meetsCriteria = true;
            int randomX = rand()%(GMRef->getBoardSizeX() - 2) + 1; // Generates random coords inside the game board
            int randomY = rand()%(GMRef->getBoardSizeY() - 2) + 1;

            // Bad Case 1 (Same position as character)
            for(int k = 0; k < blockOff->getSize(); k++)
            {
                if(randomX == blockOff->getElement(k).pos->x && randomY ==  blockOff->getElement(k).pos->y)
                {
                    meetsCriteria = false;
                    break;
                }
            }

            //Bad Case 2 (Same position as previous food objects)    
            for(int j = 0; j < foodPos->getSize(); j++) 
            {
                if (randomX == foodPos->getElement(j).pos->x && randomY == foodPos->getElement(j).pos->y)
                {
                    meetsCriteria = false;
                    break;
                }
            }
            
            // If food is valid, add to list of food objects
            if(meetsCriteria)
            {
                if(specialAmt == 1 || specialAmt == 2) // Adds the special food
                {
                    foodPos->insertTail(objPos(randomX,randomY, char(157)));
                    specialAmt -= 1;
                } else { // Adds the normal food
                    foodPos->insertTail(objPos(randomX,randomY, 36));
                }
            }

            attempts++;
            if(attempts > 1000) { // If too many attempts to generate food, assume board is full and game is over
                GMRef->setExitTrue();
                GMRef->setLoseFlag();
                break;
            }


        } while (!meetsCriteria); // Compute positions until valid is found
    }
}

objPosArrayList* Food::getFoodPos() const // Returns pointer to objPosArrayList
{
    return foodPos;
}


Food::~Food() //Destructor
{
    delete foodPos;
}