#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h"
#include <iostream>

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

GameMechs *game = new GameMechs();



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
    MacUILib_init();
    MacUILib_clearScreen();

}

void GetInput(void)
{
    if (MacUILib_hasChar()) {
        char input = MacUILib_getChar();
        game->setInput(input);
    } else {
        game->clearInput();
    }
}


void RunLogic(void)
{
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

    game->clearInput();
}

void DrawScreen(void)
{
    MacUILib_clearScreen();    
    game->printBoard();
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
        MacUILib_printf("Score = %d", game->getScore());
    }

    MacUILib_uninit();
}
