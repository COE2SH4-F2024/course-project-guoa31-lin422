#ifndef FOOD_H
#define FOOD_H

#define FOOD_CAP 5
#include <cstdlib>
#include <time.h>
#include <objPos.h>
#include <GameMechs.h>


class Food
{
    private:
        objPosArrayList* foodPos;
        GameMechs* GMRef;

    
    public:
        void generateFood(objPosArrayList* blockOff);
        objPosArrayList* getFoodPos() const;
        ~Food();
        Food(GameMechs* thisGMRef);
};

#endif
