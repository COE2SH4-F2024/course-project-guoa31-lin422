#ifndef FOOD_H
#define FOOD_H

#define FOOD_CAP 5 // Amount of food objects shown on board

#include <cstdlib> // For random number gen
#include <time.h> // Seeding random number gen
#include <objPos.h> // Managing food object positions
#include <GameMechs.h> // Use to influence main game mechanics like ending game, etc


class Food
{
    private:
        objPosArrayList* foodPos; // Pointer to arraylist to hold multiple number of food objects
        GameMechs* GMRef; // Reference to game mechanics

    public:
        /*
         - Generates food objects on board
         - Accepts variable blockOff which tells function what locations are off-limits to generate food
        */
        void generateFood(objPosArrayList* blockOff);

        // Returns pointer to food list
        objPosArrayList* getFoodPos() const;

        // Destructor
        ~Food();

        // Constructor
        Food(GameMechs* thisGMRef);
};

#endif
