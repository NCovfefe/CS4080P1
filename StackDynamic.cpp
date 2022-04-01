#include <iostream>
#include <string>
#include <fstream>
#include "StackDynamic.h"
using namespace std;

//Matrix addition
void add(float matA[][100], float matB[][100], int row, int col) {

	//If dimensions are not exact, return to menu
	if (rowsA != rowsB && colsA != colsB) {
		cout << "Error. Matrices must be the same dimensions for addition. Returning to menu. \n";
		return;
	}
	else {
		matC[row][col];
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				matC[i][j] = matA[i][j] + matB[i][j];
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

//Matrix subtraction
void sub(float matA[][100], float matB[][100], int row, int col) {

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

//File method of entering matrices
void filePopulate() {
	
	string file;
	string line; //Used to read first line of file for dimensions
	cout << "Enter the file name for the first matrix: \n";
	cin >> file;

	ifstream inputfile;
	inputfile.open(file);
	if (getline(inputfile, line)) { //Store dimensions into rows and cols of Matrix A
		rowsA = stoi(line);
		colsA = stoi(line);
	}
	
	for (int i = 0; i < rowsA; i++) {
		for (int j = 0; j < colsA; j++) {
			inputfile >> matA[i][j];
		}
	}
	inputfile.close();

	cout << "Enter the file name for the second matrix: \n";
	cin >> file;
	
	inputfile.open(file);
	if (getline(inputfile, line)) { //Store dimensions into rows and cols of Matrix B
		rowsB = stoi(line);
		colsB = stoi(line);
	}

	for (int i = 0; i < rowsB; i++) {
		for (int j = 0; j < colsB; j++) {
			inputfile >> matB[i][j];
		}
	}
	inputfile.close();
	
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