#ifndef MATHEMATICS_H_INCLUDED
#define MATHEMATICS_H_INCLUDED

typedef float matrix [2][2];


//Vector Stuff
typedef struct
{
    float x , y;

}vector;

static inline vector vect2D( float x,float y)
{
    return (vector) {x,y};
}

static inline vector vect2DAddition(vector vect1, vector vect2)
{
        return (vector){vect1.x + vect2.x, vect1.y + vect2.y};
}

static inline vector vect2DSubtraction(vector vect1, vector vect2)
{
    return (vector){vect1.x - vect2.x,vect1.y - vect2.y};
}

static inline vector vect2DMult(vector vect,float mult)
{
    return (vector){vect.x * mult, vect.y * mult};
}

static inline vector vect2DDiv(vector vect, float divisor)
{
    return (vector){vect.x / divisor , vect.y / divisor};
}

static inline vector vect2DScaling(vector vect1, vector vect2)
{
    return (vector){vect1.x * vect2.x , vect1.y * vect2.y};
}

static inline float vect2DMag(vector vect1 , vector vect2)
{
    return sqrt(vect1.x * vect2.x + vect1.y  * vect2.y);
}

static inline float vect2Ddstnc(vector vect1, vector vect2)
{
    return sqrt((vect1.x - vect2.x)*(vect1.x - vect2.x)+(vect1.y - vect2.y)*(vect1.y - vect2.y));
}

/*static inline float vectorDot(vector vect1. vector vect2)
{
    //  x1 * x2 + y1 * y2 = unit vector
    return vect1.x * vect2.x + vect1.y * vect2.y;
}
*/
static inline vector normal(vector vect)
{
    const float norm = sqrt(vect.x * vect.x + vect.y * vect.y);
    return (vector){vect.x / norm,vect.y / norm};
}
/*End of vector Stuff*/

vector getMatrixRow(float* matrix, int8_t i);
vector getMatrixColumn(float* matrix,int8_t i);

void loadIdentity(float *m);
void addMatrix(float *m1 ,float *m2, float* m);
void multMatrix(float* m1, float* m2, float* m);
void initProjectionMatrix(float* m, float fovy,float aspect,float near,float far );
void projectVectorPlane(vector* vect, vector vect2);
void fixMatrix(float* m);
void translateMatrix(float *tm, float x, float y);
void scaleMatrix(float* tm, float x, float y);




//void getBackground();
float createGrid();
float moveGrid(float *arrGrid,float x, float y);

#endif // MATHEMATICS_H_INCLUDED
