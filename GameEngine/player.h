#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED



/*TypeDefs & Structs */
typedef enum
{
    false, true;

}bool;

typedef struct{

    float speed;
    float weight;
    mvector position;

    bool isOnMap;
    bool canWallJump;
    bool isMoving;

}char_strct;

/*---------------*/


/*Method Archetypes*/
void initPlayer();
void movePlayer();
void exitPlayer();
/*----------------*/
#endif // PLAYER_H_INCLUDED
