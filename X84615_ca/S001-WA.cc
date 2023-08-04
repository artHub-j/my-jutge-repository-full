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
      char _c;    // Símbol posició i-èssima de la clau
      node* _esq; // Fill esquerra, apunta a símbols mateixa posició formant un BST
      node* _cen; // Fill central, apunta a símbols següent posició
      node* _dre; // Fill dret, apunta a símbols mateixa posició formant un BST
      node(const char &c, node* esq = NULL, node* cen = NULL, node* dre = NULL);
    };
    node* _arrel;

    static void esborra_nodes(node* t);
    static node* insereix(node *t, nat i, const string &k);

    // Aquí va l’especificació dels mètodes privats addicionals
    static void busca_longitud(node *p, int prof, vector<nat> &res);
    static void busca_max_longitud(node *p, int prof, int &max);
};

// Aquí va la implementació del mètode públic freq_longituds i privats addicionals

void dicc::busca_max_longitud(node *p, int prof, int &max)
{
  if (p) {
    busca_max_longitud(p->_esq, prof, max);

    if (p->_c == '#') {
      if (max < prof)
        max = prof;
    }

    busca_max_longitud(p->_cen, prof + 1, max); 
    busca_max_longitud(p->_dre, prof, max); 
  }
}


void dicc::busca_longitud(node *p, int prof, vector<nat> &res)
{
  if (p) {
    busca_longitud(p->_esq, prof, res);

    if (p->_c == '#') {
      ++res[prof];
    }

    busca_longitud(p->_cen, prof + 1, res); 
    busca_longitud(p->_dre, prof, res); 
  }
}

vector<nat> dicc::freq_longituds() const
// Pre: True
// Post: Retorna un vector amb les freqüències de les longituds de les claus.
// La mida del vector és igual a la longitud de la clau més llarga més un. 
{
  int max = 0;
  busca_max_longitud(_arrel, 0, max);
  vector<nat> res(max + 1, 0);

  busca_longitud(_arrel, 0, res);

  return res;
}