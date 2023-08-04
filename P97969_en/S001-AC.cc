#include <iostream>
using namespace std;

int main()
{
    char c;
    int i = 0;
    while (cin >> c and c != '.')
    {
        if (c == 'a')
            i++;
    }
    cout << i << endl;
}