#include <iostream>
using namespace std;

int main()
{
    int x;
    while (cin >> x)
    {
        int c = 0;
        while (x != 1)
        {
            if (x % 2 == 0)
                x /= 2;
            else
                x = x * 3 + 1;
            ++c;
        }
        cout << c << endl;
    }
}