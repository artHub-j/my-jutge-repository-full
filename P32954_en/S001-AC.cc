#include <iostream>
#include <algorithm>
using namespace std;


void sort3(int& a, int& b, int& c)
{// Insert arr[1]
    if (b < a)
       swap(a, b);
 
    if (c < b) {
       swap(b, c);
       if (b < a)
          swap(b, a);
    }
}


int main() {
  int x, y, z;
  while (cin >> x >> y >> z) {
    sort3(x, y, z);
    cout << x << ' ' << y << ' ' << z << endl;
  }
}
