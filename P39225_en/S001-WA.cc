#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int i;
    cin >> i;
    int n;
    vector<int> v;
    while (cin >> n and n != -1)
    {
        v.push_back(n); 
    }
    cout << "At the position " << i << " there's a(n) " << v[i-1] << "." << endl;
}