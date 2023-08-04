#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void change_base(int n, int base)
{
    if (n > 0)
    {
        int val = 0;
        val = n % base;
        cout << val;
        change_base(n / base, base);
    }
}

int main()
{
    int n;
    while (cin >> n)
    {
        cout << n << " = ";
        change_base(n, 2);
        cout << ", ";
        change_base(n, 8);
        cout << ", ";
        change_base(n, 16);
        cout << endl;
    }
}