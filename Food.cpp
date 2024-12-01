#include <food.h>

Food::Food(GameMechs* thisGMRef)
{
    foodPos.setObjPos(500, 500, '*'); //default values, set outside board
    GMRef = thisGMRef;
}

void Food::generateFood(objPos blockOff)
{
    //Randomize
    
    bool meetsCriteria;
    do {       
        meetsCriteria = true;
        int randomX = rand()%(GMRef->getBoardSizeX() - 2) + 1;
        int randomY = rand()%(GMRef->getBoardSizeY() - 2) + 1;

        // Bad Case 1 (Same position as character)
        if(randomX == blockOff.getObjPos().pos->x && randomY ==  blockOff.getObjPos().pos->y)
        {
            meetsCriteria = false;
        }

        if(meetsCriteria)
        {
        foodPos.setObjPos(randomX,randomY,'*');
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