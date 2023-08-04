#include <iostream>
using namespace std;

int main()
{
    char c;
    cin >> c;
    if (c >= 97 and c <= 122)
    {
        cout << "lowercase" << endl;
    }
    else if (c >= 65 and c <= 92)
    {
        cout << "uppercase" << endl;
    }
    if (c == 'a' or c == 'A' or c == 'e' or c == 'E' or 
        c == 'i' or c == 'I' or c == 'o' or c == 'O' or 
        c == 'u' or c == 'U') cout << "vowel" << endl;
    else cout << "consonant" << endl;
}