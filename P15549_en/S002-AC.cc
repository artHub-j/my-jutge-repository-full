#include <iostream>
#include <vector>
using namespace std;

void bubble_sort(vector<double> &v)
{
    int last = v.size() - 1;
    while (last > 0)
    {
        int last_swap = 0;
        for (int i = 0; i < last; ++i)
        {
            if (v[i] > v[i + 1])
            {
                swap(v[i], v[i + 1]);
                last_swap = i;
            }
        }
        last = last_swap;
    }
}
