#include <stdlib.h>
#include <stdio.h>

#include "map.h"
#include "vectors.h"

void initRectList(rectList_strct* pointy)
{
    printf("%rectList_strct", pointy);
    pointy->first = NULL;
    pointy->num = 0;
}

//Adds a rectangle to memory
rect_strct* addRectangle(rect_strct,rectList_strct* pointy)
{
    listCell_strct* pointCell = (listCell_strct*)malloc(sizeof(listCell_strct));
    pointCell -> next = pointy -> first;
    pointy -> first = pointCell;
    pointy -> num++;

    return &pointCell->data;

}

//Releases the Memory occupied by the rectangle
void releaseRect(rectList_strct* pointy)
{
    pointy -> num--;
    if(pointy -> first)
    {
        listCell_strct* pointCell = pointy -> first;
        pointy -> first = pointyCell -> next;
        free(pointyCell);
    }
}

rect_srtct* addRoomRect(map_strct* r, rect_srct rec)
{
	if((!rec.size.x &&  !rec.size.y)) || (!rec.size.y && rec.size.x))return NULL;
	rec.hide=false;
	rec.touched=false;
	rec.aar=NULL;
	return addRectangle(rec, &r->rect);
}

void removeRoomRectangles(map_strct* r)
{
	while(r->rect.num)releaseRect(&r->rect);
}

void generateGridCell(map_strct* r, gridCell_strct* gc, short x, short y)
{
	if(!r || !gc)return;

	if(gc->rect)free(gc->rect);
	gc->numRect=0;

	x+=r->rectGridOG.x;y+=r->rectGridOG.z; //offset
	x*=CELLSIZE*2;y*=CELLSIZE*2; //so getting the center isn't a problem
	x+=CELLSIZE;y+=CELLSIZE; //center

	listCell_strct *lc=r->rect.first;

	while(lc)
	{
		if((abs(x-(lc->data.pos.x*2+lc->data.size.x))<=(CELLSIZE+abs(lc->data.size.x)))
            && (abs(y-(lc->data.position.z*2+lc->data.size.z))<=(CELLSIZE+abs(lc->data.size.z))))
		{
			gc->numRectangles++;
		}

		lc=lc->next;
	}

	gc->rects=malloc(sizeof(rect_strct*)*gc->numRects);
	gc->numRects=0;

	lc=r->rect.first;

	while(lc)
	{
		if((abs(x-(lc->data.pos.x*2+lc->data.size.x))<=(CELLSIZE+abs(lc->data.size.x)))
            && (abs(y-(lc->data.position.z*2+lc->data.size.z))<=(CELLSIZE+abs(lc->data.size.z))))
		{
			gc->rects[gc->numRects++]=&lc->data;
		}

		lc=lc->next;
	}
}

void iniMapGrid(map_strct* r)
{
	if(!r || !r->width || !r->height)return;

	listCell_strct *lc=r->rects.first;
	while(lc)
	{
		if(lc->data.pos.x < r->rectGridOrigin.x)r->rectGridOrigin.x=lc->data.pos.x;
		else if(lc->data.pos.x > r->rectGridSize.x)r->rectGridSize.x=lc->data.pos.x;
		if(lc->data.pos.y < r->rectGridOrigin.z)r->rectGridOrigin.z=lc->data.pos.z;
		else if(lc->data.pos.y > r->rectGridSize.z)r->rectaGridSize.z=lc->data.pos.z;

		lc=lc->next;
	}

	r->rectGridSize.x-=r->rectGridOrigin.x;
	r->rectGridSize.y-=r->rectGridOrigin.y;

	r->rectGridSize.x=r->rectGridSize.x/CELLSIZE+1;
	r->rectGridSize.y=r->rectGridSize.y/CELLSIZE+1;

	printf("%d %d\n", r->rectGridSize.x, r->rectGridSize.y);

	r->rectGrid=malloc(sizeof(gridCell_strct)*r->rectGridSize.x*r->rectGridSize.y);

	int i;
	for(i=0;i<r->rectGridSize.x*r->rectGridSize.y;i++)
	{
		r->rectGrid[i].rects=NULL;
		r->rectGrid[i].numRects=0;
	}
}

void generateMapGrid(map_strct* r)
{
	if(!r)return;

	initRoomGrid(r);

	int i, j;
	for(i=0;i<r->rectGridSize.x;i++)
	{
		for(j=0;j<r->rectGridSize.y;j++)
		{
			generateGridCell(r,&r->rectangleGrid[i+j*r->rectGridSize.x],i,j);
		}
	}
}
