#ifndef AAR_H_INCLUDED
#define AAR_H_INCLUDED
//AAR is Axis Aligned Rectangle
#include "vectors.h"

#define NUMAARSEGMENTS (4)
#define NODESIZE (nodeSize)
#define OGNODESIZE (4096)

typedef struct
{
    mvector position, length, normal;
    bool touched;
    bool used;
}AAR;

typedef struct
{
    int data;
    int length;
}node;

typedef struct
{
    node* nodes;
    int width,height;
    mvector m,H;
}grid;

extern long int nodeSize;

//METHODS
void initAllocator(void);
void* allocateData(int size);
void initAAR(void);
void freeGrid(grid* g);
AAR* createAAR(mvector position,mvector size, mvector nomal);
void updateAAR(int id, mvector pos);
void toggleAAR(u16 id);
void generateGrid(grid* g);
void fixAAR(AAR* a);
void getOBBNodes(grid* g, OBB_s* o, u16* x, u16* X, u16* z, u16* Z);


#endif
