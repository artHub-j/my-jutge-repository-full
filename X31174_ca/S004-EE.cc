// Add or remove includes
#include <iostream>
#include <string>
#include <stack>
#include <sstream>
#include <vector>

using namespace std;

int numElementsPerSota(stack<int> p) {
    int count = 0;
    while (!p.empty()) {
        int x = p.top();
        if (x == 0 or x == 1) {
            break;
        }
        p.pop();
        count++;
    }
    return count;
}

void eliminarCeroParUnoImpar(stack<int>& s, int cont) {
    stack<int> temp;
    while (!s.empty()) {
        int elem = s.top();
        s.pop();
        cont += numElementsPerSota(s);
        if ((elem == 0 and cont % 2 == 0) or (elem == 1 and cont % 2 != 0)) {
            continue;
        }
        temp.push(elem);
    }
    while (!temp.empty()) {
        s.push(temp.top());
        temp.pop();
    }
}

stack<int> remove01(stack<int> s) {
    eliminarCeroParUnoImpar(s, 0);
    return s;
}