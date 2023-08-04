#include <iostream>
#include <vector>
using namespace std;

int first_occurrence(double x, const vector<double> &v)
{
    bool trobat = false;
    int r;
    if (x < v[0])
        return -1;
    else
    {
        for (unsigned int i = 0; i < v.size(); i++)
        {
            if (v[i] == x)
            {
                r = i;
                trobat = true;
                break;
            }
        }
    }

    return trobat ? r : -1;
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