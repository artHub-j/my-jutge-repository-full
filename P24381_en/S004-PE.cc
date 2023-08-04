#include <iostream>
using namespace std;

void cross(int n, char c)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == n / 2 or j == n / 2)
                cout << c;
            else if (j < n / 2)
                cout << " ";
        }
        if (i < n - 1)
            cout << endl;
    }
}

int main()
{
    int n;
    char c;
    while (cin >> n >> c)
        cross(n, c);
}