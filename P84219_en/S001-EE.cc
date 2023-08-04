#include <iostream>
#include <vector>
using namespace std;


int first_occurrence(double x, const vector<double>& v)
{
    bool trobat = false;
    unsigned int i = 0;
    while (not trobat and i < v.size())
    {
        if (v[i] == x) trobat = true;
        else 
        {
            i++;
        }
    }
    return i;
}


int main() {
    int n;
    while (cin >> n) {
        vector<double> V(n);
        for (int i = 0; i < n; ++i) cin >> V[i];
        int t;
        cin >> t;
        while (t--) {
            double x;
            cin >> x;
            cout << first_occurrence(x, V) << endl;
        }
    }
}