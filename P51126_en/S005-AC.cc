#include <iostream>
using namespace std;

typedef pair<int, int> P;
void interseccio(int a1, int a2, int b1, int b2)
{
    if (b1 > a2 or a1 > b2)
    {
        cout << "[]" << endl;
    }
    else
    {
        P r = make_pair(max(a1, b1), min(a2, b2));
        cout << "[" << r.first << "," << r.second << "]" << endl;
    }
}

int main()
{
    int a1, a2, b1, b2;
    cin >> a1 >> a2 >> b1 >> b2;
    interseccio(a1, a2, b1, b2);
}
