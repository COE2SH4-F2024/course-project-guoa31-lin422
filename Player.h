#ifndef PLAYER_H
#define PLAYER_H

#include "Food.h"
#include "GameMechs.h"
#include "objPos.h"
#include "objPosArrayList.h"

class Player
{

    public:
        enum Dir {UP, DOWN, LEFT, RIGHT, STOP};  // This is the direction state

        Player(GameMechs* thisGMRef, Food* thisFdRef); // Constructor
        ~Player(); // Destructor

        objPosArrayList* getPlayerPos() const; // List holding positions of the whole snake player
        void updatePlayerDir(); // Changes movement direction based on input
        void movePlayer(); // Moves player and all includes logic behind eating, border wrapping and self collision

    private:
        // Arraylist holding all player positions
        objPosArrayList* playerPosList;

        // Enumeration of movement directions
        enum Dir myDir;

        // References to classes
        GameMechs* mainGameMechsRef; 
        Food* mainFoodRef;
};

#endif