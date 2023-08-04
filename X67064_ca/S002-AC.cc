#include <iostream>
#include <sstream>
#include <vector>

using namespace std;
typedef unsigned int nat;

template <typename Clau>
class dicc {

  public:
    // Constructora per defecte. Crea un diccionari buit.
    dicc();

    // Destructora
    ~dicc();

    // Insereix la clau k en el diccionari. Si ja hi era, no fa res.
    void insereix(const Clau &k);

    // Retorna quants elements (claus) té el diccionari.
    nat quants() const;

    // Retorna la segona clau.
    // Pre: El diccionari té com a mínim 2 claus.
    Clau segona() const;

  private:
    struct node {
      Clau _k;      // Clau
      node* _esq;   // fill esquerre
      node* _dret;  // fill dret
      nat _n;       // Nombre de nodes del subarbre
      node(const Clau &k, node* esq = NULL, node* dret = NULL);
    };
    node *_arrel;

    static void esborra_nodes(node* m);
    static node* insereix_bst(node *n, const Clau &k, bool &ins);

    // Aquí va l’especificació dels mètodes privats addicionals
    void segona(node *p, vector<Clau> &l) const;
};

// Aquí va la implementació dels mètodes públics i privats

template <typename Clau>
void dicc<Clau>::segona(node *p, vector<Clau> &l) const
{ 
  if (p == NULL)
    return ;

  if (l.size() < 2) {
    segona(p->_esq, l);
    l.push_back(p->_k);
    segona(p->_dret, l);
  }

}

template <typename Clau>
Clau dicc<Clau>::segona() const 
{
  vector<Clau> l;
  segona(_arrel, l);
  // for (auto a: l)
  //   cout << a << " ";
  // cout << endl;
  return l[1];
}