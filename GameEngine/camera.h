#ifndef CAMERA_H_INCLUDED
#define CAMERA_H_INCLUDED

#include "matrices.h"
#include "vectors.h"

typedef struct
{
    matrix projection;
    matrix orientation;
    mvector position;

}cam_strct;

void returnCamera();

void cameraInit(cam_strct * cam);

void moveCamera(cam_strct* cam, mvector vect);

void updateCam(cam_strct* cam);

void setCameraPosition(cam_strct* cam,mvector vect);

mvector moveCameraVect(cam_strct* cam, mvector vect);

#endif // CAMERA_H_INCLUDED
