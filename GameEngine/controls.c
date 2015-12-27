#include <stdio.h>

#include "controls.h"
#include "SDL.h"

SDL_Event e;
/*
int listener()
{
    //Why the hell am I using an int to store a char...
    //Im so stupid...
    int c;

    c = getchar();

    putchar(c);

    return c;
}
*/
mvector keyListener()
{

    //We still need to put the Char values
    //inside the quotes
    switch(e.key.keysym.sym)
    {

    case SDLK_UP:
        return mvector(0.0,-1.0,0.0);
        break;

    case SDLK_DOWN:
        return mvector(0.0,1.0,0.0);
        break ;

    case SDLK_LEFT:
        return mvector(-1.0,0.0,0.0);
        break ;

    case SDLK_RIGHT:
        return mvector(1.0,0.0,0.0);
        break ;

    default:
        break;

    }
}
