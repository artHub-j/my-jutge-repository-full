#include <iostream>
#include <sstream>
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
    static void suma_elem(node *p, int &sum);
    void duplica_amb_sumes(node *p, node *pant, int &suma);

};

// Aquí va la implementació del mètode duplica_amb_sumes i dels privats addicionals

template <typename T>
void pila<T>::suma_elem(node *p, int &sum) 
{
  if (p == nullptr)
    return; 
    
  sum += p->info;

  suma_elem(p->seg, sum);
}

template <typename T>
void pila<T>::duplica_amb_sumes(node *p, node *pant, int &suma) 
{
  if (p == nullptr)
    return ;

  node *nou = new node;
  nou->info = suma;

  if (pant == nullptr) {
    _cim = nou;
    nou->seg = p;
    pant = nou;
  } 
  else {
    pant->seg = nou;
    nou->seg = p;
    pant = nou;
    // if (p->seg == nullptr) {
    //   pant = p;
    //   p->seg = nou;
    //   nou->seg = nullptr;
    //   p = nou;
    // }
  }
  ++_mida;

  duplica_amb_sumes(p->seg, pant->seg, suma -= p->info);
}

template <typename T>
void pila<T>::duplica_amb_sumes()
{
  int suma = 0;
  suma_elem(_cim, suma);
  duplica_amb_sumes(_cim, nullptr, suma);
}