#include <iostream>
using namespace std;

void print(int s, char c, int n)
{
    while (s > 0)
    {
        cout << " ";
        s--;
    }
    while (n > 0)
    {
        cout << c;
        n--;
    }

    cout << endl;
}

int main()
{
    int s, n;
    char c;
    while (cin >> s >> c >> n)
        print(s, c, n);
}