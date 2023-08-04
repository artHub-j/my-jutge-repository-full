#include <iostream>
using namespace std;

void min_max(int a, int b, int &mn, int &mx)
{
    if (a > b)
    {
        mx = a;
        mn = b;
    }
    else
    {
        mx = b;
        mn = a;
    }
}

int main()
{
    int x, y;
    while (cin >> x >> y)
    {
        int mn = -2000000000, mx = 2000000000;
        min_max(x, y, mn, mx);
        cout << mn << ' ' << mx << endl;
    }
}
