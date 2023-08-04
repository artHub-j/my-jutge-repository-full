// Add or remove includes
#include <iostream>
#include <string>
#include <stack>
#include <sstream>
#include <vector>

using namespace std;

int numElementsPerSota(stack<int> p)
// PRE: p es una pila auxiliar. Parametro por copia.
// POST: Modfica p. Pop de p hasta que haya un 0 o 1.
//       Devuleve el numero de elementos por debajo de 0 o 1.
//       El numero de elementos son los elementos restantes (p.size())
//       despues de haber hecho los respectivos pop.
{
    if (p.empty())
        return 0;

    int x = p.top();
    p.pop();

    if (x == 0 or x == 1) {
        return p.size();
    }

    return numElementsPerSota(p);
}

void eliminarCeroParUnoImpar(stack<int>& s, int cont) {
    // Caso base
    if (s.empty()) {
        return;
    }

    int elem = s.top();
    cont = numElementsPerSota(s); // contar el numero de elementos por debajo de 0 o 1 en s.
    s.pop();

    // Eliminar 0 si tenía un número par de elementos por debajo
    if (elem == 0 and cont % 2 == 0) {
        eliminarCeroParUnoImpar(s, cont);
        return;
    }

    // Eliminar 1 si tenía un número impar de elementos por debajo
    if (elem == 1 and cont % 2 != 0) {
        eliminarCeroParUnoImpar(s, cont);
        return;
    }

    // Si no se elimina el elemento, se inserta de nuevo en la pila
    eliminarCeroParUnoImpar(s, cont);
    s.push(elem);
}

stack<int> remove01(stack<int> s) {
    eliminarCeroParUnoImpar(s, 0);
    return s;
}