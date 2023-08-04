#include <iostream>
#include <stack>
using namespace std;

void invertir_pila(stack <int> &s)
/*  Pre: */
/*  Post: inverteix seqüències de nombres naturals en una pila */
{
    if (s.empty()) cout<<endl;
    while(not s.empty())
    {
        cout<<s.top();
        if (s.size() > 1) cout<<" ";
        else cout<<endl;
        s.pop();
    }
}

int main()
{
    int n;
    stack <int> s;

    while (cin >> n)
    {
        s.push(n);
        if (n == -1)
        {
            s.pop();
            invertir_pila(s);
        }
    }
}