#include <iostream>
#include <stack>

#include <cstdlib>
 #include <iostream>
 using namespace std;
 typedef unsigned int nat;
 
template <typename T>
class Abin {
   public:
     Abin(): _arrel(NULL) {};
     // Pre: cert
     // Post: el resultat és un arbre sense cap element
     Abin(Abin<T> &ae, const T &x, Abin<T> &ad);
     // Pre: cert
     // Post: el resultat és un arbre amb un element i dos subarbres
 
     // Les tres grans
     Abin(const Abin<T> &a);
     ~Abin();
     Abin<T>& operator=(const Abin<T>& a);
 
     // operador << d’escriptura
     template <class U> friend std::ostream& operator<<(std::ostream&, const Abin<U> &a);
 
     // operador >> de lectura
     template <class U> friend std::istream& operator>>(std::istream&, Abin<U> &a);

     Abin(int n);
 
   private:
     struct node {
       node* f_esq;
       node* f_dret;
       T info;
     };
     node* _arrel;
     static node* copia_nodes(node* m);
     static void esborra_nodes(node* m);
     static void print_nodes(node* m, ostream &os, string d1);
    
    node* crea(nat i, nat n);
};

template <typename T>
Abin<T>::Abin(int n) 
{
    _arrel = crea(1, n);
}

template <typename T>
typename Abin<T>::node* Abin<T>::crea(nat i, nat n)
{
    node *p(nullptr);
    if (i <= n)
    {
      p = new node;
      p->info = i;
      p->f_esq = crea(i + 1, n);
      p->f_dret = crea(i + 1, n);
    }

    return p;
}