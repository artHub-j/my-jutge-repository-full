#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double d;
    cin >> d;
    if (d > 10000000)
    {
        int n = d;
        cout << floor(n) << " " << ceil(n) << " " << round(n) << endl;
    }   
    else
        cout << floor(d) << " " << ceil(d) << " " <<  round(d) << endl;
    
}