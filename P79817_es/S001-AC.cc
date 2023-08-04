#include <iostream>
using namespace std;

int potencia(int a, int b)
{
    int r = 1;
    while (b > 0)
    {
        r = r * a;
        b--;
    }
    return r;
}

int main()
{
    int a, b;
    while (cin >> a >> b)
    {
        cout << potencia(a, b) << endl;
    }
}