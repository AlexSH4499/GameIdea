#include <stdio.h>

#include "controls.h"

int listener()
{
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
