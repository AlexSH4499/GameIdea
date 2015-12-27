
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

void movePlayer(char_strct character, mvector* v)
{
    //Also needs sprite
    character.isMoving = true;

    // we need to receive the value from the controls
    //already added, we just receive the vector returned by the keyListener method
    character.position = addVectors(character->position,v);

}

void exitPlayer(char_strct* character)
{
    character.isMoving = false;
    free(character);
}
