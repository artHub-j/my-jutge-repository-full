#include <iostream>
using namespace std;

int suma_digits(int x)
{
    if (x == 0) return 0;
    else return suma_digits(x/10) + x%10;
}

bool is_prime(int x, int i = 2)
{
    if (x <= 2)
        return (x == 2) ? true : false;
    if (x % i == 0)
        return false;
    if (i * i > x)
        return true;
    return is_prime(x, i + 1);
}

bool is_perfect_prime(int n)
{
    return is_prime(suma_digits(n));
}

int main()
{
    int n;
    while (cin >> n)
        cout << (is_perfect_prime(n) ? "true" : "false") << endl;
}