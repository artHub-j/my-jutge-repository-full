#include <iostream>
#include <vector>

using namespace std;

void ordena_vect(vector<int> &v)
{
    int m = v.size();
    for (int i = 0; i < m; i++)
    {
        for (int j = i; j < m; j++)
        {
            if (v[i] > v[j])
                swap(v[i], v[j]);
        }
    }
}

vector<int> elimina_repetits(vector<int> &v)
{
    vector<int> w(v);
    vector<int>::iterator i = w.begin();
    while (i != w.end())
    {
        vector<int>::iterator f = i;
        ++f;
        while (f != w.end())
        {
            if (*f == *i)
                f = w.erase(f);
            else
                ++f;
        }
        ++i;
    }
    return w;
}

int freq(vector<int> &v, int &v_i)
{
    int r = 0;
    for (unsigned int i = 0; i < v.size(); i++)
    {
        if (v[i] == v_i)
            r++;
    }
    return r;
}

int main()
{
    int i;
    cin >> i;
    vector<int> v;
    int n;
    while (cin >> n and i > 0)
    {
        if (n <= 1000001000 and n >= 1000000000)
        {
            v.push_back(n);
            i--;
        }
    }
    ordena_vect(v);
    vector<int> w = elimina_repetits(v);
    for (unsigned int i = 0; i < w.size(); i++)
    {
        cout << w[i] << " : " << freq(v, w[i]) << endl;
    }
}