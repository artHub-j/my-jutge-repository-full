
#include <sstream>
using namespace std;

#include <iostream>
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
 void rec_postordre(node *inici, Clau &res) const;
 // Retorna el valor del node x (x = 2) segonms el recorregut del bst en postordre.
};

// Aquí va la implementació dels mètodes públics i privats

template <typename Clau>
void dicc<Clau>::rec_postordre(node *inici, Clau &res) const
{
	node *p(inici);
	node *pant(nullptr);
	
	while (p != nullptr) {
		pant = p;
		if (p->_esq != nullptr)
			p = p->_esq;
		else 
			break;
	}
	
	if (p->_dret != nullptr)
		res = p->_dret->_k;
	else 
		res = pant->_k;
}

template <typename Clau>
Clau dicc<Clau>::segona() const 
// Pre: El diccionari té com a mínim dues claus.
// Post: Retorna la segona clau.
{
	Clau res;
	
	rec_postordre(_arrel, res);

	return res;
}
