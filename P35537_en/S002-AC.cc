#include <iostream>
using namespace std;


bool is_increasing(int n)
/*  Pre: */
/*  Post: retorna True o False segons si n es creixent o decreixent. */
/*  Fita: */
{
    if (n <= 9) return true;
    else if (n%10 < (n/10)%10) return false;
    return is_increasing(n/10);
}


int main() {
    int n;
    while (cin >> n) cout << (is_increasing(n) ? "true" : "false") << endl;
}