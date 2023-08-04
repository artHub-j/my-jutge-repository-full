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

void freq(vector<int> &v, int n)
{
    vector<bool> visited(n, false);
    for (int i = 0; i < n; i++)
    {

        if (visited[i] == true)
            continue;

        int count = 1;
        for (int j = i + 1; j < n; j++)
        {
            if (v[i] == v[j])
            {
                visited[j] = true;
                count++;
            }
        }
        cout << v[i] << " " << count << endl;
    }
}

int main()
{
    int i;
    cin >> i;
    vector<int> v;
    int n;
    while (i > 0 and cin >> n)
    {
        if (n <= 1000001000 and n >= 1000000000)
        {
            v.push_back(n);
            i--;
        }
    }
    ordena_vect(v);
    int m = v.size();
    freq(v, m);
}