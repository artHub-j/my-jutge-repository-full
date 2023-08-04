#include <vector>
#include <iostream>
#include <sstream>

using namespace std;
typedef unsigned int nat;

class graf {
  // Graf dirigit i no etiquetat.
  // Les arestes es guarden en multillistes d’adjacència en memòria dinàmica.
  public:
    // Constructora per defecte. Crea un graf buit de n vèrtexs.
    graf(nat n);

    // Destructora
    ~graf();

    // Retorna un vector amb els successors del vèrtex v
    vector<nat> successors(nat v) const;

    // Retorna un vector amb els predecessors del vèrtex v
    vector<nat> predecessors(nat v) const;

    void insereix(nat orig, nat dest);
    // Pre: orig i dest són menors que el número de vèrtexs
    // Post: Insereix una aresta que connecta des del vèrtex orig cap al vèrtex dest.
          // Si l’aresta ja existia no fa res.

  private:
    nat nv; // Nombre de vèrtexs
    struct node {
      nat orig; // Vèrtex origen 
      nat dest; // Vèrtex destí 
      node *seg_succ; // Punter al següent successor
      node *seg_pred; // Punter al següent predecessor
    };
    vector<node *> prim_succ; // Punters al primer successor de cada vèrtex.
                              // La llista de successors està ordenada.
    vector<node *> prim_pred; // Punters al primer predecessor de cada vèrtex.
                              // La llista de predecessors està ordenada.

    // Aquí va l’especificació dels mètodes privats addicionals
};

// Aquí va la implementació del mètode públic insereix i privats addicionals

void graf::insereix(nat orig, nat dest)
// Pre: orig i dest són menors que el número de vèrtexs
// Post: Insereix una aresta que connecta des del vèrtex orig cap al vèrtex dest.
// Si l’aresta ja existia no fa res.
{
  node *p = prim_succ[orig], *pant = nullptr;
  bool trobat = false;
  while (p != nullptr and p->dest <= dest and not trobat) {
    trobat = p->dest == dest;
    pant = p;
    p = p->seg_succ;
  }
  if (not trobat) {
    node *pnou = new node;
    pnou->orig = orig;
    pnou->dest = dest;
    if (pant == nullptr) {
      pnou->seg_succ = prim_succ[orig];
      prim_succ[orig] = pnou;
    } else {
      pnou->seg_succ = pant->seg_succ;
      pant->seg_succ = pnou;
    }
    p = prim_pred[dest];
    pant = nullptr;
    while (p != nullptr and p->orig <= orig) {
      pant = p;
      p = p->seg_pred;
    }
    if (pant == nullptr) {
      pnou->seg_pred = prim_pred[dest];
      prim_pred[dest] = pnou;
    } else {
      pnou->seg_pred = pant->seg_pred;
      pant->seg_pred = pnou;
    }
  }
}