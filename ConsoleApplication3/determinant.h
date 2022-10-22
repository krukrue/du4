#pragma once
#include <iostream>
#include <vector>
using namespace std;

class determinant
{
public:
	vector<int> vect;
	int size;
	determinant(int value, vector<int> vectr) {
		this->vect = vectr;
		this->size = value;
	}
    ~determinant() {
        delete createarrow();
        
    }
    int** createarrow();
    void substitution(int** matrix, int** temp, int p, int q, int n);
    int MatrixDeterminant(int** matrix, int n);

    
};

