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

<<<<<<< HEAD
void objPosArrayList::insertTail(objPos thisPos)
{
    if (listSize<arrayCapacity)
    {
        aList[listSize]=thisPos;
        listSize++;
    }
=======
void objPosArrayList::insertHead(objPos thisPos)
{
    listSize++;
    for(int i = listSize; i > 0; i--)
    {
        aList[i] = aList[i-1];
    }
    aList[0] = thisPos;
    
}

void objPosArrayList::insertTail(objPos thisPos)
{
    aList[listSize++] = thisPos;
>>>>>>> 7be1688a45e0e4c5f550dbdfc1029510efa4b751
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
<<<<<<< HEAD
{
    if (listSize>0)
    {
        for (int i=0; i<listSize-1; ++i)
        {
            aList[i]=aList[i+1];
        }
        listSize--;
    }
=======
{  
    if(listSize > 0)
    {
        for(int i = 0; i < listSize-1; i++)
        {
            aList[i] = aList[i+1];
        }
    }
    listSize--;
>>>>>>> 7be1688a45e0e4c5f550dbdfc1029510efa4b751
}

void objPosArrayList::removeTail()
{
<<<<<<< HEAD
    if (listSize>0)
    {
        listSize--;
    }
=======
    if(listSize > 0) listSize--;
>>>>>>> 7be1688a45e0e4c5f550dbdfc1029510efa4b751
}


objPos objPosArrayList::getHeadElement() const
{
<<<<<<< HEAD
    return aList[0].getObjPos();
=======
    return aList[0];
>>>>>>> 7be1688a45e0e4c5f550dbdfc1029510efa4b751
}

objPos objPosArrayList::getTailElement() const
{
<<<<<<< HEAD
    return aList[listSize-1].getObjPos();
=======
    return aList[listSize-1];
>>>>>>> 7be1688a45e0e4c5f550dbdfc1029510efa4b751
}

objPos objPosArrayList::getElement(int index) const
{
<<<<<<< HEAD
    return aList[index].getObjPos();
=======
    return aList[index];
>>>>>>> 7be1688a45e0e4c5f550dbdfc1029510efa4b751
}