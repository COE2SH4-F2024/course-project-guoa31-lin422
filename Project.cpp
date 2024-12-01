#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h"
#include <iostream>
#include "Player.h"
#include "Food.h"

using namespace std;

#define DELAY_CONST 100000

// bool exitFlag;
// Advised to remove all global variables

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);

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
    player = new Player(game);
    food = new Food(game);
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
}

void DrawScreen(void)
{   
    MacUILib_clearScreen();    
    for(int i = 0; i < game->getBoardSizeY(); i++)
    {
        for(int j = 0; j < game->getBoardSizeX(); j++)
        {
            if(j ==  player->getPlayerPos().pos->x && i == player->getPlayerPos().pos->y)
            {
                MacUILib_printf("%c", player->getPlayerPos().symbol);
            } else if (j == food->getFoodPos().pos->x && i == food->getFoodPos().pos->y)
            {
                MacUILib_printf("%c", food->getFoodPos().symbol);
            }
              else if (i == 0 || i == game->getBoardSizeY() - 1)
            {
                MacUILib_printf("#");
            } else if (j == 0 || j == game->getBoardSizeX() - 1)
            {
                MacUILib_printf("#");
            } else 
            {
                MacUILib_printf(" ");
            }
        }
        MacUILib_printf("\n");
    }
    MacUILib_printf("Last key pressed: %c\n", game->getInput());
    MacUILib_printf("Player position: (%d,%d) \n",player->getPlayerPos().pos->x,player->getPlayerPos().pos->y);
    MacUILib_printf("Food position: (%d,%d)\n", food->getFoodPos().pos->x,food->getFoodPos().pos->y);
}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();    
    delete food;
    if(game->getLoseFlagStatus() == true) 
    {
        MacUILib_printf("Custom Lose Message \n");
        MacUILib_printf("Score = %d", game->getScore());
    }

    MacUILib_uninit();
}
