#include <iostream>
#include <list>
using namespace std;
typedef unsigned int nat;

class dicc {
  public:
    // Constructora per defecte. Crea un diccionari buit.
    dicc();

    // Destructora
    ~dicc();

    void insereix(const string &k);
    // Pre: True
    // Post: Insereix la clau k en el diccionari. Si ja hi era, no fa res.

    list<string> llista_ordenada_dec() const;
    // Pre: True
    // Post: Retorna una llista amb totes les claus ordenades decreixentment.

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
    void llista_aux(node *p, char *buff, int prof, list<string> &l) const;
};

// Aquí va la implementació del mètode llista_ordenada_dec i privats addicionals

void dicc::llista_aux(node *root, char *buff, int depth, list<string> &l) const
{
  if (root) {
    llista_aux(root->_dre, buff, depth, l);

    buff[depth] = root->_c;
    if (root->_c == '#') {
      buff[depth + 1] = '\0';
      string s = (string) buff;
      if (not s.empty())
        s.pop_back();
      l.push_back(s);
    }

    llista_aux(root->_cen, buff, depth + 1, l);
    llista_aux(root->_esq, buff, depth, l);
  } 
}

list<string> dicc::llista_ordenada_dec() const
{
  char buff[200];
  list<string> l;
  llista_aux(_arrel, buff, 0, l);

  return l;
}