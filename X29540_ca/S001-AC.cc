#include <iostream>
#include <vector>
using namespace std;
typedef unsigned int nat;

template <typename Clau>
class dicc {
public:
 dicc() : _arrel(NULL) {};
 // Pre: Cert
 // Post: El resultat és un dicc sense cap element

 ~dicc();
 // Pre: Cert
 // Post: El dicc ha estat destruït

 pair<Clau, char> insereix(const Clau &k);
 // Pre: Cert
 // Post: La clau k s’ha inserit en el diccionari si no hi era. Retorna la clau dels nodes
 // visitats a on hi ha el desequilibri més proper a les fulles i un caràcter amb el seu
 // tipus de desequilibri: ’E’: Esquerre, ’D’: Dret, ’ ’: No s’ha trobat cap desequilibri

private:
 struct node {
   Clau _k;      // Clau
   node* _esq;   // fill esquerre
   node* _dret;  // fill dret
   nat _h;       // Altura del subarbre
 };
 node *_arrel;

 static void esborra_nodes(node* m);

 // Aquí va l’especificació dels mètodes privats addicionals
 int altura (node * n);
 int factor_equilibri (node * n);
 node* insereix_bst(node *n, const Clau &k, pair<Clau, char> &res);
};

template <typename Clau>
int dicc<Clau>::altura (node * n)
{
	if (n == nullptr)
		return 0;
	return n->_h ;
}

template <typename Clau>
int dicc <Clau>:: factor_equilibri (node * n)
{
	if (n == nullptr)
		return 0;
	return altura (n->_dret) - altura (n ->_esq );
}

template <typename Clau>
typename dicc<Clau>::node* dicc<Clau>::insereix_bst(node *n, const Clau &k, pair<Clau, char> &res)
{
	// 1. Fem la inserció a un BST normal
	if (n == nullptr ) {
		n = new node;
		n->_k = k;
		n->_h = 1;
		n->_esq = nullptr;
		n->_dret = nullptr;
	}
	else if (k < n->_k)
		n->_esq = insereix_bst (n->_esq , k , res);
	else if (k > n->_k)
		n->_dret = insereix_bst (n->_dret , k , res);
	// else 
	// 	return n;
	
	n->_h = max (altura (n->_esq) , altura (n->_dret)) + 1;
	
	int fe = factor_equilibri(n);
	
	if (res.second == ' ') {
		if (fe > 1) {
			res.first = n->_k;
			res.second  = 'D';
		}
		if (fe < -1) {
			res.first = n->_k;
			res.second = 'E';
		}
	}

	return n;
};

// Aquí va la implementació dels mètodes públics i privats
template <typename Clau>
pair<Clau, char> dicc<Clau>::insereix(const Clau &k)
{
	pair<Clau, char> res;
	res.second = ' ' ;
	_arrel = insereix_bst(_arrel, k, res);
	return res;
}
