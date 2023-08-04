#include <iostream>
using namespace std;

int main()
{
    char c;
    cin >> c;
    if (c >= 97 and c <= 122) c = c - 32;
    else if (c >= 65 and c <= 92) c = c + 32;
    cout << c << endl;
}