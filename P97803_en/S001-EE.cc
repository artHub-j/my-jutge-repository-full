#include <iostream>
#include <stack>
#include <vector>
#include <sstream>
#include <limits>

using namespace std;

void print_stack(vector<stack<string>> &v)
{
    vector<stack<string>> llibreria = v;
    for (int i = 0; i < llibreria.size(); ++i)
    {
        cout << "Stack " << i + 1 << ": ";
        while (not llibreria[i].empty())
        {
            cout << llibreria[i].top();
            if (llibreria[i].size() > 1)
                cout << " ";
            llibreria[i].pop();
        }
        cout << endl;
    }
}

int main()
{
    vector<stack<string>> llibreria;
    string linia;
    int n;
    cin >> n;
    cin.ignore();
    llibreria.reserve(n);

    while (getline(cin, linia))
    {
        stack<string> llibres;
        string elem;
        stringstream ss(linia);
        while (ss >> elem)
            llibres.push(elem);
        llibreria.push_back(llibres);
        --n;
        if (n == 0)
            break;
    }

    // print_stack(llibreria);

    cin.ignore();
    string op;
    while (cin >> op)
    {
        // cout << op << " ";
        unsigned int id;
        if (op == "LOAN")
        {
            cin >> id;
            // cout << id - 1 << endl;
            if (id < llibreria.size() and not llibreria[id - 1].empty())
                llibreria[id - 1].pop();
        }
        else if (op == "RETURN")
        {
            string nouLlibre;
            cin >> nouLlibre;
            cin >> id;
            // cout << nouLlibre << " " << id - 1 << endl;
            if (id < llibreria.size())
                llibreria[id - 1].push(nouLlibre);
        }
    }

    print_stack(llibreria);
}
