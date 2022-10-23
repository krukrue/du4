#include "determinant.h"
#include <iostream>
#include <vector>
using namespace std;


int** determinant::createarrow() { // create arrow from vector, unnecessary function if we will push arrow.
 	int** mat = 0;
	mat = new int* [size];

	int counter = 0;
	for (int i = 0; i < size; i++) {
		mat[i] = new int[size];

		for (int j = 0; j < size; j++) {
			mat[i][j] = vect[counter];
			counter++;
		}
	}
	return mat;
}


void determinant::substitution(int** matrix, int** temp, int p, int c, int n) { // default substitution 
    int i = 0, j = 0;

    for (int row = 0; row < n; row++) {
        for (int column = 0; column < n; column++) {

            if (row != p && column != c) { // copy to temp matrix only unique elements
                temp[i][j++] = matrix[row][column];
                if (j == n - 1) { // if column end
                    j = 0; 
                    i++; // increase row
                }
            }
        }
    }

}

int determinant::MatrixDeterminant(int** matrix, int n) {
    if (n == 1) {
        return matrix[0][0];
    }
    if (n == 2) {
        return (matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]);
    }
    int** temp = new int* [size];
    for (int i = 0; i < size; i++) { // create empty arrow with needed size
        temp[i] = new int[size]; // allocate every row 
    }
    int sign = 1;
    int determinant = 0;
    for (int i = 0; i < n; i++) { // recursive function call while size > i for first rows, when it be 2/1 call simple function.

        substitution(matrix, temp, 0, i, n);
        determinant += sign * matrix[0][i] * MatrixDeterminant(temp, n - 1);
        sign = -sign; // change sign 
    }
    return determinant;
}
