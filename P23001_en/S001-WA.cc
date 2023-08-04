#include <iostream>

using namespace std;

int main()
{
    string og;
    cin >> og;

    string s;
    int cont;
    while (cin >> s)
    {
        if (s != og)
            cont = 1;

        else
            ++cont;
    }
    cout << cont << endl;
}