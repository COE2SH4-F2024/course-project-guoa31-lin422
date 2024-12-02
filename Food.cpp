#include <food.h>

Food::Food(GameMechs* thisGMRef)
{
    foodPos.setObjPos(500, 500, 36); //default values, set outside board
    GMRef = thisGMRef;
}

void Food::generateFood(objPosArrayList* blockOff)
{
    //Randomize
    
    bool meetsCriteria;
    do {       
        meetsCriteria = true;
        int randomX = rand()%(GMRef->getBoardSizeX() - 2) + 1;
        int randomY = rand()%(GMRef->getBoardSizeY() - 2) + 1;

        // Bad Case 1 (Same position as character)
        for(int i = 0; i < blockOff->getSize(); i++)
            if(randomX == blockOff->getElement(i).pos->x && randomY ==  blockOff->getElement(i).pos->y)
            {
                meetsCriteria = false;
                break;
            }

        if(meetsCriteria)
        {
        foodPos.setObjPos(randomX,randomY,36);
        }


    } while (!meetsCriteria);
}

objPos Food::getFoodPos() const
{
    return foodPos;
}

//No DMA
Food::~Food() {

}