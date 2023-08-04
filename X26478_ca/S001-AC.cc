#include <iostream>

using namespace std;

int main()
{
    unsigned int n;
    cin >> n;

    while (n > 0)
    {
        cout << n << endl;
        if (n % 10 == 5 or n % 10 == 0)
            cout << "Beep" << endl;
        n--;
    }
}