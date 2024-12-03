#include "objPos.h"

// Default constructor, sets (x,y) to (0,0), sets symbol to null and allocates memory for the position structure
objPos::objPos()
{
    pos = new Pos;
    pos->x = 0;
    pos->y = 0;
    symbol = 0; //NULL
}

// Parametized constructor, sets x,y and symbol to parameters, and allocates memory for the position structure
objPos::objPos(int xPos, int yPos, char sym)
{
    pos = new Pos;
    pos->x = xPos;
    pos->y = yPos;
    symbol = sym;
}

//Destructor
objPos::~objPos()
{
    delete pos;
    pos = nullptr;
}

// Copy, creates deep copy of objPos
objPos::objPos(const objPos& obj)
{
    pos = new Pos;
    pos->x = obj.pos->x;
    pos->y = obj.pos->y;
    symbol = obj.symbol;
}   

// Copy Assignment, assigns a deep copy to the given objPos object
objPos& objPos::operator= (const objPos& obj)
{
    if(this == &obj) return *this;
    delete pos;

    pos = new Pos;
    pos->x = obj.pos->x;
    pos->y = obj.pos->y;
    symbol = obj.symbol;

    return *this; // Returns a pointer to new objPos
}

// Sets the coordinates and symbol of the objPos to the one in the parameters
void objPos::setObjPos(objPos o)
{
    pos->x = o.pos->x;
    pos->y = o.pos->y;
    symbol = o.symbol;
}

// Sets the coordinates and symbol to the ones in the parameters
void objPos::setObjPos(int xPos, int yPos, char sym)
{
    pos->x = xPos;
    pos->y = yPos;
    symbol = sym;
}

// Returns a copy of the coordinates and symbol of the objPos
objPos objPos::getObjPos() const
{
    objPos returnPos;
    returnPos.pos->x = pos->x;
    returnPos.pos->y = pos->y;
    returnPos.symbol = symbol;
    
    return returnPos;
}

// Getter for symbol
char objPos::getSymbol() const
{
    return symbol;
}

// Checks if this position matches the given position.
bool objPos::isPosEqual(const objPos* refPos) const
{
    return (refPos->pos->x == pos->x && refPos->pos->y == pos->y);
}


// Gets the symbol if the position matches the given position.
char objPos::getSymbolIfPosEqual(const objPos* refPos) const
{
    if(isPosEqual(refPos))
        return symbol;
    else
        return 0;
}
