#include <iostream>
#include <vector>
using namespace std;

int first_occurrence(double x, const vector<double> &v)
{
    double r;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == x) 
        {
            r = i;
            break;
        } 
    }
    return r;
}

int main()
{
    int n;
    while (cin >> n)
    {
        vector<double> V(n);
        for (int i = 0; i < n; ++i)
            cin >> V[i];
        int t;
        cin >> t;
        while (t--)
        {
            double x;
            cin >> x;
            cout << first_occurrence(x, V) << endl;
        }
    }
}