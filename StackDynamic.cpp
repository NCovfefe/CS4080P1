#include <iostream>
#include <string>
#include <fstream>
#include "StackDynamic.h"
using namespace std;



//Matrix addition
void add(float mat1[][100], float mat2[][100], int row, int col) {

	//float matC[100][100] = {0}; //Create sum matrix
	//If dimensions are not exact, return to menu
	if (rowsA != rowsB && colsA != colsB) {
		cout << "Error. Matrices must be the same dimensions for addition. Returning to menu. \n";
		return;
	}
	else {
		matC[row][col];
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				matC[i][j] = mat1[i][j] + mat2[i][j];
			}
		}
	}
	//Display matrix C
	cout << "Addition of MatrixA and MatrixB: \n";
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cout << " " << matC[i][j] << " ";
		}
		cout << "\n";
	}
}

void sub(float matA[][100], float matB[][100], int row, int col) {

	//float matC[100][100] = {0}; //Create difference matrix
	//If dimensions are not exact, return to menu
	if (rowsA != rowsB && colsA != colsB) {
		cout << "Error. Matrices must be the same dimensions for subtraction. Returning to menu. \n";
		return;
	}
	else {
		matC[row][col];
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				matC[i][j] = matA[i][j] - matB[i][j];
			}
		}
	}
	//Display matrix C
	cout << "Subtraction of MatrixA and MatrixB: \n";
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cout << " " << matC[i][j] << " ";
		}
		cout << "\n";
	}
}

//Matrix multiplication
void mult(float matA[][100], float matB[][100], int prodrow, int prodcol) {

	//float matC[100][100] = { 0 }; //Create product matrix
	int mid = colsA;
	//Check columns of matA are the same as rows of matB
	if (colsA != rowsB) {
		cout << "Error. MatrixA's columns and MatrixB's rows must be the same dimensions. Returning to menu. \n";
		return;
	}
	else {
		matC[prodrow][prodcol];
		for (int i = 0; i < prodrow; i++) {		//a00 * b00 + a01 * b10
			for (int j = 0; j < prodcol; j++) {
				for (int k = 0; k < mid; k++) {
					matC[i][j] += matA[i][k] * matB[k][j];
				}
			}
		}
	}
	//Display matrix C
	cout << "Multiplication of MatrixA and MatrixB: \n";
	for (int i = 0; i < prodrow; i++) {
		for (int j = 0; j < prodcol; j++) {
			cout << " " << matC[i][j] << " ";
		}
		cout << "\n";
	}
}

//**Fix method to read first line as size and then reads elements**
//File method of entering matrices
void filePopulate() {
	
	rowsA = 5;
	rowsB = 5;
	colsA = 5;
	colsB = 5;
	matA[rowsA][colsA];
	matB[rowsB][colsB];
	string file, file2;

	cout << "Enter file name for the first matrix: ";
	cin >> file;
	ifstream inFile;
	inFile.open(file);
	string line = "";
	string temp = "";
	if (inFile.is_open()) {
		int i = 0;
		int j = 0;
		while (getline(inFile, line)) {
			if (line != "") {
				j = 0;
				line = line + ',';
				for (int k = 0; k < line.length(); k++) {
					if (line[k] != ',') {
						temp += line[k];
					}
					else {
						matA[i][j] = stof(temp);
						temp = "";
						j++;
					}
				}
			}
			i++;
		}
	}

	cout << "Enter file name for the second matrix: ";
	cin >> file2;
	ifstream inFile2;
	inFile2.open(file2);
	string line2 = "";
	string temp2 = "";
	if (inFile2.is_open()) {
		int i = 0;
		int j = 0;
		while (getline(inFile2, line2)) {
			if (line2 != "") {
				j = 0;
				line2 = line2 + ',';
				for (int k = 0; k < line2.length(); k++) {
					if (line2[k] != ',') {
						temp2 += line2[k];
					}
					else {
						matB[i][j] = stof(temp2);
						temp2 = "";
						j++;
					}
				}
			}
			i++;
		}
	}
	//Display Matrix A
	cout << "Matrix A\n";
	for (int i = 0; i < rowsA; i++) {
		for (int j = 0; j < colsA; j++) {
			cout << " " << matA[i][j] << " ";
		}
		cout << "\n";
	}
	//Display Matrix B
	cout << "Matrix B\n";
	for (int i = 0; i < rowsB; i++) {
		for (int j = 0; j < colsB; j++) {
			cout << " " << matB[i][j] << " ";
		}
		cout << "\n";
	}
}

//Manual method of entering matrices
void manualPopulate() {

	//Create matrix A
	cout << "Enter the size of matrix A, first for the rows followed by enter, then the columns and enter again. (Max 100 x 100) ";
	cin >> rowsA >> colsA;
	//matA[rowsA][colsA];
	//Create matrix B
	cout << "Enter the size of matrix B, first for the rows followed by enter, then the columns and enter again. (Max 100 x 100) ";
	cin >> rowsB >> colsB;
	//matB[rowsB][colsB];
	cout << "Enter the numbers for matrix A. ";
	
	for (int i = 0; i < rowsA; i++) {
		for (int j = 0; j < colsA; j++) {
			cin >> matA[i][j];
		}
	}
	
	cout << "Enter the numbers for matrix B. ";
	for (int i = 0; i < rowsB; i++) {
		for (int j = 0; j < colsB; j++) {
			cin >> matB[i][j];
		}
	}

	//Display Matrix A
	cout << "Matrix A\n";
	for (int i = 0; i < rowsA; i++) {
		for (int j = 0; j < colsA; j++) {
			cout << " " << matA[i][j] << " ";
		}
		cout << "\n";
	}

	//Display Matrix B
	cout << "Matrix B\n";
	for (int i = 0; i < rowsB; i++) {
		for (int j = 0; j < colsB; j++) {
			cout << " " << matB[i][j] << " ";
		}
		cout << "\n";
	}
}