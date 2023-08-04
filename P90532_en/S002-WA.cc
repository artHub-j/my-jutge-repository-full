#include <typeinfo>

#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Province
{
    string name;
    string capital;
    int population;
    int area;
    double gdp;
};

struct Country
{
    string name;
    string capital;
    vector<Province> provs;
};

typedef vector<Country> Countries;
double gdp(const Countries &p, char c, double d)
{
    int sum = 0;
    for (auto &provinces : p)
    {
        if (provinces.name[0] == c)
        {
            for (auto &gdps : provinces.provs)
            {
                if (gdps.population > d)
                    sum = sum + gdps.gdp;
            }
        }
    }
    return sum;
}

int main()
{
    int n;
    cin >> n;
    Countries p(n);
    for (int i = 0; i < n; ++i)
    {
        int np;
        cin >> p[i].name >> p[i].capital >> np;
        p[i].provs = vector<Province>(np);
        for (int j = 0; j < np; ++j)
        {
            cin >> p[i].provs[j].name >> p[i].provs[j].capital >>
                p[i].provs[j].population >> p[i].provs[j].area >>
                p[i].provs[j].gdp;
        }
    }
    cout << gdp(p, 'A', 10) << endl;
    cout << gdp(p, 'A', 20) << endl;
    cout << gdp(p, 'A', 30) << endl;
    cout << gdp(p, 'A', 40) << endl;
    cout << gdp(p, 'E', 10) << endl;
    cout << gdp(p, 'E', 20) << endl;
    cout << gdp(p, 'E', 30) << endl;
    cout << gdp(p, 'E', 40) << endl;
    cout << gdp(p, 'C', 40) << endl;
}