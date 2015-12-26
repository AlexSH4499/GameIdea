
#include "player.h"


void initPlayer()
{
    //Need to add the sprites and such
    character.speed = 0.0;
    character.position = 0.0;
    character.isMoving = false;

}

void movePlayer()
{
    //Also needs sprite
    character.isMoving = true;

    // we need to recieve the value from the controls
    character.position += 0.0;
}
