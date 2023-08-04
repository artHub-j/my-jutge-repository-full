#include <iostream>
#include <vector>
using namespace std;
typedef unsigned int nat;
 
template <typename T>
class pila { // pila en memòria dinàmica
public:
    pila();
    // Crea pila buida
 
    ~pila();
    // Destrueix el p.i.
 
    pila(const vector<int> &v);
    // Crea pila amb els elements de v amb el mateix ordre.
 
    nat longitud() const;
    // Retorna el nombre d’elements del p.i.
 
     void mostra() const;
    // Mostra el p.i. pel canal estàndard de sortida.
 
    void duplica_amb_sumes();
    // Pre: true
    // Post: S’han duplicat els elements de la pila, a sobre de cada element hi ha un
    // nou element que conté la suma dels elements restants de la pila original
 
private:
    struct node {
        T info;
        node* seg;
    };
    node* _cim; // Apunta al cim de la pila
    nat _mida;  // Nombre d’elements de la pila
 
    // Aquí va l’especificació dels mètodes privats addicionals
     void crea();
     int suma_tot(node *p);
};
 
// Aquí va la implementació del mètode duplica_amb_sumes i dels privats addicionals
template <typename T>
void pila<T>::duplica_amb_sumes()
{
    crea();
}

template <typename T>
void pila<T>::crea()
{
  node *act(_cim);
  int sum_tot = suma_tot(_cim);

  if (_mida == 1) {
    node *suma = new node;
    suma->info = sum_tot;
    suma->seg = act;
    _cim = suma;
  }
  else if (_mida != 0) {
    node *ant(nullptr);
    while (act != nullptr) 
    {
        node *suma = new node;
        if (ant == nullptr) {
        suma->info = sum_tot;
        suma->seg = act;
        _cim = suma;
        ant = act;
        act = act->seg;
        }
        else {
        suma->info = suma_tot(act);
        suma->seg = act;
        ant->seg = suma;
        ant = act;
        }

        _mida++;
        act = act->seg;
    }
  }
}

template <typename T>
int pila<T>::suma_tot(node *p)
{
    int suma = 0;
    while (p != nullptr) {
        suma += p->info;
        p = p->seg;
    }
    return suma;
}

template <typename T>
int pila<T>::suma_tot(node *p)
{
    int suma = 0;
    while (p != nullptr) {
        suma += p->info;
        p = p->seg;
    }
    return suma;
}
