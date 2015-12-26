#include <stdio.h>
#include <stdlib.h>

#include "SDL.h"

#include "main.h"
#include "map.h"

void Initialize();
void render();
void update();
void cleanUp();

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
        initPlayer();
        cameraInit();

}

void cleanUp()
{
    //Free Graphical Interface
    SDL_FreeSurface(surf);
    SDL_Quit();
    freeGrid();
    exitPlayer();

}

void update(SDL_Surface* surf, SDL_Surface* dest,int x, int y)
{
    SDL_Rect destR;
    destR.x = x;
    destR.y = y;

    updateAAR();
    SDL_BlitSurface(surf,NULL,dest,&destR);
}

void render()
{
    SDL_Flip(Surf_Display);
}

int main()
{

}

