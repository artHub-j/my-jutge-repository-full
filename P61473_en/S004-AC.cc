/*Write a function that, given a square matrix m, tells if it is symmetric or not.

Remember that a matrix m is symmetric if mi,j=mj,i for any i and for any j.

Precondition

m is a square matrix n× n with n = 0.*/

//Matriu simètrica

#include <iostream>
#include <vector>
using namespace std;


typedef vector< vector<int> > Matrix;

bool is_symmetric(const Matrix& m) {
    int n = m.size();
    
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j){
            if (m[i][j] != m[j][i]) return false;
        }
    }
    return true;
}