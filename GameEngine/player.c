
#include "player.h"

char_strct character;

void initPlayer(char_strct* character)
{
    //Need to add the sprites and such
    character.speed = 0.0;
    //Read position from a file
    character.position = (0.0,0.0,0.0);
    character.isMoving = false;

}

void movePlayer(char_strct* character)
{
    //Also needs sprite
    character.isMoving = true;

    // we need to receive the value from the controls
    //if(keys.RIGHT)
    character.position = addVectors(character->position,(1.0,0.0,0.0));

}

void exitPlayer(char_strct* character)
{

    free(character);
}
