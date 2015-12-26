#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED

#include<stdio.h>

#include "mathematics.h"

#define TILESIZE (1)
#define TILE_SIZE_FLOAT ((float)TILESIZE)

#define CELL_SIZE (2)

/////////////////////
//    ***********  //
//    *         *  //
//    ***********  //
/////////////////////
typedef struct
{
    vector pos;
    vector lenght;
    vector normal
    //material_strct* material;
    AAR_strct* aar;

    bool jumpable,hide,touched, collides;

}rect_strct;

/////////////////////
// __ __  __ __
//|__|__||__|__|
//|__|__||__|__|
//
//////////////////////

typedef struct listCell_strct
{
    rect_strct data;
    struct listCell_strct* next;

}listCell_strct;

typedef struct
{
    listCell_strct* first;
    int num;
}rectList_strct;

typedef struct
{
    rectList_strct** rects;
    int numRects;

}gridCell_strct;

typedef struct
{
    short x,y;
    short u,v;
    short u2,v2;
}rectVertex_strct;

typedef struct
{

    u16 width, height;
    u16 indexBuffers;

    mvector position;
    mvector rectGridSize;
    mvector rectGridOGSize;

    gridCell_strct* rectGrid;

    rectList_strct rectangles;

    rectVertex_strct* vertBuffer;

    int numVertices;
    int numIndexBuffers;
    int* numIndices;



}map_strct;

void mapInit();
void mapExit();

void initRectList(rectList_strct* pointy);
rect_strct* addRectangle(rect_strct rect, rectList_strct* pointy);
void releaseRect(rectList_strct* pointy);

void readVect(vector* vect,FILE* file, bool fp);
void readRect(rect_strct* rect, FILE* file);


#endif // MAP_H_INCLUDED
