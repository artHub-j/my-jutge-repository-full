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
 
     bool compleix_suma_fills() const;
     // Pre: true
     // Post: retorna si compleix la propietat ’Suma dels fills’:
     // Per tot node el seu valor és igual a la suma dels valors
     // dels nodes (arrels) del fill esquerre i del fill dret.
 
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
 
     // Aquí va l’especificació dels mètodes privats addicionals
     static bool compleix_suma_fills(node *p);
};

template <typename T>
bool Abin<T>::compleix_suma_fills() const
{
    return compleix_suma_fills(_arrel);
}

template <typename T>
bool Abin<T>::compleix_suma_fills(node *p) 
{
    bool compleix(true);

    if (p != nullptr)
    {
        int suma(0);
        node *act(p);

        if (act->f_esq == nullptr and act->f_dret == nullptr)
            suma = p->info;

        if (act->f_esq != nullptr)
          suma += act->f_esq->info;
        if (act->f_dret != nullptr)
          suma += act->f_dret->info;

        compleix = suma == p->info;
          
        compleix = compleix and compleix_suma_fills(p->f_esq) and compleix_suma_fills(p->f_dret);
    }

    return compleix;
}