#include <iostream>
#include <vector>
using namespace std;
typedef unsigned int nat;

class dicc {
  public:
    // Constructora per defecte. Crea un diccionari buit.
    dicc();

    // Destructora
    ~dicc();

    // Insereix la clau k en el diccionari. Si ja hi era, no fa res.
    void insereix(const string &k);

    vector<nat> freq_longituds() const;
    // Pre: True
    // Post: Retorna un vector amb les freqüències de les longituds de les claus.
    // La mida del vector és igual a la longitud de la clau més llarga més un. 

  private:
    struct node {
      char _c;   // Símbol posició i-èssima de la clau
      node* _pf; // Primer fill, apunta a símbols de la següent posició
      node* _sg; // Següent germà, apunta a símbols de la mateixa posició
      node(const char &c, node* pf = NULL, node* sg = NULL);
    };
    node* _arrel;

    static void esborra_nodes(node* t);
    static node* insereix(node *t, nat i, const string &k);

    // Aquí va l’especificació dels mètodes privats addicionals
    static void busca_max_longitud(node *p, int prof, int &max);
    static void busca_longituds(node *p, int prof, vector<nat> &res);

};

// Aquí va la implementació del mètode públic freq_longituds i privats addicionals

void dicc::busca_max_longitud(node *p, int prof, int &max)
{
  if (p) {
    busca_max_longitud(p->_pf, prof + 1, max);

    if (p->_c == '#') {
      if (max < prof) 
        max = prof;
    }

    busca_max_longitud(p->_sg, prof, max);
  }
}

void dicc::busca_longituds(node *p, int prof, vector<nat> &res)
{
  if (p) {
    busca_longituds(p->_pf, prof + 1, res);

    if (p->_c == '#') {
      ++res[prof];
    }

    busca_longituds(p->_sg, prof, res);
  }
}


vector<nat> dicc::freq_longituds() const
// Pre: True
// Post: Retorna un vector amb les freqüències de les longituds de les claus.
// La mida del vector és igual a la longitud de la clau més llarga més un. 
//on a cada posició i del vector resultat conté la freqüència o quantitat de claus de longitud i del diccionari.
{
  vector<nat> res;
  int max = 0;
  busca_max_longitud(_arrel, 0, max);

  if (max == 0) {
    res = vector<nat>();
  }
  else {
    res = vector<nat>(max + 1, 0);
    busca_longituds(_arrel, 0, res);
  }
  return res;
}
