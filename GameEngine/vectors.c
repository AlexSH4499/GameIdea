#include "vectors.h"
#include <math.h>

//Returns Orthogonal vector
//Determines X movement
mvector crossProd(mvector* v, mvector* u)
{
    if(!v || !u )return NULL;
    mvector s;

                                // s(x,y,z)
    s.x = v.y * u.z - v.z * u.y;// x = y1 * z2 - z1 * y2
    s.y = v.z * u.x - v.x * u.z;// y = z1 * x2 - x1 * z2
    s.z = v.x * u.y - v.y * u.x;// z = x1 * y2 - y1 * x2

    return s;
}

//Needs future proofing for negative values
/*
    @param v  1st Vector
    @param u  2nd Vector
*/
mvector projectVector(mvector* v, mvector* u)
{
    if(!v || !u) return NULL;
    mvector s;

    //( Dot Product of V & U / Dot Prod U & U )* U
    s = (dotProd(v,u)/dotProd(u,u)) * u;

    return s;
}

/*
    @param v Vector to manipulate
    @param s Scalar used to manipulate Vector
*/

mvector scaleVector(mvector* v, float s)
{
    if(!v)return NULL;
    if(s == 0)return mvector(0,0,0);

    v.x *= s;
    v.y *= s;
    v.z *= s;

    return v;
}

mvector addVectors(mvector* v, mvector* u)
{
    mvector vcopy;
    if(!v || !u)return NULL;

    vcopy.x = v.x + u.x;
    vcopy.y = v.y + u.y;
    vcopy.z = v.z + u.z;

    return vcopy;
}

mvector subtractVectors(mvector* v, mvector* u)
{
    mvector vcopy;
    if(!v|| !u)return NULL;

    vcopy.x = v.x - u.x;
    vcopy.y = v.y - u.y;
    vcopy.z = v.z - u.z;

    return vcopy;
}

mvector rotateVector(mvector* v)
{
        //X vector(x,y,z) [X    Y     Z   ]
        // x = cos(theta) [cos() 0  -sin()]
        // y = 0          [0     1     0  ]
        // z = sin(theta) [sin() 0   cos()]

        //Y vector(0,1,0)

        //Z Vector(x,y,z)
        //x = -sin(theta)
        //y = 0
        //z = cos(theta)

}

float dotProd(mvector* v, mvector* u)
{
    if(!v || !u)return NULL;

    return v.x * u.x + v.y * u.y + v.z *u.z ;

}

float dotProd4D(mvector4D* v, mvector4D* u)
{
    if(!v || !u)return NULL;

    return v.x * u.x  + v.y * u.y + v.z * u.z + v.w * u.w;
}

//Determine the distance between two points
float magnitudeOfVector(mvector* v)
{
    if(!v)return NULL;

    return sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
}

//To determine where character is looking at
float normalizeVector(mvector* v)
{
    if(!v)return NULL;

    return (v.x/magnitudeOfVector(v)) + (v.y/magnitudeOfVector(v) + (v.z/magnitudeOfVector(v)));
}
