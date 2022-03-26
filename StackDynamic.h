#pragma once

extern int rowsA, colsA, rowsB, colsB; //rows and columns for matA and matB
extern float matA[100][100]; //Default matrixA 100x100
extern float matB[100][100]; //Default matrixB 100x100
extern float matC[100][100]; //Default operation output matrix 100x100

void add(float mat1[][100], float mat2[][100], int row, int col);
void sub(float matA[][100], float matB[][100], int row, int col);
void mult(float matA[][100], float matB[][100], int prodrow, int prodcol);
void filePopulate();
void manualPopulate();