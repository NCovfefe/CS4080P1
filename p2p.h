#pragma once

extern float a[100][100];
extern float b[100][100];
extern float c[100][100];
extern float** ptrA;
extern float** ptrB;
extern float** ptrC;


float* ptrAdd(float* mat1[100], float* mat2[100], float* mat3[100], int row, int col);
float* ptrSub(float* mat1[100], float* mat2[100], int row, int col);
float* ptrMult(float* mat1[][100], float* mat2[][100], int prodrow, int prodcol);