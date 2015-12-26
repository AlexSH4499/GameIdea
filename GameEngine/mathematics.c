
#include <math.h>

#include "mathematics.h"

void loadIdentity33(float *m)
{
    memset(m,0x00, 4* 4);
    m[0] = m[3] = 1.0f;
}

void addMatrix(float *m1 ,float *m2, float* m)
{
    int i,j;

    for(i = 0; i < 2;i++)
        for(j = 0; j < 2 ;j++)
            m[j+i*2]=m1[j+i*2]+m2[j+i*2];
}
 void multMatrix(float* m1, float* m2, float* m)
 {
     //CHECK TO SEE IF IT WORKS APPROPRIATELY
     int i,j;

     for(i = 0; i < 2 ;i++)
        for(j = 0; j < 2; j++)
            m[i+j*2]=(m1[0+j*2]*m2[i+0*2])+(m1[1+j*2]*m2[i+1*2]);
 }

void initProjectionMatrix(float* m, float fovy,float aspect,float near,float far )
{
    float top = near * tan(fovy/2);
    float right = (top * aspect);


    float mp[2*2];

    mp[0x0] = near / right ;
    mp[0x1] = near / top ;
    mp[0x2] = -(far+near)/(far-near);
    mp[0x3] = -2.0f*(far*near)/(far-near);

    float mp2[2*2];
    loadIdentity(mp2);
    mp2[0x2] =  0.5;
    mp2[0x3] = -0.5;

    multMatrix(mp2,mp,m);
}

void projectVectorPlane(vector* vect, vector vect2)
{
    float dot = vectorDot(*vect, vect2);
    *vect = vect2DSubtraction(*vect,vect2DMult(vect2,dot));
}
void fixMatrix(float* m)
{

    vector x = vector(m[0],m[2]);
    vector y = vector(m[1],m[3]);

    projectVectorPlane(&x,y);

    x = normal(x);
    y = normal(y);

    m[0] = x.x;m[2]= x.y;
    m[1] = y.x;m[3]= y.y;
}

void translateMatrix(float *tm, float x, float y)
{
    float rm[4],m[4];

    loadIdentity(rm);
    rm[1] = x ;
    rm[3] = y ;

    multMatrix(tm,rm,m);
}

void scaleMatrix(float* tm, float x, float y)
{
	tm[0]*=x; tm[2]*=x;
	tm[1]*=y; tm[3]*=y;
}

vector getMatrixRow(float* matrix, int8_t i)
{
    if(!matrix || i >= 2) return vector(0,0);
    return  vector(matrix[i+0*2],matrix[i+1*2]);

}

vector getMatrixColumn(float* matrix, int8_t i)
{
        if(!matrix || i >= 2) return vector(0,0);
        return vector(matrix[0+i*2],matrix[1+i*2]);

}

