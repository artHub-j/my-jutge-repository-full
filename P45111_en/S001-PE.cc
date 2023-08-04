#include <iostream>
#include <stack>
using namespace std;

void investmentStack(stack <int> &s)
{
    while(not s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
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
