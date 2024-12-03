#include "GameMechs.h"
#include "MacUILib.h"
/*
    Default Constructor
    If no parameters generates a gameboard of size 30x15, with default flag and score values
    Allocates memory for the board
*/
GameMechs::GameMechs()
{
    boardSizeX = 30;
    boardSizeY = 15;
    exitFlag = false;
    loseFlag = false;
    score = 0;
    input = '\0'; // Default arguments

    // Dynamically allocate memory for the game board
    board = new char*[boardSizeY];
    for(int i = 0; i < boardSizeY; i++)
    {
        board[i] = new char[boardSizeX];
    }
}


/*
    Parametized constructor, which gives custom size to board
    Everything else default, same as default constructor
*/
GameMechs::GameMechs(int boardX, int boardY)
{
    if (boardX < 10) boardX = 30; //Sets board size to default size if values are unreasonably small
    if (boardY < 5) boardY = 15;

    boardSizeX = boardX;
    boardSizeY = boardY;
    exitFlag = false;
    loseFlag = false;
    score = 0;
    input  = '\0'; // Default arguments

    // Dynamically allocate memory for the game board
    board = new char*[boardSizeY];
    for(int i = 0; i < boardSizeY; i++)
    {
        board[i] = new char[boardSizeX];
    }
}

// Destructor for allocated memory for board variable
GameMechs::~GameMechs()
{
    for(int i = 0; i < boardSizeY; i++)
    {
        delete[] board[i];
    }
    delete[] board;
}

// Self-explanatory --- Getters and setters for various variables
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
