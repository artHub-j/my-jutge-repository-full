#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    cout << n/3600 << " " << (n/60)%60 << " " << n%60 << endl;
}