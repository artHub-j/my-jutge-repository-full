#include <iostream>
#include <stack>
using namespace std;

int main()
{
    int a;
    cin >> a;
    if (a > 30)
    {
        cout << "it's hot" << endl;
        if (a > 100) cout << "water would boil" << endl;
    }
    else if (a < 10) 
    {
        cout << "it's cold" << endl;
        if (a <= 0) cout << "water would freeze" << endl;
    }
    else cout << "it's ok" << endl;
}