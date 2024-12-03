#include "Player.h"

// Constructor for the snake
Player::Player(GameMechs* thisGMRef, Food* thisFdRef)
{
    // References to influence the game mechanics and food class
    mainGameMechsRef = thisGMRef;
    mainFoodRef = thisFdRef;
    myDir = STOP; // Default value so snake is stopped at game start

    // Initializes the snakes default position in the center
    playerPosList = new objPosArrayList();
    int x = mainGameMechsRef->getBoardSizeX()/2;
    int y = mainGameMechsRef->getBoardSizeY()/2;
    playerPosList->insertHead(objPos(x,y,char(254)));
}

// Destructor
Player::~Player()
{
    delete playerPosList;
}

// Returns the reference to the playerPos arrray list
objPosArrayList* Player::getPlayerPos() const
{
    return playerPosList;
}

/*
Updates players movement based on input
Makes sure that the snake cannot reverse movement like UP to DOWN
*/
void Player::updatePlayerDir()
{
    char input = mainGameMechsRef->getInput();

    // Logic to make sure reverse movement cannot be done
    switch (input) {
        case 'w':
            if (myDir == LEFT || myDir == RIGHT || myDir == STOP) // If going LEFT or RIGHT, moving UP is allowed
                myDir = UP;
            break;
        case 'a':
            if (myDir == UP || myDir == DOWN || myDir == STOP) // If going UP or DOWN, moving LEFT is allowed
                myDir = LEFT;                
                break;
        case 's':
            if (myDir == LEFT || myDir == RIGHT || myDir == STOP) // If going LEFT or RIGHT, moving DOWN is allowed
                myDir = DOWN;
            break;
        case 'd':
            if (myDir == UP || myDir == DOWN || myDir == STOP) // If going UP or DOWN, moving RIGHT is allowed 
                myDir = RIGHT;
           break;
        default:
            break;
        }
    }

/*
    Moves the player in the direction indicated by function updatePlayerDir()
    Allows border wrapping for the player
    Checks for self-collision, creating a lose condition
    Checks for food consumption and increments score based on normal or special food
*/
void Player::movePlayer()
{
    // Preallocated variables for cleaner syntax
    // Gets coordinates of head element
    int x = playerPosList->getHeadElement().getObjPos().pos->x;
    int y = playerPosList->getHeadElement().getObjPos().pos->y;

    // Gets dimension of the board
    int boardX = mainGameMechsRef->getBoardSizeX();
    int boardY = mainGameMechsRef->getBoardSizeY();

    // Defines the symbol of the character and initializes consumption of food to be false
    char sym = 254;
    bool hasFood = false;

    // Pointer to arraylist containing positions of food
    objPosArrayList* foodList = mainFoodRef->getFoodPos();

    // Determine the new position based on the direction
    switch (myDir) {
        case UP:    y -= 1; break;
        case DOWN:  y += 1; break;
        case LEFT:  x -= 1; break;
        case RIGHT: x += 1; break;
        default:    break;
    }

    // Border Wrapping logic
    if (x > boardX-2) x = 1;
    else if (x < 1)  x = boardX - 2;
    
    if (y < 1) y = boardY-2;
    else if (y > boardY-2) y = 1;
  
    // Checks for food consumption
    for(int i = 0; i < FOOD_CAP; i++) //Loops through each food position
    {   
        // Coordinates and symbol of the ith food element
        int xFood = foodList->getElement(i).pos->x;
        int yFood = foodList->getElement(i).pos->y;
        char foodSym = foodList->getElement(i).symbol;

        // Logic for normal food, char 36
        if(x == xFood && y == yFood && foodSym == 36)
        {
            mainFoodRef->generateFood(playerPosList); // Regenerate food locations
            mainGameMechsRef->incrementScore(1);
            hasFood = true; // Sets consuming food to true
            break;
        // Logic for special food, char 157, increases score by 10
        } else if (x == xFood && y == yFood && foodSym == char(157))
        {   
            mainFoodRef->generateFood(playerPosList); // Regenerate food locations
            mainGameMechsRef->incrementScore(10);
            hasFood = true; // Sets consuming food to true
            break;
        }
    }

    // Snake movement logic
    playerPosList->insertHead(objPos(x,y,sym)); // Inserts head at new location
    if(!hasFood) playerPosList->removeTail(); // If the snake has eaten food, don't remove tail, else remove tail as normal
    
    // Check self collision
    for (int i = 1 ; i < playerPosList->getSize(); i++) // Set i = 1 so that player doesn't have self-collision with itself
    {   
        // Checks if current head position has the same coordinates as other positions of body
        if (x == playerPosList->getElement(i).pos->x && y==playerPosList->getElement(i).pos->y) 
        {
            mainGameMechsRef->setLoseFlag(); // If so, set exit and lose flag to true (reference to gamemechs)
            mainGameMechsRef->setExitTrue();
            return;
        }
    }
}

