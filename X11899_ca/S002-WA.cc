#include <iostream>
#include <sstream>
#include <vector>
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

    void insereix(nat orig, nat dest);
    // Pre: orig i dest són més petits que el número de vèrtexs
    // Post: Insereix una aresta que connecta des del vèrtex orig cap al vèrtex dest.
    // Si l’aresta ja existia no fa res.

    vector<nat> successors(nat v) const;
    // Pre: v és més petit que el número de vèrtexs
    // Post: Retorna un vector amb els successors del vèrtex v

    vector<nat> predecessors(nat v) const;
    // Pre: v és més petit que el número de vèrtexs
    // Post: Retorna un vector amb els predecessors del vèrtex v

    void elimina(nat orig, nat dest);
    // Pre: orig i dest són més petits que el número de vèrtexs
    // Post: Elimina una aresta que connecta des del vèrtex orig cap al vèrtex dest.
    // Si l’aresta no existia no fa res.

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
    void delete_node(node*& p, int val);
};

// Aquí va la implementació del mètode elimina i privats addicionals

void graf::delete_node(node*& p, int val)
{

    // Check if list is empty or we
    // reach at the end of the
    // list.
    if (p == NULL) {
        cout << "Element not present in the list";
        return;
    }
    // If current node is the node to be deleted
    if (p->orig == val) {
        node* t = p;
        p = p->seg_succ; // If it's start of the node head
                           // node points to second node
        delete (t); // Else changes previous node's link to
                    // current node's link
        return;
    }
    delete_node(p->seg_succ, val);
}

void graf::elimina(nat orig, nat dest)
{
  node *p = prim_succ[orig], *pant = nullptr;
  bool trobat = false;
  while (p != nullptr and p->dest <= dest and not trobat) {
    trobat = p->dest == dest;
    if (trobat)
      break;
    pant = p;
    p = p->seg_succ;
  }

  if (trobat) 
  {
    node *p2 = prim_pred[dest], *pant2 = nullptr;
    while (p2 != nullptr and p2->orig <= orig) {
      if (p2->orig == orig)
        break;
      pant2 = p2;
      p2 = p2->seg_succ;
    }

    // if (pant2 == nullptr)
    //   cout << endl << "pant null";
    // else
    //   cout << endl << "pant2: " << pant2->orig << ", " << pant2->dest;
    // if (p2 == nullptr)
    //   cout << endl << "p2 null";
    // else
    //   cout << endl << "p2: " << p2->orig << ", " << p2->dest;

    node *t = p;
    if (pant == nullptr) {
      p = p->seg_succ;
      prim_succ[orig] = prim_succ[orig]->seg_succ;
      // p2 = p2->seg_pred;
      // prim_pred[dest] = prim_pred[dest]->seg_pred;
      delete (t);
    } 
    else {
      if (p->seg_succ == nullptr) {
        p = pant;
        p->seg_succ = nullptr;

        // p2 = pant2;
        // p2->seg_pred = nullptr;
        delete (t);
      }
      else {
        p = p->seg_succ;
        pant->seg_succ = p;
        // p2 = p2->seg_pred;
        // pant2->seg_pred = p2;
        delete (t);
      }
    }
    prim_pred[dest] = nullptr;
  }

}