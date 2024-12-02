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
    if(x == mainFoodRef->getFoodPos().pos->x && y == mainFoodRef->getFoodPos().pos->y){
        playerPosList->insertHead(objPos(x,y,sym)); 
        mainFoodRef->generateFood(playerPosList);
    } else {
        playerPosList->insertHead(objPos(x,y,sym));
        playerPosList->removeTail();
    }


}

// More methods to be added