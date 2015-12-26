##ifndef VECTORS_H_INCLUDED
#define VECTORS_H_INCLUDED

typedef struct
{
    float x;
    float y;
    float z;
}mvector;

typedef struct
{
    float x;
    float y;
    float z;
    float w;
}mvector4D;

typedef struct
{
    float x;
    float y;
}point;

//Vector Manipulations

//Needs future proofing for negative values
/*
    @param v  1st Vector
    @param u  2nd Vector
*/
mvector projectVector(mvector* v, mvector* u)
mvector crossProd(mvector*v, mvector* u);
mvector addVectors(mvector* v, mvector* u);
mvector subtractVectors(mvector* v, mvector* u);
mvector scaleVector(mvector* v, float s);

float dotProd4D(mvector4D* v, mvector4D* u);

float normalizeVector(mvector* v);// x / mag && y / mag
float magnitudeOfVector(mvector* v);//a2 = sqrt(b2 +c2)

#endif
