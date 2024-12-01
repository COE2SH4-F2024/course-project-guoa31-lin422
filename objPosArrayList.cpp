#include "objPosArrayList.h"

// Paste your Tested implementation here.
// Paste your Tested implementation here.
// Paste your Tested implementation here.
objPosArrayList::objPosArrayList()
{
    arrayCapacity = ARRAY_MAX_CAP; 
    aList = new objPos[arrayCapacity];
    listSize = 0;
}

objPosArrayList::~objPosArrayList()
{
    delete[] aList;
}

int objPosArrayList::getSize() const
{
    return listSize;
}

void objPosArrayList::insertTail(objPos thisPos)
{
    if (listSize<arrayCapacity)
    {
        aList[listSize]=thisPos;
        listSize++;
    }
}

void objPosArrayList::insertHead(objPos thisPos)
{
    if (listSize<arrayCapacity)
    {
        for (int i=listSize; i>0; --i)
        {
            aList[i]=aList[i-1];
        }
        aList[0]=thisPos;
        listSize++;
    }
}


void objPosArrayList::removeHead()
{
    if (listSize>0)
    {
        for (int i=0; i<listSize-1; ++i)
        {
            aList[i]=aList[i+1];
        }
        listSize--;
    }
}

void objPosArrayList::removeTail()
{
    if (listSize>0)
    {
        listSize--;
    }
}


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