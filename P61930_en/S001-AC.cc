#include <iostream>
using namespace std;

int suma_digits(int n)
{
    if (n == 0) return 0;
    else return suma_digits(n/10) + n%10;
}

bool is_multiple_3(int n)
{
    n = suma_digits(n);
    return n%3 == 0;
}

int main()
{
    int n;
    while (cin >> n)
    {
        cout << (is_multiple_3(n) ? "true" : "false") << endl;
    }
}