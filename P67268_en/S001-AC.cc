/*
Write a program that reads sequences of integer numbers, and prints each one reversing the order of its elements.

Input

Input consists of several sequences. Each sequence consists of a natural number n, followed by n integer numbers.

Output

Print each sequence in reverse order in a line.
*/

//Inversió de seqüències
#include <iostream>
#include <vector>
using namespace std;
 
 
//Pre: Llegeix una seqücncia
//Post: Escriu la seqücncia invertida
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
