#include "Food.h"

Food::Food(GameMechs* thisGMRef)
{   
    foodPos = new objPosArrayList;
    for(int i = 0; i < FOOD_CAP; i++){
        foodPos->insertHead(objPos(-50,-50,36)); 
    }
    GMRef = thisGMRef;
}

void Food::generateFood(objPosArrayList* blockOff)
{
    //Randomize
    for(int i = 0; i <FOOD_CAP; i++){foodPos->removeTail();}
    
    bool meetsCriteria;
    int attempts = 0;
    int specialAmt = rand()%2 + 1;
    for(int i = 0; i < FOOD_CAP; i++)
    {
        do {       
            meetsCriteria = true;
            int randomX = rand()%(GMRef->getBoardSizeX() - 2) + 1;
            int randomY = rand()%(GMRef->getBoardSizeY() - 2) + 1;

            // Bad Case 1 (Same position as character)
            for(int k = 0; k < blockOff->getSize(); k++)
                if(randomX == blockOff->getElement(k).pos->x && randomY ==  blockOff->getElement(k).pos->y)
                {
                    meetsCriteria = false;
                    break;
                }
            for(int j = 0; j < foodPos->getSize(); j++) 
            {
                if (randomX == foodPos->getElement(j).pos->x && randomY == foodPos->getElement(j).pos->y)
                {
                    meetsCriteria = false;
                    break;
                }
            }

            if(meetsCriteria)
            {
                if(specialAmt == 1 || specialAmt == 2)
                {
                    foodPos->insertTail(objPos(randomX,randomY, char(157)));
                    specialAmt -= 1;
                } else {
                    foodPos->insertTail(objPos(randomX,randomY, 36));
                }
            }
            attempts++;

            if(attempts > 1000) { //assume board is full, game is over
                GMRef->setExitTrue();
                GMRef->setLoseFlag();
                break;
            }


        } while (!meetsCriteria);
    }
    //Set random food element to be special
}

objPosArrayList* Food::getFoodPos() const
{
    return foodPos;
}


Food::~Food() {
    delete foodPos;
}