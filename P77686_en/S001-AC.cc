#include <iostream>
#include <list>
using namespace std;

bool is_palindromic(int n)
{
    bool b = true;
    list<int> l;

    while (n > 0)
    {
        l.push_back(n % 10);
        n = n / 10;
    }
    if (l.size() % 2 == 0)
    {
        list<int> aux = l;
        while (not aux.empty())
        {
            if (aux.front() != aux.back())
                b = false;
            aux.pop_front();
            aux.pop_back();
        }
    }
    else
    {
        while (l.size() != 1)
        {
            if (l.front() != l.back())
                b = false;
            l.pop_front();
            l.pop_back();
        }
    }
    return b;
}

int main()
{
    int n;
    while (cin >> n)
        cout << (is_palindromic(n) ? "true" : "false") << endl;
}