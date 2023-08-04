/*
Write a function that, given two square matrices a and b, computes their sum.
*/ 
#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> Fila;
typedef vector<Fila> Matrix;

Matrix sum(const Matrix& a, Matrix& b) {
  int size = a.size();
  Matrix Sum(size, Fila(size));
  for (int i = 0; i < size; ++i) {
    for (int j = 0; j < size; ++j) {
      Sum[i][j] =    a[i][j] + b[i][j];
    }
  }
  return Sum;
}
