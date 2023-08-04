#include <iostream>
#include <string>

using namespace std;

string reversing_words(string s)
{
    int m = s.size() - 1;
    string r;
    int j = 0;
    for (int i = m; i >= 0; i--)
    {
        r = r + s[i];
        j++;
    }
    return r;
}

int main()
{
    string s;
    while (cin >> s)
    {
        cout << reversing_words(s) << endl;
    }
}