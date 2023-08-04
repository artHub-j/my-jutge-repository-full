#include <iostream>
#include <string>

using namespace std;

void is_hello(const string &s, const string &word) 
{
    bool trobat = false;
    trobat = (s.size() < word.size());

    if (not trobat) {
        int i = s.find('h');
        trobat = (s.substr(i, word.size()) == word);
    }

    if (trobat) {
        cout << "hello" << endl;
    } else {
        cout << "bye" << endl;
    }
}

int main() 
{
    string s;
    int i = 0;
    while (cin >> s) {
        is_hello(s, "hello");
    }
}