#include <iostream>
using namespace std;

struct Racional
{
    int num, den;
};

Racional minim(const Racional &a, const Racional &b)
{
    Racional r;
    int n = a.num * b.den - a.den * b.num;
    if (n < 0)
        r = a;
    else
        r = b;
    return r;
}

int main()
{
    unsigned int n;
    cin >> n;

    Racional nums[n];
    for (unsigned int i = 0; i < n; ++i)
    {
        Racional r;
        char c;
        cin >> r.num >> c >> r.den;
        nums[i] = r;
    }

    Racional nums2[n];
    for (unsigned int i = 0; i < n; ++i)
    {
        Racional r;
        char c;
        cin >> r.num >> c >> r.den;
        nums2[i] = r;
    }

    for (unsigned int i = 0; i < n; ++i)
    {
        Racional r2 = minim(nums[i], nums2[i]);
        cout << r2.num << "/" << r2.den << endl;
    }
}