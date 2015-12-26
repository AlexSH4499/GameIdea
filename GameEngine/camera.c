#include "camera.h"

vector normGravVect;

void cameraInit(cam_strct* cam)
{
    initProjectionMatrix((float*)cam->projection,1.3962634f,240.0f,0.01f,1000.0f);
    loadIdentity((float*)cam->orientation);
    cam->position = vector(0.0f,0.0f);
    normGravVect = vector(0.0f,-1.0f);
}

void setCameraPosition(cam_strct* cam,vector vect)
{
    if(!cam){ return;}
    cam->position = vect;
}

vector moveCameraVect(cam_strct* cam, vector vect, bool free)
{
    //Verify this later as well
    vector vect1 = vector(cam->orientation[2][0],cam->orientation[2][1],cam->orientation[2][2]);

    if(!free)vect1 = normal(vect2DSubtraction(vect1,vect2DMult(normGravVect,vect1))));

    return vector((vect.y * vect1.x) + (vect.x*cam->orientation[0][0]));
}

void moveCamera(cam_strct* cam,vector vect)
{
    cam->position = vector2DAddition(cam->position,moveCameraVect(cam,vect,true));
}

 void updateCam(cam_strct* cam)
 {
    //Do update shennanigans
 }

/*These require shaders which havent been placed yet
void useCamera(camera_s* c)
{
	if(!c)return;

	gsMatrixMode(GS_PROJECTION);
	gsLoadIdentity();
	gsMultMatrix((float*)c->projection);

	gsMatrixMode(GS_MODELVIEW);
	gsMultMatrix((float*)c->modelview);
}
*/

vector box[]={(vector){0.f,0.f},
				(vector){1.f,0.f},
				(vector){0.f,1.f},
				(vector){1.f,1.f}};

void returnCamera(cam_strct *cam){}
