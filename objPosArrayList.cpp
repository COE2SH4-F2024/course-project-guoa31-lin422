#include "objPosArrayList.h"

// Default constructor
objPosArrayList::objPosArrayList()
{
    arrayCapacity = ARRAY_MAX_CAP; 
    aList = new objPos[arrayCapacity];
    listSize = 0; // Initial list size of 0
}

// Destructor
objPosArrayList::~objPosArrayList()
{
    delete[] aList;
}

// Size getter
int objPosArrayList::getSize() const
{
    return listSize;
}

// Inserts objPos into end of arrayList (tail)
void objPosArrayList::insertTail(objPos thisPos)
{
    if (listSize<arrayCapacity) // Will not add if adding new object will exceed capacity
    {
        aList[listSize]=thisPos;
        listSize++;
    }
}

// Inserts objPos into front of arrayList (head)
void objPosArrayList::insertHead(objPos thisPos)
{
    if (listSize<arrayCapacity) // Will not add if adding new object will exceed capacity
    {
        for (int i=listSize; i>0; --i) // Shift all element 1 to the right, making space for head
        {
            aList[i]=aList[i-1];
        }
        aList[0]=thisPos;
        listSize++;
    }
}

// Removes objPos in front of arrayList (head)
void objPosArrayList::removeHead()
{
    if (listSize>0) // Doesn't remove if arraylist is going to become size 0
    {
        for (int i=0; i<listSize-1; ++i) // Shifts list 1 to the left, erasing head
        {
            aList[i]=aList[i+1];
        }
        listSize--;
    }
}

// Removes objPos at the end of arrayList (tail)
void objPosArrayList::removeTail()
{
    // Simply changes the listSize so index doesn't see the last element (removing tail)
    if (listSize>0)
    {
        listSize--;
    }
}

// Simple getter functions of head, tail and index
objPos objPosArrayList::getHeadElement() const
{
    return aList[0].getObjPos();
}

objPos objPosArrayList::getTailElement() const
{
    return aList[listSize-1].getObjPos();
}

objPos objPosArrayList::getElement(int index) const
{
    return aList[index].getObjPos();
}