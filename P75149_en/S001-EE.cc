#include <iostream>
using namespace std;

int main()
{
    char c;
    bool trobat = false;
    while (cin >> c and c != '.')
    {
        if (c == 'a')
            trobat = true;
    }
    if (trobat)
        cout << "yes" << endl;
    else
        cout << "no" << endl;
}