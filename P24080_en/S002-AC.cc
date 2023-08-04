#include <iostream>

using namespace std;

int main()
{
    int n;
    bool b = true;
    while (cin >> n)
    {
        if (not b)
            cout << endl;
        b = false;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; ++j)
                cout << n;
            cout << endl;
        }
    }
}