/*
Write a program that reads sequences of integer numbers, and prints each one reversing the order of its elements.

Input

Input consists of several sequences. Each sequence consists of a natural number n, followed by n integer numbers.

Output

Print each sequence in reverse order in a line.
*/

//Inversi� de seq��ncies
#include <iostream>
#include <vector>
using namespace std;
 
 
//Pre: Llegeix una seq�cncia
//Post: Escriu la seq�cncia invertida
int main() {
        int n;
        while (cin >> n) {
                vector<int> v(n);
                for (int i = 0; i < n; ++i) {
                        cin >> v[i];
                }
                bool primer = true;
                for (int i = n-1; i >= 0; --i) {
                        if (not primer) cout << ' ';
                        else primer = false;
                        cout << v[i];
                }
                cout << endl;
        }
}
