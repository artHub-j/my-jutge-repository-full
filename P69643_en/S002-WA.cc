#include <iostream>
#include <stack>
#include<string>

using namespace std;

bool obrirTancar(char top ,char c)
/* Pre: */
/* Post: indica si el char top (que es el caracter que es troba al cap de la pila) i el char c
         formen un tancament correcte.
         ex: () o []    */
{
    bool correcte = false;
	if(top == '(' and c == ')') correcte = true;
	if(top == '[' and c == ']') correcte = true;

    return correcte;
}

bool sonParentesis(string cadena)
/*  Pre: */
/*  Post: si la cadena comença amb una obetura '(' o '[' llavors depenent del resultat de obrirTancar() s'indica si forma una cadena de parentesis correcta
          i es guarda en una pila auxiliar. 
          En cas de que començi per un tancament ')' o per ']' o la pila auxiliar es buidi s'indica que la cadena es incorrecte. */
{
	stack<char> aux;
    bool correcte = true;

    for (unsigned int i = 0; i < cadena.length(); i++)
    {
        if (cadena[i] == '(' or cadena[i] == '[')
        {
            aux.push(cadena[i]);
        }
        else if (cadena[i] == ')' or cadena[i] == ']')
        {
            if(aux.empty() or not obrirTancar(aux.top(), cadena[i])) correcte = false;
			else aux.pop();
        }
    
    }
    return correcte;
}

int main()
{
	string cadena;
    while (cin>>cadena)
    {
        if(sonParentesis(cadena)) cout<<cadena<<" is correct"<<endl;
	    else cout<<cadena<<" is incorrect"<<endl;
    }
}