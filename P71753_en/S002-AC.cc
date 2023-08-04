#include <iostream>
using namespace std;

int main()
{
    unsigned int n;
    while (cin >> n)
    {
        int a;
        int max = -2000000000;
        while (n > 0 and cin >> a)
        {
            if (a > max)
                max = a;
            n--;
        }
        cout << max << endl;
    }
}