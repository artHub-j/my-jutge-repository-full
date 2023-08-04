#include <iostream>
using namespace std;

int main()
{
    char c;
    double alc;
    int any;

    cin >> c >> alc;

    bool sancio;

    if (c == 'n')
    {
        cin >> any;
        sancio = (any < 2 and alc > 0.15) or (any >= 2 and alc > 0.25);
    }

    else if (c == 'p')
        sancio = alc > 0.15;

    if (sancio)
        cout << "Ha de ser sancionat" << endl;
    else
        cout << "Pot seguir conduint" << endl;
}