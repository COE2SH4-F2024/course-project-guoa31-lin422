#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h"
#include <iostream>
#include "Player.h"
#include "Food.h"

using namespace std;

#define DELAY_CONST 75000

// Function prototypes
void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);

bool win = false; // Checks if snake has exceeded limit of arraylist, if so it is considered a "win"

// Global pointers for core classes that influence the game
GameMechs *game;
Player *player;
Food *food;



int main(void)
{
    Initialize();
    
    // Core game loop, which checks for exit and loss flags to know when to exit
    while(game->getExitFlagStatus() == false && game->getLoseFlagStatus() == false)  
    {
        GetInput();    
        RunLogic();
        DrawScreen(); 
        LoopDelay();   
    }

    CleanUp();

}


void Initialize(void)
{
    srand(time(NULL)); // Seed randomizer
    MacUILib_init();
    MacUILib_clearScreen();

    // Create game, food and player instances
    game = new GameMechs(); // Initialize with default constructor
    food = new Food(game); 
    player = new Player(game, food);

    // Generate inital locations of food
    food->generateFood(player->getPlayerPos());
}

void GetInput(void)
{
    if (MacUILib_hasChar()) { // Gets input from user and sets input of game class
        char input = MacUILib_getChar();
        game->setInput(input);
    } else {
        game->clearInput(); // Clear input if no key is pressed
    }
}


void RunLogic(void)
{
    player->updatePlayerDir(); // Updates player direction based on previous key entered
    player->movePlayer();  // Continuously moves player in the direction based on previous function call

    // Exit game command "Esc"
    if(game->getInput() == 27) 
    {
        game->setExitTrue();
    }

    //Debug Keys

    //Test increment | Key: p
    if(game->getInput() == 112) 
    {
        game->incrementScore(1);
    }

    //Test loseFlag | Key: l
    if(game->getInput() == 108) 
    {
        game->setLoseFlag();
    }

    //Test Food object | Key: o
    if(game->getInput() == 'o')
    {
        food->generateFood(player->getPlayerPos());
    }

    game->clearInput(); // Clears input after correct call is made

    // Checks for win condition, case where the snake size exceeds the max capacity of arraylist
    if(player->getPlayerPos()->getSize() > ARRAY_MAX_CAP) {
        game->setExitTrue();
        game->setLoseFlag();
        win = true;
    }
}

void DrawScreen(void)
{   
    bool hasPlayer = false, hasFood = false;
    // Preallocated variables for cleaner syntax
    objPosArrayList* playerList = player->getPlayerPos(); // Gets player position
    objPosArrayList* foodList = food->getFoodPos(); // Gets food position
    objPos playerPart;
    objPos foodPart;
    MacUILib_clearScreen();    

    for(int i = 0; i < game->getBoardSizeY(); i++)
    {
        for(int j = 0; j < game->getBoardSizeX(); j++) // Cycles through all spaces of board
        {
            hasFood = false;
            hasPlayer = false;
            
            // First check if location has the player object (first priority)
            for(int k = 0; k < playerList->getSize(); k++)
            {
                playerPart = playerList->getElement(k); // Gets kth snake character from arraylist
                // If current coordinate coincides with a character object, print the character symbol
                if(j == playerPart.pos->x && i == playerPart.pos->y)
                {
                    MacUILib_printf("%c", playerPart.symbol);
                    hasPlayer = true; // Tells the rest of the loop that something already has been printed, and to skip
                    break;
                }
            }

            if(!hasPlayer) // Skip if character is already printed
            {
                for(int k = 0; k < FOOD_CAP; k++) // Check for food character from arraylist (second priority)
                {
                    foodPart = foodList->getElement(k);
                    // If current coordinate matches with the given food object, print the food symbol
                    if (j == foodPart.pos->x && i == foodPart.pos->y )
                    {
                        MacUILib_printf("%c", foodPart.symbol);
                        hasFood = true; // Tells the rest of the loop that something already has been printed, and to skip
                    }
                }
            }

            if(!hasPlayer && !hasFood) // If neither food or snake is printed, print game board as normal
            {
                if (i == 0 || i == game->getBoardSizeY() - 1) // Print Y border
                {
                    MacUILib_printf("#");
                } 
                else if (j == 0 || j == game->getBoardSizeX() - 1) // Print X border
                {
                    MacUILib_printf("#");
                } 
                else 
                {
                    MacUILib_printf(" "); // Print game space
                }
            }
        }
        MacUILib_printf("\n");
    }
    // Debug/Gameplay help
    // Shows player position on XY plane
    MacUILib_printf("Player position: (%d,%d) \n",player->getPlayerPos()->getHeadElement().pos->x,player->getPlayerPos()->getHeadElement().pos->y);
    
    // Prints coordinates of all food position on XY plane
    MacUILib_printf("Food positions: ");
    for (int k = 0; k < FOOD_CAP; k++) 
    {
    objPos foodItem = foodList->getElement(k);
    MacUILib_printf("(%d,%d) ", foodItem.pos->x, foodItem.pos->y);
    }
    MacUILib_printf("\n");

    //Prints score of game from eating food
    MacUILib_printf("Score: %d\n", game->getScore());
}


void LoopDelay(void)
{
        MacUILib_Delay(DELAY_CONST); // 0.075s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();    
    if(game->getLoseFlagStatus() == true)  // If game is exited by losing (colliding with self) print custom message
    {
        MacUILib_printf("You Lost! \n"); // Losing normally
        if(win) { // If "lost" by winning print a different message
            MacUILib_printf("You win! (Exceeded Arraylist size)\n");
        }
        MacUILib_printf("Score = %d", game->getScore()); // Add score to the bottom
    } else {
        MacUILib_printf("Forced Exit!"); // Print message if forced exit due to escape character
    }

    MacUILib_uninit();
}
