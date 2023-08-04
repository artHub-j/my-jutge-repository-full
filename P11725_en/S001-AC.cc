/*Write a function that tells if the integer number x is present in the vector of integer numbers v.

In order to compare the efficiency of your solution against the efficiency of the solution of the Judge, start searching for x from the lowest positions.*/

#include <iostream>
#include <vector>

using namespace std;

bool exists(int x, const vector<int>& v){
  bool encontrado = false;
  int i = 0;

  while (!encontrado and i < v.size()){
    if (x == v[i]) encontrado = true;
    i++;
  }
  return encontrado;
}
