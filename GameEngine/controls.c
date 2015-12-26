#include <stdio.h>

#include "controls.h"

int listener()
{
    //Why the hell am I using an int to store a char...
    //Im so stupid...
    int c;

    c = getchar();

    putchar(c);

    return c;
}

float interpreterForListener(int fromListener)
{
    int c = listener();
    //We still need to put the Char values
    //inside the quotes
    switch(c)
    {

    case "":
        return ;
        break;

    case "":
        return ;
        break ;

    case "":
        return ;
        break ;

    case "" :
        return ;
        break ;

    default:
        break;

    }
}
