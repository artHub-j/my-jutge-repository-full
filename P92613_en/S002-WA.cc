#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double d;
    cin >> d;
    if (d > 100000)
        cout << d << " " << d << " " << d << endl;
    else
        cout << floor(d) << " " << ceil(d) << " " <<  round(d) << endl;
    
}