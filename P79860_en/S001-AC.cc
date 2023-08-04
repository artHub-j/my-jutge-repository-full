#include <iostream>
#include <string>
using namespace std;

void barres (int n) 
{
    if (n == 0) cout << endl;
    if (n == 1) cout << "*" << endl;
    else 
    {
        int compt = 0;
        for (int i = 0; i < n; ++i)
        {
            cout << "*";
            compt++;
        }
        cout << endl;
        barres(n-1);
        if (compt == n) barres(n-1);
        else barres(n-2);
    }
}

int main() 
{
    int n;
    cin >> n;
    barres(n);
}