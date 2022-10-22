#include <iostream>
#include "determinant.h"


using namespace std;

int main() {
    vector<int> G = { 3,4,2,1,6,7,8,2,3,4,2,0, 9, 8, 5, 2 };
    vector<int> A = { 3,4,6, 7,8,9,10,4,5 };
    vector<int> B = { 3,4,6, 7};

    determinant det(3, A);
    cout << "Result: " << det.MatrixDeterminant(det.createarrow(), det.size) << endl;
    determinant det1(2, B);
    cout << "Result: " << det1.MatrixDeterminant(det1.createarrow(), det1.size) << endl;
    determinant det2(4, G);
    cout << "Result: " << det2.MatrixDeterminant(det2.createarrow(), det2.size) << endl;
    return 0;
}