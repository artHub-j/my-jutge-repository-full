#include <iostream>
using namespace std;

typedef pair<int, int> P;
P interseccio(P a, P b)
{
    //Ia=[as,ae] 
    int as = a.first;
    int ae = a.second;
    int bs = b.first;
    int be = b.second;
    if (bs > ae or as > be)
    {
        return make_pair(0, 0);
    }
    else
    {
        return make_pair(max(as, bs), min(ae, be));
    }
}

int main()
{
    int a1, a2, b1, b2;
    P a, b;

    cin >> a1 >> a2 >> b1 >> b2;
    a.first = a1;
    a.second = a2;
    b.first = b1; 
    b.second = b2;

    P r = interseccio(a, b);
    P buit = {0, 0};

    if (r == buit) 
    {
        if (a.first < 0 or a.second < 0 or b.first < 0 or b.second < 0)
            cout << "[" << r.first << "," << r.second << "]" << endl;
        else cout << "[]" << endl;

    }
    else 
        cout << "[" << r.first << "," << r.second << "]" << endl;
}
