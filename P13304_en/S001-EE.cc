#include <iostream>
#include <stack>

using namespace std;

istream& operator>>(istream &is, stack<int> &p)
{
    int n;
    is >> n;
    for (int i = 0; i < n ; ++i){
        int e;
        is >> e;
        p.push(e);
    }
    return is;
}

ostream& operator<<(ostream& os, stack<int> p)
{
    int n = p.size();
    for (int i = 0; i < n; ++i) {
        os << p.top();
        if (i < n-1) os << " ";
        p.pop();
    }
    os << endl;
    return os;
}

//-------------------------------------------------

stack<int> ordena(stack<int> &p)
{
    stack<int> par, imp, aux;

    while (not p.empty())
    {
        if (p.top() % 2 != 0)
        {
            imp.push(p.top());
            p.pop();
        }
        else if (p.top() % 2 == 0)
        {
            par.push(p.top());
            p.pop();
        }
    }
    
    while (not imp.empty())
    {
        aux.push(imp.top());
        imp.pop();
    }
    while (not par.empty())
    {
        aux.push(par.top());
        par.pop();
    }
    cout<<aux;
    return aux;
}

int main()
{
    stack<int> p;

    while(cin>>p)
    {
        ordena(p);
    }
    
}