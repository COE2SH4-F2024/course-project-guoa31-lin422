#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h"
#include <iostream>
#include "Player.h"
#include "Food.h"

using namespace std;

#define DELAY_CONST 75000

// bool exitFlag;
// Advised to remove all global variables

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);

bool win = false;
char test;

GameMechs *game;
Player *player;
Food *food;



int main(void)
{

    Initialize();

    while(game->getExitFlagStatus() == false && game->getLoseFlagStatus() == false)  
    {
        // cout << "Checking for input..." << endl;
        GetInput();    
        // cout << "Running game logic..." << endl;
        RunLogic();
        // cout << "Drawing screen..." << endl;
        DrawScreen(); 
        LoopDelay();   
    }

    CleanUp();

}


void Initialize(void)
{
    srand(time(NULL)); //seed randomizer
    MacUILib_init();
    MacUILib_clearScreen();
    game = new GameMechs();
    food = new Food(game);
    player = new Player(game, food);
    food->generateFood(player->getPlayerPos());


}

void GetInput(void)
{
    if (MacUILib_hasChar()) {
        char input = MacUILib_getChar();
        game->setInput(input);
    } else {
        game->clearInput(); //remove to debug
    }
}


void RunLogic(void)
{

    //Player stuff
    player->updatePlayerDir();
    player->movePlayer(); 

    if(game->getInput() == 27) {
        game->setExitTrue();
    }

    //Debug Keys

    //Test increment | Key: p
    if(game->getInput() == 112) {
        game->incrementScore(1);
    }

    //Test loseFlag | Key: l
    if(game->getInput() == 108) {
        game->setLoseFlag();
    }

    //Test Food object | Key: o
    if(game->getInput() == 'o'){
        food->generateFood(player->getPlayerPos());
    }


    game->clearInput(); //remove to debug

    if(player->getPlayerPos()->getSize() > ARRAY_MAX_CAP) {
        game->setExitTrue();
        game->setLoseFlag();
        win = true;
    }
}

void DrawScreen(void)
{   
    bool hasPlayer = false, hasFood = false;
    objPosArrayList* playerList = player->getPlayerPos();
    objPos playerPart;
    objPosArrayList* foodPart = food->getFoodPos();

    MacUILib_clearScreen();    
    for(int i = 0; i < game->getBoardSizeY(); i++)
    {
        for(int j = 0; j < game->getBoardSizeX(); j++)
        {
            hasFood = false;
            hasPlayer = false;
            
            for(int k = 0; k < playerList->getSize(); k++) 
            {
                playerPart = playerList->getElement(k);
                if(j == playerPart.pos->x && i == playerPart.pos->y)
                {
                    MacUILib_printf("%c", playerPart.symbol);
                    hasPlayer = true;
                    break;
                }
            }

            if(!hasPlayer)
            {
                for(int k = 0; k < FOOD_CAP; k++)
                {
                    if (j == foodPart->getElement(k).pos->x && i == foodPart->getElement(k).pos->y )
                    {
                        MacUILib_printf("%c", foodPart->getElement(k).symbol);
                        hasFood = true;
                    }
                }
            }

            if(!hasPlayer && !hasFood)
            {
                if (i == 0 || i == game->getBoardSizeY() - 1)
                {
                    MacUILib_printf("#");
                } 
                else if (j == 0 || j == game->getBoardSizeX() - 1)
                {
                    MacUILib_printf("#");
                } 
                else 
                {
                    MacUILib_printf(" ");
                }
            }
        }
        MacUILib_printf("\n");
    }
    MacUILib_printf("Player position: (%d,%d) \n",player->getPlayerPos()->getHeadElement().pos->x,player->getPlayerPos()->getHeadElement().pos->y);
    MacUILib_printf("Food positions: ");
    for (int k = 0; k < FOOD_CAP; k++) 
    {
    objPos foodItem = foodPart->getElement(k);
    MacUILib_printf("(%d,%d) ", foodItem.pos->x, foodItem.pos->y);
    }
    MacUILib_printf("\n");
    MacUILib_printf("Score: %d\n", game->getScore());
}


void LoopDelay(void)
{
        MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();    
    if(game->getLoseFlagStatus() == true) 
    {
        MacUILib_printf("Custom Lose Message \n");
        if(win) {
            MacUILib_printf("You win! (Exceeded Arraylist size)\n");
        }
        MacUILib_printf("Score = %d", game->getScore());
    }

    MacUILib_uninit();
}
