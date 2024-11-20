#include "GameMechs.h"
#include "MacUILib.h"

GameMechs::GameMechs()
{
    boardSizeX = 30;
    boardSizeY = 15;
}

GameMechs::GameMechs(int boardX, int boardY)
{
    if (boardX < 10) boardX = 30; //Sets board size to default size if values are unreasonably small
    if (boardY < 5) boardY = 15;

    boardSizeX = boardX;
    boardSizeY = boardY;
}

// do you need a destructor?
GameMechs::~GameMechs()
{
    
}

bool GameMechs::getExitFlagStatus() const
{
    return exitFlag;
}

bool GameMechs::getLoseFlagStatus() const
{
    return loseFlag;
}
    

char GameMechs::getInput() const
{
    if(MacUILib_hasChar()) {
        return MacUILib_hasChar();
    }
}

int GameMechs::getScore() const
{
    return score;
}

void GameMechs::incrementScore(int val)
{
    score += val;
}

int GameMechs::getBoardSizeX() const
{
    return boardSizeX;
}

int GameMechs::getBoardSizeY() const
{
    return boardSizeY;
}


void GameMechs::setExitTrue()
{

}

void GameMechs::setLoseFlag()
{
    
}

void GameMechs::setInput(char this_input)
{

}

void GameMechs::clearInput()
{

}

// More methods should be added here