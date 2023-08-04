#include <iostream>
#include <stack>
using namespace std;

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
            while (not s.empty())
            {
                cout<<s.top();
                if (s.size() > 1) cout<<" ";
                else cout<<endl;
                s.pop();
            }
            
        }
    }
}