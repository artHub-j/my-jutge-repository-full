#include <iostream>
using namespace std;

int main()
{
    int n;
    bool b = false;
    int i = 1;
    while (cin >> n and b == false)
    {
        if (n % 2 == 0)
        {
            b = true;
            cout << i << endl;
        }
        i++;
    }
}