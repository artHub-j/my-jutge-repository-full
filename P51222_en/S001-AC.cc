#include <iostream>
using namespace std;


int number_of_digits(int n)
{
    int num;
    if (n / 10 == 0) num = 1;
    else num = 1 + number_of_digits(n/10);
    return num;
}


int main () {
  int n;
  while (cin >> n) cout << number_of_digits(n) << endl;
}