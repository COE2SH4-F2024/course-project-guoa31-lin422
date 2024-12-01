#ifndef FOOD_H
#define FOOD_H

#include <cstdlib>
#include <time.h>
#include <objPos.h>
#include <GameMechs.h>
#include <Player.h>


class Food
{
    private:
        objPos foodPos;
        GameMechs* GMRef;

    
    public:
        void generateFood(objPos blockOff);
        objPos getFoodPos() const;
        ~Food();
        Food(GameMechs* thisGMRef);
};

#endif
