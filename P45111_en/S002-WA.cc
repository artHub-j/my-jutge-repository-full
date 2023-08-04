#include <iostream>
#include <stack>
using namespace std;

void investmentStack(stack <int> &s)
/*  Pre: */
/*  Post: reverse sequences of natural numbers in a stack */
{
    if (s.empty()) cout<<endl;
    while(not s.empty())
    {
        cout<<s.top();
        if (s.size() > 1) cout<<"";
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
            investmentStack(s);
        }
    }
}
