#include <iostream>
#include <queue>
#include <vector>
#include <sstream>
using namespace std;

void imprimir_base(const vector<queue<string>> &v)
{
    vector<queue<string>> base = v;
    for (unsigned int i = 0; i < base.size(); i++)
    {
        cout << "queue "<< i + 1 << ":";
        if (base[i].size() > 0) cout << " ";
        while (not base[i].empty())
        {
            cout << base[i].front();
            if (base[i].size() > 1) cout << " ";
            base[i].pop();
        }
        cout << endl;
    }
}

void imprimir(const queue<string> &q)
{
    queue<string> q2 = q;
    while(not q2.empty())
    {
        cout << q2.front() << endl;
        q2.pop();
    }
}

int main()
{
    int n;
    cin >> n;
    cin.ignore();
    vector<queue<string>> base;
    while (n > 0)
    {
        string linia;
        queue<string> q;
        getline(cin, linia);
        istringstream ss(linia);
        string s;
        while (ss >> s)
        {
            q.push(s);
        }
        base.push_back(q);
        n--;
    }
    cin.ignore();
    string linia;
    queue<string> aux;
    while (getline(cin, linia))
    {
        istringstream ss(linia);
        int i;
        string s, nom;
        ss >> s;
        if (s == "LEAVES")
        {
            ss >> i;
            if (not base[i-1].empty())
            {
                aux.push(base[i-1].front());
                base[i-1].pop();
            }
        }
        if (s == "ENTERS")
        {
            ss >> nom;
            ss >> i;
            base[i-1].push(nom);
            //cout << s << " " << nom << " " << i << endl;
        }
    }
    cout << "DEPARTS"<< endl << "-------" << endl;
    imprimir(aux);
    cout << endl << "FINAL CONTENTS" << endl << "--------------" << endl;
    imprimir_base(base);
}