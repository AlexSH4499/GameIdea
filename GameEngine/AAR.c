#include "AAR.h"

#define ALLOCATORSIZE (9*1024)

int allocatorPool[ALLOCATORSIZE];
long int allocatorCounter;

static const int AARSegments[NUMAARSEGMENTS][2]={{0,1},{1,2},{3,2},{0,3}};
static const int AARSegmentsPD[NUMAARSEGMENTS][2]={{0,0},{1,1},{3,0},{0,1}};

AAR aaRectangles[NUMAARS];
grid AARgrid;

int nodeSize =OGNODESIZE;

void initAllocator(void)
{
    allocatorCounter=0;
}

void* allocateData(int size)
{
    if(allocatorCounter + size> ALLOCATORSIZE)return NULL;
    allocatorCounter += size;

    return &allocatorPool[allocatorCounter-size];
}

void initAAR(void)
{
         //Add NUMAARS GLOBAL VAR
    int i;
    for(i = 0; i < NUMAARS;i++)
    {
        aaRect[i].used = false;
    }

    AARgrid.nodes=NULL;
    AARgrid.width=AARgrid.height=0;

    initAllocator();
}

void freeGrid(grid* g)
{
    if(!g || !g->nodes)return;
    g->nodes=NULL;
    initAllocator();
}
void drawAAR()
{

}

AAR* createAAR(mvector position,mvector size, mvector nomal)
{
    int i;
    for(i = 0;i <NUMAARS;i++)
    {
        if(!aaRectangles[i].used)
		{
			aaRectangles[i].used=true;
			aaRectangles[i].position=position;
			aaRectangles[i].size=size;
			aaRectangles[i].normal=normal;
			return &aaRectangles[i];
		}
    }
    return NULL;
}

void updateAAR(int id, mvector pos)
{
    int i = id;

    if(aaRectangles[i].used)
    {
        aaRectangles[i].position=pos;
    }
}

void toggleAAR(u16 id)
{
    if(id>= NUMAARS)return;
    aaRectangles[id].used ^=1;
}

void generateGrid(grid* g)
{
    if(!g)g = &AARgrid;

    freeGrid(g);

    int i;
    bool b= false;
    mvector m,M;

    m = mvector((1<<29),(1<<29),(1<<29));
    M = mvector(-(1<<29),-(1<<29),-(1<<29));

    for(i = 0 ;i<NUMAARS;i++)
    {
        if(aaRectangles[i].used)
        {
            if(aaRectangles[i].position.x<m.x)m.x=aaRectangles[i].position.x;
			if(aaRectangles[i].position.z<m.z)m.z=aaRectangles[i].position.z;

			if(aaRectangles[i].position.x+aaRectangles[i].size.x>M.x)M.x=aaRectangles[i].position.x+aaRectangles[i].size.x;
			if(aaRectangles[i].position.z+aaRectangles[i].size.z>M.z)M.z=aaRectangles[i].position.z+aaRectangles[i].size.z;
			b=true;
        }

    }
    if(!b)return;

    nodeSize = OGNODESIZE;

    g->width = (M.x-m.x)/NODESIZE+1;
    g->height = (M.z-m.z)/NODESIZE+1;

    while((sizeof(node)*g->width*g->height)>(ALLOCATORSIZE/3))
    {
        nodeSize *= 2;
        g->width = (M.x-m.x)/NODESIZE+1;
        g->height = (M.z-m.z)/NODESIZE+1;
    }

    g->nodes=allocateData(sizeof(node)*g->width*g->height);

    g->m=m;
    g->H=M;

    static u16 temp[NUMAARS];

    int j,k;
for(i=0;i<g->width;i++)
	{
		for(j=0;j<g->height;j++)
		{
			node_s* n=&g->nodes[i+j*g->width];
			n->length=0;
			for(k=0;k<NUMAARS;k++)
			{
				if(aaRectangles[k].used)
				{
					const float mX=g->m.x+i*NODESIZE, MX=g->m.x+(i+1)*NODESIZE;
					const float mZ=g->m.z+j*NODESIZE, MZ=g->m.z+(j+1)*NODESIZE;
					if(!((aaRectangles[k].position.x<mX && aaRectangles[k].position.x+aaRectangles[k].size.x<mX)
					||   (aaRectangles[k].position.x>MX && aaRectangles[k].position.x+aaRectangles[k].size.x>MX)
					||   (aaRectangles[k].position.z<mZ && aaRectangles[k].position.z+aaRectangles[k].size.z<mZ)
					||   (aaRectangles[k].position.z>MZ && aaRectangles[k].position.z+aaRectangles[k].size.z>MZ)))
					{
						temp[n->length]=k;
						n->length++;
					}
				}
			}
			if(n->length){n->data=allocateData(sizeof(u16)*n->length);memcpy(n->data,temp,n->length*sizeof(u16));}
			else n->data=NULL;
		}
	}

}

void fixAAR(AAR* a)
{
    if(!a) return;

    if(a->size.x<0){a->position.x+=a->size.x;a->size.x=-a->size.x;}
    if(a->size.y<0){a->position.y+=a->size.y;a->size.y=-a->size.y;}
	if(a->size.z<0){a->position.z+=a->size.z;a->size.z=-a->size.z;}
}

void getOBBNodes(grid* g, OBB_s* o, u16* x, u16* X, u16* z, u16* Z)
{
	if(!o)return;
	if(!g)g=&AARgrid;

	const mvector m=subtractVectors(o->AABBo,g->m);
	const mvector M=addVectors(m,o->AABBs);

	*x=m.x/NODESIZE;*z=m.z/NODESIZE;
	*X=M.x/NODESIZE;*Z=M.z/NODESIZE;
}
