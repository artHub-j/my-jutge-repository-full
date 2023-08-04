#include <iostream>
using namespace std;

int product_digits(int n)
{
    int r = 1;
    if (n == 0)
        r = 0;
    while (n != 0)
    {
        r = r * (n % 10);
        n = n / 10;
    }
    return r;
}

int main()
{
    int n;
    while (cin >> n)
    {
        bool b = false;
        int r;
        while (not b)
        {
            r = product_digits(n);
            cout << "The product of the digits of " << n
                 << " is ";
            cout << r << "." << endl;
            n = r;
            if (n / 10 == 0)
            {
                cout << "----------" << endl;
                b = true;
            }
        }
    }
}
