#include <sstream>
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

    void fusiona(const pila<T> &p2);
    // Pre: Les piles del p.i. i p2 estan ordenades de menor a major
    // Post: Al p.i. se li han afegit els elements de p2 ordenadament. p2 no es modifica

  private:
    struct node {
      T info;
      node* seg;
    };
    node* _cim; // Apunta al cim de la pila
    nat _mida;  // Nombre d’elements de la pila

    // Aquí va l’especificació dels mètodes privats addicionals
};

// Aquí va la implementació del mètode públic fusiona i privats addicionals

template <typename T>
void pila<T>::fusiona(const pila<T> &pila2)
// Pre: Les piles del p.i. i p2 estan ordenades de menor a major
// Post: Al p.i. se li han afegit els elements de p2 ordenadament. p2 no es modifica
{
  node *p(_cim), *pant(nullptr), *p2(pila2._cim);

  while (p != nullptr and p2 != nullptr) {
    node *nou = new node;
    nou->info = p2->info;
    if (pant == nullptr and p->info > p2->info) { // Afegir al principi.
      _cim = nou;
      nou->seg = p;
      pant = p;
      p2 = p2->seg;
    }
    else {
      if (p->seg == nullptr and p->info < p2->info) { // Afegir al final.
        p->seg = nou;
        nou->seg = nullptr;
        p2 = p2->seg;
      }
      else if (p->seg != nullptr and p->info > p2->info) {
        pant = pant->seg;
        nou->seg = p;
        pant->seg = nou;
        p2 = p2->seg;
      }
    }
    ++_mida;
    pant = nou;
    p = p->seg;
  }
}