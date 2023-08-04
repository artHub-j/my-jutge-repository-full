#include <iostream>
#include <sstream>
#include <stack>
using namespace std;

bool is_pal(const stack<int> &s)
{
    int n = s.size() / 2;
    stack<int> aux = s;
    stack<int> aux2;
    if (s.size() % 2 == 0)
    {
        for (int i = 0; i < n; i++)
        {
            aux2.push(aux.top());
            aux.pop();
        }
    }
    else
    {
        for (int i = 0; i <= n; i++)
        {
            aux2.push(aux.top());
            if (i == n)
                aux2.pop();
            aux.pop();
        }
    }
    return aux == aux2;
}

int main()
{
    string linia;
    while (getline(cin, linia))
    {
        istringstream ss(linia);
        stack<int> s;
        int n;
        while (ss >> n)
        {
            s.push(n);
        }
        if (is_pal(s))
            cout << "It is a palindrome." << endl;
        else
            cout << "It is NOT a palindrome." << endl;
    }
}
