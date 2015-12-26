#include "camera.h"

mvector normGravVect;

void cameraInit(cam_strct* cam)
{
    initProjectMatrix((float*)cam->projection,1.3962634f,240.0f,0.01f,1000.0f);
    loadIdentity44((float*)cam->orientation);
    cam->position = mvector(0.0f,0.0f);
    normGravVect = mvector(0.0f,-1.0f);
}

void setCameraPosition(cam_strct* cam,mvector vect)
{
    if(!cam){ return;}
    cam->position = vect;
}

vector moveCameraVect(cam_strct* cam, mvector vect, bool free)
{
    //Verify this later as well
    vector vect1 = mvector(cam->orientation[2][0],cam->orientation[2][1],cam->orientation[2][2]);

    if(!free)vect1 = normal(subtractVectors(vect1,dotProd(normGravVect,vect1))));

    return mvector((vect.y * vect1.x) + (vect.x*cam->orientation[0][0]));
}

void moveCamera(cam_strct* cam,mvector vect)
{
    if(!cam )return;
    if(!vect)vect =(0.0,0.0,0.0);

    cam->position = addVectors(cam->position,moveCameraVect(cam,vect,true));
}

 void updateCam(cam_strct* cam)
 {
    //Do update shennanigans
    if(cam == NULL)return;

    //IDK WHAT TO DO HERE

 }

/*These require shaders which haven't been placed yet*/
void useCamera(camera_s* c)
{
	if(!c)return;

	gsMatrixMode(GS_PROJECTION);
	gsLoadIdentity();
	gsMultMatrix((float*)c->projection);

	gsMatrixMode(GS_MODELVIEW);
	gsMultMatrix((float*)c->modelview);
}
/*----------------------------------------------------*/

vector box[]={(vector){0.f,0.f},
				(vector){1.f,0.f},
				(vector){0.f,1.f},
				(vector){1.f,1.f}};

void returnCamera(cam_strct *cam)
{
    if(cam == NULL)return;

    cam->position = mvector(0.0,0.0,0.0);//returns camera to initial place
}
