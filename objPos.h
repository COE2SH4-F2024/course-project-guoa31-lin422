#ifndef OBJPOS_H
#define OBJPOS_H

// Struct holding coordinates
typedef struct
{
    int x;
    int y;
} Pos;

class objPos
{
    public:
        Pos* pos; // Pointer to pos structure which holds x,y
        char symbol; // Symbol of object

        objPos(); // Constructor
        objPos(int xPos, int yPos, char sym); // Parametized constructor

        ~objPos(); // Destructor
        objPos(const objPos& obj); // Copy constructor
        objPos& operator=(const objPos& obj); // Copy assignment operator
        
        // Sets the coordinates and symbol of objPos based on the parameters
        void setObjPos(objPos o);        
        void setObjPos(int xPos, int yPos, char sym);  

        // Getters of the objPos
        objPos getObjPos() const;
        char getSymbol() const;

        // Gets the symbol if the position matches the given objPos.
        char getSymbolIfPosEqual(const objPos* refPos) const;

        // Checks if the position of this object matches the position of another.
        bool isPosEqual(const objPos* refPos) const;
};

#endif