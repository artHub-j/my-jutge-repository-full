#include <iostream>
#include <vector>

using namespace std;

void ordena_vect(int v[], int m)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = i; j < m; j++)
        {
            if (v[i] > v[j])
                swap(v[i], v[j]);
        }
    }
}

void freq(int v[], int n)
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
    int v[i];
    int n;
    int j = 0;
    while (i > 0 and cin >> n)
    {
        if (n <= 1000001000 and n >= 1000000000)
        {
            v[j] = n;
            i--;
            j++;
        }
    }
    int m = sizeof(v) / sizeof(v[0]);
    ordena_vect(v, m);
    freq(v, m);
}