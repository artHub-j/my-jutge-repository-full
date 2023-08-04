#include <iostream>

using namespace std;

int main()
{
    string primera;
    cin >> primera;
    string seq;
    int max = 1;
    int cont = 1;
    while (cin >> seq)
    {
        if (primera != seq)
            cont = 0;
        else
        {
            ++cont;
            if (cont > max)
                max = cont;
        }
    }
    cout << max << endl;
}