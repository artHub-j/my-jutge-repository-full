/*
Write a function that tells if s is a palindrome or not. Remember that a word is a palindrome if it reads the same from left to right than from right to left. In this exercise, s can be rather large; this is why it is passed by reference.

In order to compare the efficiency of your solution against the efficiency of the solution of the Judge, start checking s from its ends.
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {

  unsigned long n;
  int sum;

  while (cin >> n){
    sum = 0;
    bool found = false;
    vector<int> v(n);

    for (int i = 0; i < n; i++){
      cin >> v[i];
      sum += v[i];
    }

    int j = 0;
    while (j < n and !found){
      if (sum-v[j] == v[j]) {
        cout << "YES" << endl;
        found = true;
      }
      j++;
    }
    if (!found) cout << "NO" << endl;
  }

}
