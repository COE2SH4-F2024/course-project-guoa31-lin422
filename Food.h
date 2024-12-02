#ifndef FOOD_H
#define FOOD_H

#include <cstdlib>
#include <time.h>
#include <objPos.h>
#include <GameMechs.h>


class Food
{
    private:
        objPos foodPos;
        GameMechs* GMRef;

    
    public:
        void generateFood(objPosArrayList* blockOff);
        objPos getFoodPos() const;
        ~Food();
        Food(GameMechs* thisGMRef);
};

#endif
