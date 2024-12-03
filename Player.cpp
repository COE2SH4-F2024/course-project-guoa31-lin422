#include "Player.h"

Player::Player(GameMechs* thisGMRef, Food* thisFdRef)
{
    mainGameMechsRef = thisGMRef;
    mainFoodRef = thisFdRef;
    myDir = STOP;

    // more actions to be included
    playerPosList = new objPosArrayList();
    int x = mainGameMechsRef->getBoardSizeX()/2;
    int y = mainGameMechsRef->getBoardSizeY()/2;
    playerPosList->insertHead(objPos(x,y,char(254)));
}


Player::~Player()
{
    // delete any heap members here
    delete playerPosList;
}

objPosArrayList* Player::getPlayerPos() const
{
        // return the reference to the playerPos arrray list
        return playerPosList;
}

void Player::updatePlayerDir()
{
    char input = mainGameMechsRef->getInput();
            switch (input) {
            case 'w':
                if (myDir == LEFT || myDir == RIGHT || myDir == STOP)
                    myDir = UP;
                break;
                
            case 'a':
                if (myDir == UP || myDir == DOWN || myDir == STOP)
                    myDir = LEFT;
                break;

            case 's':
                if (myDir == LEFT || myDir == RIGHT || myDir == STOP)
                    myDir = DOWN;
                break;
            
            case 'd':
                if (myDir == UP || myDir == DOWN || myDir == STOP)
                    myDir = RIGHT;
                break;

            default:
                break;
        }
    }


void Player::movePlayer()
{
    int x = playerPosList->getHeadElement().getObjPos().pos->x;
    int y = playerPosList->getHeadElement().getObjPos().pos->y;
    int boardX = mainGameMechsRef->getBoardSizeX();
    int boardY = mainGameMechsRef->getBoardSizeY();
    char sym = 254;
    bool hasFood = false;
    
    objPosArrayList* foodList = mainFoodRef->getFoodPos();
    switch (myDir) {
        case UP:
            y -= 1;
            break;
        case DOWN:
            y += 1;
            break;
        case LEFT:
            x -= 1;
            break;
        case RIGHT:
            x += 1;
            break;
        default:
            break;
    }

    if (x > boardX-2) {
        x = 1;
    }
    else if (x < 1) {
        x = boardX - 2;
    }
    
    if (y < 1) {
        y = boardY-2;
    }
    else if (y > boardY-2) {    
        y = 1;
    }   

    for(int i = 0; i < FOOD_CAP; i++)
    {   
        int xFood = foodList->getElement(i).pos->x;
        int yFood = foodList->getElement(i).pos->y;
        char foodSym = foodList->getElement(i).symbol;

        if(x == xFood && y == yFood && foodSym == 36)
        {
            mainFoodRef->generateFood(playerPosList);
            mainGameMechsRef->incrementScore(1);
            hasFood = true;
            break;
        } else if (x == xFood && y == yFood && foodSym == char(157))
        {
            mainFoodRef->generateFood(playerPosList);
            mainGameMechsRef->incrementScore(10);
            hasFood = true;
            break;
        }
    }

    playerPosList->insertHead(objPos(x,y,sym));

    if(!hasFood){
        playerPosList->removeTail();
    } 


    for (int i=1; i<playerPosList->getSize(); i++) {
        if (x==playerPosList->getElement(i).pos->x &&
            y==playerPosList->getElement(i).pos->y) {
            mainGameMechsRef->setLoseFlag();
            mainGameMechsRef->setExitTrue();
            return;
        }

    }
}


// More methods to be added

