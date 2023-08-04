#include <iostream>
using namespace std;


int gcd(int a, int b)
/*  Pre: */
/*  Post: retorna el màxim comú divisor entre a i b. */
/*  Fita: si b = 0, el màxim comú divisor és a.
          si a = 0, el màxim comú divisor és b. */
{
    if (b == 0) return a;
    else return gcd(b, a%b);
}
