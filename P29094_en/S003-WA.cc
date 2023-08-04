#include <iostream>
#include <vector>
using namespace std;

int position_maximum(const vector<double> &v, int m)
//Pre: 0 ≤ m < v.size()
//Post: retorna la posicio i (entre 0 i m) del maxim element de v.
{
    int max = v[0];
    int i_max = 0;
    for (int i = 1; i <= m; i++)
    {
        if (v[i] > max)
        {
            max = v[i];
            i_max = i;
        }
    }
    return i_max + 1;
}

//6 1.0, 7.2, 4.3, 8.1, 8.1, 2.3

int main()
{
    int m, n;
    while (cin >> m >> n)
    {
        vector<double> V(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> V[i];
        }
        cout << position_maximum(V, m) << endl;
    }
}