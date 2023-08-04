#include <iostream>
#include <vector>
using namespace std;

//0 ≤ left ≤ v.size() and −1 ≤ right < v.size()
int position(double x, const vector<double>& v, int left, int right)
{
    if (right >= left)
    {
        int mid = left + (right - left) / 2;
        if (v[mid] == x) return mid;
        if (v[mid] > x) return position(x, v, left, mid-1);
        if (v[mid] < x) return position(x, v, mid+1, right);
    }
    return -1;
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
            int left, right;
            cin >> x >> left >> right;
            cout << position(x, V, left, right) << endl;
        }
    }
}