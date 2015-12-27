#include <stdio.h>
#include <stdlib.h>

#include "SDL.h"

#include "main.h"
#include "map.h"
#include "controls.h"
#include "camera.h"

void Initialize();
void render();
void update();
void cleanUp();

/*----Global Vars-----*/
cam_strct cam  = NULL;
char_strct character = NULL;
/*--------------------*/


void loadImage(SDL_Surface* surf, char* file)
{
    surf = SDL_LoadBMP(file);
}

void Initialize()
{
        SDL_Init(SDL_INIT_EVERYTHING);
        SDL_SetVideoMode(1920,1080,32,SDL_HWSURFACE|SDL_DOUBLEBUF);

        initAAR();
        iniMapGrid();
        initPlayer(character);
        cameraInit(cam);
        keyListener();

}

void cleanUp()
{
    //Free Graphical Interface
    SDL_FreeSurface(surf);
    SDL_Quit();
    freeGrid();
    exitPlayer(character);

}

void update(SDL_Surface* surf, SDL_Surface* dest,int x, int y)
{
    SDL_Rect destR;
    destR.x = x;
    destR.y = y;

    updateAAR();
    SDL_BlitSurface(surf,NULL,dest,&destR);

    //we need to add the cam struct
    moveCamera(cam,keyListener());
    movePlayer(keyListener());
}

void render()
{
    SDL_Flip(Surf_Display);
}

int main()
{
    Initialize();
    return 0;
}

