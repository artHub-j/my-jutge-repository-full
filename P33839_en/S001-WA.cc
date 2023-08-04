#include <iostream>

using namespace std;

int sumdigits(int n)
{
    int r = 1;
    if (n == 0)
        r = 0;
    while (n != 0)
    {
        r = r + (n % 10);
        n = n / 10;
    }
    return r;
}

int main()
{
    int n;
    while (cin >> n)
    {
        cout << "The sum of the digits of " << n << " is " << sumdigits(n) << "." << endl;
    }
}