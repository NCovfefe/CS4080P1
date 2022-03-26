#include <iostream>
#include <string>
#include <fstream>
#include "StackDynamic.h"
#include "p2p.h"

using namespace std;

int rowsA, colsA, rowsB, colsB;
float matA[100][100]; //Default matrixA 100x100
float matB[100][100]; //Default matrixB 100x100
float matC[100][100]; //Default operation output matrix 100x100
float** ptrA;
float** ptrB;
float** ptrC;



int main() {

	int menuSelection = 0; //Selects operation to be performed
	int matFill = 0; //Determines manual or file entry
	
	ptrA = new float* [100];
	ptrB = new float* [100];
	ptrC = new float* [100];

	for (int i = 0; i < 100; i++) {
		ptrC[i] = new float[100];
	}
	//Pick file or manual entry
	cout << "Enter matrices by file or manually? (1 for file, 2 for manual) ";
	cin >> matFill;
	if (matFill == 1) {
		filePopulate();
	}
	else if (matFill == 2) {
		manualPopulate();
	}

	do {

		cout << "Menu\n 1:Addition\n 2:Subtraction\n 3:Multiplication\n 4:Enter new matrices\n 5:Exit \n";
		cin >> menuSelection;

		//Switch cases for menu selection
		switch (menuSelection) {
		case 1:
			int addrows, addcols;
			addrows = rowsA;
			addcols = colsA;
			add(matA, matB, addrows, addcols);
			break;
		case 2:
			int subrows, subcols;
			subrows = rowsA;
			subcols = colsA;
			sub(matA, matB, subrows, subcols);
			break;
		case 3:
			int multrows, multcols;
			multrows = rowsA;
			multcols = colsB;
			mult(matA, matB, multrows, multcols);
			break;
		case 4:
			cout << "Enter matrices by file or manually? (1 for file, 2 for manual): ";
			cin >> matFill;
			if (matFill == 1) {
				filePopulate();
			}
			else if (matFill == 2) {
				manualPopulate();
			}
			break;
		case 5:
			exit(0);
			break;
		default://Fix the default case//
			cout << "Incorrect input.\n";
			continue;
		}

	} while (menuSelection != 5);
	return 0;
}