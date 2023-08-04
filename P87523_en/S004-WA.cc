#include <iostream>
#include <string>

using namespace std;

void is_hello(const string &s, const string &word) 
{
    if (s.size() > word.size()) {
        bool trobat = false;
        int i = s.find('h');
        if (i != string::npos)
            trobat = (s.substr(i, word.size()) == word);
        if (trobat) {
            cout << "hello" << endl;
        } else {
            cout << "bye" << endl;
        }
    }   
    else {
        cout << "bye" << endl;
    }
}

int main() 
{
    string s;
    int i = 0;
    while (cin >> s) {
        if (s[s.size()-1] == '.') {
            is_hello(s, "hello");
        }
    }
}