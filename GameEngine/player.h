#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

/*Method Archetypes*/
void initPlayer();
void movePlayer();
void exitPlayer();
/*----------------*/

/*TypeDefs & Structs */
typedef enum
{
    false, true;
}bool;

typedef struct{

    float speed;
    float weight;
    float position;

    bool canWallJump;
    bool isMoving;

}char_strct;
/*---------------*/

#endif // PLAYER_H_INCLUDED
