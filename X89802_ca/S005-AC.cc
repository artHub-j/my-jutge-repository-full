#include <iostream>
#include <sstream>
#include <list>
#include <vector>

using namespace std;
typedef unsigned int nat;

class dicc {
  // Taula de dispersió sinònims encadenats indirectes
  // Les llistes de sinònims estan ordenades per clau
  public:
    // Constructora per defecte. Crea un diccionari buit.
    dicc();

    // Destructora
    ~dicc();

    // Retorna quants elements (claus) té el diccionari.
    nat quants() const;

    // Impressió per cout de totes les claus del diccionari segons l’ordre
    // en que estan a cadascuna de les llistes encadenades indirectes
    void print() const;

    // Pre: Cert
    // Post: Insereix la clau k en el diccionari. Si ja hi era, no fa res.
    void insereix(const int &k);

    // Pre: El diccionari res està buit
    // Post: Omple res amb la intersecció entre el p.i. i d2
    void interseccio(const dicc &d2, dicc &res) const;

  private:
    struct node_hash {
      int _k;           // Clau
      node_hash* _seg;
    };
    node_hash **_taula; // Taula amb punters a les llistes de sinònims
    nat _M;             // Mida de la taula
    nat _quants;        // Nº d’elements guardats al diccionari

    static long const MULT = 31415926;

    // Calcula un valor de dispersió entre 0 i LONG_MAX a partir de k
    static long h(int k);

    // Destrueix la llista de nodes apuntats per p
    static void esborra_nodes(node_hash *p);

    // Aquí va l’especificació dels mètodes privats addicionals
    static void list_of_dicc(list<int> &l, const dicc &d);
    static void intersec(node_hash *p, node_hash *p2, dicc &res);
    void esborra(const int &k);
};

// Aquí va la implementació dels mètodes públics insereix, interseccio i
// dels mètodes privats addicionals

void dicc::esborra(const int &k)
{
  int i = h(k) % _M;
	node_hash *p = _taula[i], *ant = NULL;
	bool trobat = false;
	while (p != NULL and not trobat) {
		if (p->_k == k) {
			trobat = true;
		}
		else {
			ant = p;
			p = p->_seg;
		}
	}
	if (trobat) {
		if (ant == NULL) {
			_taula[i] = p->_seg; // Era el primer
		}
		else {
			ant->_seg = p->_seg;
		}
		delete (p);
		--_quants;
	}
}

void dicc::insereix(const int &k)
// Pre: Cert
// Post: Insereix la clau k en el diccionari. Si ja hi era, no fa res.
{
  int i = h(k) % _M;
  node_hash *ant = NULL;
  node_hash *p(_taula[i]);

  bool trobat = false;
  
  while (p != NULL and p->_k <= k) {
    if (k != p->_k) {
      ant = p;
    }
    else {
      --_quants;
    }
    p = p->_seg;
  }

  if (not trobat) {
    node_hash *nou = new node_hash;
    nou->_k = k;
    if (ant == NULL) {
      _taula[i] = nou;
    }
    else {
      ant->_seg = nou;
    }
    nou->_seg = p;
    ++_quants;
  }
}

void dicc::intersec(node_hash *p, node_hash *p2, dicc &res)
{
  if (p == NULL)
    return ;

  if (p2 == NULL)
    return ;

  while (p != NULL and p2 != NULL) {
    if (p->_k < p2->_k) {
      p = p->_seg;
    }
    else if (p2->_k < p->_k) {
      p2 = p2->_seg;
    }
    else { // p->_k == p2->_k
      res.insereix(p2->_k);
      p = p->_seg;
      p2 = p2->_seg;
    }
  }
}

void dicc::interseccio(const dicc &d2, dicc &res) const
// Pre: El diccionari res està buit
// Post: Omple res amb la intersecció entre el p.i. i d2
{
  for (int i = 0; i < _M; ++i)
    intersec(_taula[i], d2._taula[i], res);
}
