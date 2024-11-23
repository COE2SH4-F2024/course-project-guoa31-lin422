#include "Player.h"

Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;

    // more actions to be included
    playerPos.pos->x = mainGameMechsRef->getBoardSizeX()/2;
    playerPos.pos->y = mainGameMechsRef->getBoardSizeY()/2;
    playerPos.symbol = '@';
}


Player::~Player()
{
    // delete any heap members here
}

objPos Player::getPlayerPos() const
{
        // return the reference to the playerPos arrray list
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

    switch (myDir) {
        case UP:
            playerPos.pos->y--;
            break;
        case DOWN:
            playerPos.pos->y++;
            break;
        case LEFT:
            playerPos.pos->x--;
            break;
        case RIGHT:
            playerPos.pos->x++;
            break;
        default:
            break;
    }

    if (playerPos.pos->x > mainGameMechsRef->getBoardSizeX()) {
        playerPos.pos->x = 1;
    }
    else if (playerPos.pos->x < 1) {
        playerPos.pos->x = mainGameMechsRef->getBoardSizeX();
    }
    else if (playerPos.pos->y < 1) {
        playerPos.pos->y = mainGameMechsRef->getBoardSizeY();
    }
    else if (playerPos.pos->y > mainGameMechsRef->getBoardSizeY()) {
        playerPos.pos->y = 1;
    }


}

// More methods to be added