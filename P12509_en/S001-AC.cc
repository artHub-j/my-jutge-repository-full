#include <iostream>
using namespace std;

int factorial(int n) //factorial(5) = 120 = 1*2*3*4*5;
{
    if (n == 0) return 1;
    else return n * factorial(n-1);
}

int main()
{
    int x;
    while (cin >> x)
    {
        cout << factorial(x) << endl;
    }
}
