#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h"

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

GameMechs *game = new GameMechs(50,30);



int main(void)
{

    Initialize();

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
    MacUILib_init();
    MacUILib_clearScreen();

}

void GetInput(void)
{
    if (MacUILib_hasChar) {
        game->setInput(MacUILib_getChar());
    }

    //Debug Code:
    cout << "input is: " << game->getInput() << endl;
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
}

void DrawScreen(void)
{
    MacUILib_clearScreen();    
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
        cout <<"Custom Lose Message"<< endl;
        cout <<"Score: " << game->getScore() << endl;
    }

    MacUILib_uninit();
}
