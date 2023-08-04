#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void change_base(int n, int base)
{
    if (n > 0)
    {
        change_base(n/base, base);
        int val = n % base;
        if (val > 9)
        {
            if (val == 10) cout << "A";
            else if (val == 11) cout << "B";
            else if (val == 11) cout << "C";
            else if (val == 11) cout << "D";
            else if (val == 11) cout << "E";
            else cout << "F";
        }
        else cout << val;
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