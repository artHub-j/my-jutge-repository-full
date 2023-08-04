#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main()
{
    stack<char> p;
    vector<string> base;
    string s;
    for (int i = 0; cin >> s; i++)
    {
        base.push_back(s); //Afegim l'string format pels parentesis i claudators.
        /*
        Per comprovar que la parentització es correcte:
            1. Afegim a la pila el caràcter de la posició j de l'string s. 
            2. Si s[j] == clau tancada i p.top() == clau oberta és correcte (Els parèntesis/claudàtors obren i tanquen en l'ordre correcte). 
               Per tant, retirem la clau de la pila.
            3. En cas contrari, incorrecte. No fem res i mantenim la clau dins la pila.
        */
        for (unsigned int j = 0; j < s.size(); j++) //Iteració "A".
        {
            if (s[j] == ')' and p.top() == '(')
            {
                p.pop();
            }
            else if (s[j] == ']' and p.top() == '[')
            {
                p.pop();
            }
            else
            {
                p.push(s[j]);
            }
        }

        cout << base[i];
        /*
        Si la pila és buida, vol dir que per a cada crida de l'iteració "A" hem anat buidant l'stack s, ja que cada vegada que
        es treia un caracter de la pila volia dir que la parametritzacio del tipus '()' i '[]' tenia l'ordre correcte per tancar i obrir.

        En cas contrari (pila amb elements) la parametrirtzació és incorrecte.
        */
        if (p.empty())
        {
            cout << " is correct";
        }
        else
        {
            cout << " is incorrect";
        }
        //Buidem la pila per complet, per reutilitzar-la en la següent crida del bucle.
        while (not p.empty())
        {
            p.pop();
        }
        cout << endl;
    }
}