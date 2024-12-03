#ifndef GAMEMECHS_H
#define GAMEMECHS_H

#include <cstdlib>
#include <time.h>

#include "objPos.h" // Managing object positions
#include "objPosArrayList.h" // List holding object positions

using namespace std;

class GameMechs // Core game mechanics
{
    private:
        char input;
        bool exitFlag;
        bool loseFlag;
        int score;

        int boardSizeX;
        int boardSizeY;

        char **board; // New variable holds game board;

    public:
        GameMechs(); //Default constructor, initializes game with default values
        GameMechs(int boardX, int boardY); // Parametized constructor, default values with custom board game size
        ~GameMechs(); // Destructor, deallocates memory used when creating board
        
        // Getters and Setters for flags
        bool getExitFlagStatus() const; 
        void setExitTrue();
        bool getLoseFlagStatus() const;
        void setLoseFlag();

        // Getters, Setters and clear for input
        char getInput() const;
        void setInput(char this_input);
        void clearInput();

        // Getters and Setters for game board
        int getBoardSizeX() const;
        int getBoardSizeY() const;
        
        // Getter and incrementor for score
        int getScore() const;
        void incrementScore(int val);
        
};

#endif