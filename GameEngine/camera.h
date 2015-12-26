#ifndef CAMERA_H_INCLUDED
#define CAMERA_H_INCLUDED

#include "mathematics.h"

typedef struct
{
    matrix projection;
    matrix orientation;
    vector position;

}cam_strct;

void returnCamera();

void cameraInit(cam_strct * cam);

void moveCamera(cam_strct* cam, vector vect);

void updateCam(cam_strct* cam);

void setCameraPosition(cam_strct* cam,vector vect);

vector moveCameraVect(cam_strct* cam, vector vect);

#endif // CAMERA_H_INCLUDED
