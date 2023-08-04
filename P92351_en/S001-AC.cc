#include <iostream>
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    if (a%b < 0) cout << a/b - 1 << " " << a%b +b;
    else cout << a/b << " " << a%b;
    cout << endl;
}