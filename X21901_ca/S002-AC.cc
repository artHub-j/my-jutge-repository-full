#include <cstdlib>
#include <iostream>
using namespace std;
typedef unsigned int nat;

class expressio {
  // Guarda una expressio en un arbre binari.
  // Els operadors i operands es guarden en l’string token de cada node.
  // Els operadors unaris (+ - sqrt log exp) tenen el fill dret buit.
  public:
    expressio(): _arrel(nullptr) {};
    // Pre: cert
    // Post: el resultat és un arbre sense cap element
    expressio(expressio &ae, const string &x, expressio &ad);
    // Pre: cert
    // Post: el resultat és un arbre amb un element i dos subarbres

    // Les tres grans
    expressio(const expressio &a);
    ~expressio();
    expressio& operator=(const expressio& a);

    // operador << d’escriptura
    friend std::ostream& operator<<(std::ostream&, const expressio &a);

    // operador >> de lectura
    friend std::istream& operator>>(std::istream&, expressio &a);

    string llista_tokens_parentitzada() const;
    // Pre: Cert
    // Post: Retorna string amb la representació infixa de l’expressió amb tots els parèntesis possibles,
    // excepte quan són operands (constants o variables) que mai fan falta.

  private:
    struct node {
      node* f_esq;
      node* f_dret;
      string token;
    };
    node* _arrel;
    static node* copia_nodes(node* m);
    static void esborra_nodes(node* m);
    static void print_nodes(node* m, ostream &os, string d1);

    // Aquí va l’especificació dels mètodes privats addicionals
    void llista_tokens_aux(node *p, string &s) const;
    bool check_operator(string &s) const;
    bool es_unari(string &s) const;
    bool es_binari(string &s) const;
};

bool expressio::check_operator(string &s) const
{
  bool es_op;
  es_op = (s == "+" or s == "*" or s == "/" or s == "^" or s == "-" or
           s == "log" or s == "sqrt");
  return es_op;
}

bool expressio::es_binari(string &s) const
{
  bool binari;
  binari = (s == "+" or s == "*" or s == "/" or s == "^");
  return binari;
}

bool expressio::es_unari(string &s) const
{
  bool unari;
  unari = (s == "log" or s == "sqrt" or s == "-");
  return unari;
}

void expressio::llista_tokens_aux(node *p, string &s) const
{
  if (p == NULL)
    return;

  if (check_operator(p->token)) {
    if (es_binari(p->token)) {
      s += '(';
      llista_tokens_aux(p->f_esq, s);
      s += p->token;
      llista_tokens_aux(p->f_dret, s);
      s += ')';
    }
    else if (es_unari(p->token)) {
      s += p->token;
      s += '(';
      llista_tokens_aux(p->f_esq, s);
      s += ')';
    }
  }
  else {
    s += p->token;
  }
}

// Aquí va la implementació del mètode llista_tokens_parentitzada i privats addicionals
string expressio::llista_tokens_parentitzada() const
{
  string res = "";
  llista_tokens_aux(_arrel, res);
  return res;
}