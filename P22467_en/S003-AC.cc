#include <iostream>
using namespace std;

int suma_digits(int x)
{
    if (x < 10) return x;
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
    if (n < 10) return is_prime(n);
    return is_prime(n) and is_perfect_prime(suma_digits(n));
}

int main()
{
    int n;
    while (cin >> n)
        cout << (is_perfect_prime(n) ? "true" : "false") << endl;
}