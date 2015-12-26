#ifndef MATRICES_H_INCLUDED
#define MATRICES_H_INCLUDED

typedef float matrix[4][4];

void loadIdentity44(float *matrix);
void tranlsateMatrix44(float *matrix,mvector4D);
void multMatrix44(flaot* m1,float* m2, float* m);

mvector4D getMatrixRow44(float* m, int i);
mvector4D getMatrixColumn44(float* m,int i);



#endif // MATRICES_H_INCLUDED
