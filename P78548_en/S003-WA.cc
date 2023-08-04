#include <iostream>
#include <vector>
using namespace std;

string reverse_word(string &s)
{
    string r;
    int m = s.size() - 1;
    for (int i = m; i >= 0; i--)
    {
        r = r + s[i];
    }
    return r;
}

int main()
{
    int n;
    cin >> n;
    string s;
    vector<string> v;
    while (n > 0)
    {
        cin >> s;
        s = reverse_word(s);
        v.push_back(s);
        n--;
    }
    int m = v.size() - 1;
    for (int i = m; i >= 0; i--)
    {
        cout << v[i] << endl;
    }
}