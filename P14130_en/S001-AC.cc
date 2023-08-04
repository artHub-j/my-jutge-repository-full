#include <iostream>
#include <vector>

using namespace std;

void imprimir(const vector<int> &v)
{
    for (unsigned int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main()
{
    int n;
    vector<int> v;
    cin >> n;
    while (n > 0)
    {
        int e;
        cin >> e;
        v.push_back(e);
        n--;
    }

    //imprimir(v);

    int ult = v[v.size()-1];
    int sum = 0;
    for (unsigned int i = 0; i < v.size()-1; i++)
    {   
        if (v[i] == ult) sum++;
    }
    cout << sum << endl;
}