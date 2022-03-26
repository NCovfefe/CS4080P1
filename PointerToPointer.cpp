#include <iostream>
#include <string>
#include <fstream>
#include "p2p.h"
#include "StackDynamic.h"
using namespace std;



//float* ptrAdd(float* mat1[100], float* mat2[100], float* mat3[100], int row, int col) {
//	
//	mat3 = new float*[100];
//
//	for (int i = 0; i < row; i++) {
//		for (int j = 0; j < col; j++) {
//			mat3[i][j] = mat1[i][j] + mat2[i][j];
//		}
//	}
//	return *mat3;
//}



float* ptrSub(float* mat1[100], float* mat2[100], int row, int col);
float* ptrMult(float* mat1[][100], float* mat2[][100], int prodrow, int prodcol);


