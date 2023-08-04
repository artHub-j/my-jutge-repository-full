#include <iostream>
using namespace std;

int main()
{
    int h, m, s;
    cin >> h >> m >> s;
    s++;
    if (s == 60)
    {
        m++;
        m = 0;
        if (m == 60)
        {
            m++;
            m = 0;
        }
        if (h == 24) h = 0;
    }

    if (h < 10) cout << "0";
    cout << h << ':';
    if (m < 10) cout << "0";
    cout << m << ':';
    if (s < 10) cout << "0";
    cout << s << endl;
} 