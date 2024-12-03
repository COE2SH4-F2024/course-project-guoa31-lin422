#ifndef OBJPOS_ARRAYLIST_H
#define OBJPOS_ARRAYLIST_H

// Maximum capacity of arraylist
#define ARRAY_MAX_CAP 500

#include "objPos.h"

class objPosArrayList // Implements an arraylist which holds and allows manipulation of objPos
{
    private:
        objPos* aList; // Pointer to array of objPos's
        int listSize; // Current number of elements of arraylist
        int arrayCapacity; // Total capacity of arraylist

    public:
        objPosArrayList(); // Constructor, intializes with maximum capacity and listSize = 0
        ~objPosArrayList(); // Destructor, frees dynamically allocated memory

        int getSize() const; // Getter for size
        // Inserts objPos into head/tail of arraylist
        void insertHead(objPos thisPos);
        void insertTail(objPos thisPos);

        // Removes an objPos from head/tail of arraylist
        void removeHead();
        void removeTail();
        
        // Getters for various elements of arraylist
        objPos getHeadElement() const;
        objPos getTailElement() const;
        objPos getElement(int index) const;
};

#endif