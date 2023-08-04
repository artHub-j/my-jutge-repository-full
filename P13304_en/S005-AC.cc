#include <iostream>
#include <sstream>
#include <stack>
using namespace std;

int main()
{
    string linia;
    while (getline(cin, linia))
    {
        istringstream ss(linia);
        stack<int> parell;
        stack<int> senar;
        int n;
        while (ss >> n)
        {
            if (n%2 == 0)
                parell.push(n);
            else 
                senar.push(n);
        }
        while (not parell.empty())
        {
            cout << parell.top();
            parell.pop();
            if (parell.size() >= 1 or not senar.empty()) cout << " ";
        }
        while (not senar.empty())
        {
            cout << senar.top();
            senar.pop();
            if (senar.size() >= 1) cout << " ";
        }
        cout << endl;

    }

}