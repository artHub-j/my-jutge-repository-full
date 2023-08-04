#include <iostream>
using namespace std;

int double_factorial(int n)
{
    if (n <= 0) return 1;
    else
    {   
        return n * double_factorial(n-2);
    }   
}

int main()
{
    int x;
    while (cin >> x)
        cout << double_factorial(x) << endl;
}