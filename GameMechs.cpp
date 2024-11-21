#include "GameMechs.h"
#include "MacUILib.h"

GameMechs::GameMechs()
{
    boardSizeX = 30;
    boardSizeY = 15;
    exitFlag = false;
    loseFlag = false;
    score = 0;
    input = '\0';

    board = new char*[boardSizeY];

    for(int i = 0; i < boardSizeY; i++)
    {
        board[i] = new char[boardSizeX];
    }

    for(int i = 0; i < boardSizeY; i++) 
    {
        for(int j = 0; j < boardSizeX; j++)
        {
            if (i == 0 || i == boardSizeY - 1)
            {
                board[i][j] = '#';
            } else if (j == 0 || j == boardSizeX - 1)
            {
                board[i][j] = '#';
            } else 
            {
                board[i][j] = ' ';
            }
        }
    }

    
}

GameMechs::GameMechs(int boardX, int boardY)
{
    if (boardX < 10) boardX = 30; //Sets board size to default size if values are unreasonably small
    if (boardY < 5) boardY = 15;

    boardSizeX = boardX;
    boardSizeY = boardY;
    exitFlag = false;
    loseFlag = false;
    score = 0;
    input  = '\0';

    board = new char*[boardSizeY];

    for(int i = 0; i < boardSizeY; i++)
    {
        board[i] = new char[boardSizeX];
    }

    for(int i = 0; i < boardSizeY; i++) 
    {
        for(int j = 0; j < boardSizeX; j++)
        {
            if (i == 0 || i == boardSizeY - 1)
            {
                board[i][j] = '#';
            } else if (j == 0 || j == boardSizeX - 1)
            {
                board[i][j] = '#';
            } else 
            {
                board[i][j] = ' ';
            }
        }
    }
}

// do you need a destructor?
GameMechs::~GameMechs()
{
    for(int i = 0; i < boardSizeX; i++) 
    {
        delete[] board[i];
        board[i] = nullptr;
    }

    delete[] board;
    board = nullptr;
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
    return input;
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
    exitFlag = true;
}

void GameMechs::setLoseFlag()
{
    loseFlag = true;
}

void GameMechs::setInput(char this_input)
{
    input = this_input;
}

void GameMechs::clearInput()
{
    input = '\0';
}

// More methods should be added here


void GameMechs::printBoard()
{
    for(int i = 0; i < boardSizeY; i++)
    {
        for(int j = 0; j < boardSizeX; j++)
        {
            MacUILib_printf("%c", board[i][j]);
        }
        MacUILib_printf("\n");
    }
}