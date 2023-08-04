/*Write a program that reads sequences of natural numbers, and that for each one prints the number of pairs of consecutive numbers such that the second number of the pair is greater than the first one.

Input

Input consists of a natural number n, followed by n sequences of strictly positive natural numbers. Each sequence ends with a zero.

Output

For every sequence, print in a line the number of pairs of consecutive numbers such that the second number of the pair is greater than the first one.*/

#include <iostream>

using namespace std;

int main() {

  int n;
  cin >> n;

  for (int i = 0; i < n; i++){
    int a;
    int b;
    int pairs = 0;
    cin >> a;

    while(a != 0){
      cin >> b;

      if (b > a){
        ++pairs;
      }

      a = b;
    }

    cout << pairs << endl;
  }
}
