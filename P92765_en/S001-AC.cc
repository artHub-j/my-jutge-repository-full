#include <iostream>
#include <cstddef>

#include <iomanip>

using namespace std;

template <typename T>
class Abin {
  private:
    struct node {
      node* f_esq;
      node* f_dret;
      T info;
    };
    node* _arrel;
    static node* copia_nodes(node* m);
    static void esborra_nodes(node* m);
    static void imprimeix_inordre(node *n, int nivell);

    static node* consulta_bst(node *n, const T &k);

  public:
    //constructors
    Abin(): _arrel(NULL) {};
    /* Pre: cert */
    /* Post: el resultat és un arbre sense cap element */
    Abin(Abin<T> &ae, const T &x, Abin<T> &ad);
    /* Pre: cert */
    /* Post: el resultat és un arbre amb un element i dos subarbres */

    // Les tres grans
    Abin(const Abin<T> &a);
    ~Abin();
    Abin<T>& operator=(const Abin<T>& a);
    Abin<T> crea();

    // Iterador sobre arbres binaris.
    friend class iterador;
    class iterador {
      private:
        Abin<T>::node* _p;

      public:
        friend class Abin;
        iterador(): _p(NULL) {};
        /* Pre: cert */
        /* Post: Construeix un iterador no vàlid. */

        Abin<T> arbre() const;
        /* Pre: cert */
        /* Post: Retorna el subarbre al que apunta l'iterador; llança un error
        si l'iterador no és vàlid. */

        T operator*() const;
        /* Pre: cert */
        /* Post: Retorna l'element en el node al que apunta l'iterador, o
        llança un error si l'iterador no és vàlid. */

        iterador fesq() const;
        /* Pre: cert */
        /* Post: Retorna un iterador al fill esquerre; llança
        un error si l'iterador no és vàlid. */

        iterador fdret() const;
        /* Pre: cert */
        /* Post: Retorna un iterador al fill dret; llança
        un error si l'iterador no és vàlid. */

        /* Operadors de comparació. */
        bool operator==(const iterador &it) const {
          return _p == it._p;
        };
        bool operator!=(const iterador &it) const {
          return _p != it._p;
        };
        static const int IteradorInvalid = 410;
    };

    //consultors
    bool es_buit() const;
    /* Pre: cert */
    /* Post: el resultat indica si el p.i. és buit o no */

    iterador arrel() const;
    /* Pre: cert */
    /* Post: Retorna un iterador al node arrel. */
    
    iterador final() const;
    /* Pre: cert */
    /* Post: Retorna un iterador no vàlid. */

    bool consulta_bst(const T &k) const;
    // Pre: cert
    // Post: Retorna true si l’element k esta en el p.i. tenint en compte que es un BST

    void imprimeix_inordre() const;
    
};

template <typename T>    
bool Abin<T>::consulta_bst(const T &k) const
{
  node *n = consulta_bst(_arrel, k);
  bool hi_es;
  if (n == nullptr)
    hi_es = false;
  else {
    hi_es = true;
  }

  return hi_es;
};

template <typename T>        
typename Abin<T>::node* Abin<T>::consulta_bst(node *n, const T &k)
{
  if (n == nullptr or n->info == k)
    return n;
  else {
    if (k < n->info)
      return consulta_bst(n->f_esq, k);
    else
      return consulta_bst(n->f_dret, k);
  }
};

template <typename T>        
Abin<T> Abin<T>::crea()
{
  int e;
  cin >> e;
  if (e == -1)
    return Abin<T>();
  else {
    Abin<T> ae(crea());
    Abin<T> ad(crea());
    return Abin<T> (ae, e, ad);
  }
};

template <typename T>    
void Abin<T>::imprimeix_inordre() const
{
  int nivell = 1;
  cout << _arrel->info << endl;
  imprimeix_inordre(_arrel, nivell);
};

template <typename T>    
void Abin<T>::imprimeix_inordre(node *n, int nivell)
{
  if (n != nullptr) 
  {
    imprimeix_inordre(n->f_dret, nivell + 1);
    cout << setw(nivell * 10) << n->info << endl;
    imprimeix_inordre(n->f_esq, nivell + 1);
  }
};

//---------------------------

template <typename T>
typename Abin<T>::node* Abin<T>::copia_nodes(node* m) {
/* Pre: cert */
/* Post: si m és NULL, el resultat és NULL; sinó,
   el resultat apunta al primer node d'un arbre binari
   de nodes que són còpia de l'arbre apuntat per m */
  node* n;
  if (m == NULL) n = NULL;
  else {
    n = new node;
    try {
      n->info = m->info;
      n->f_esq = copia_nodes(m->f_esq);
      n->f_dret = copia_nodes(m->f_dret);
    } catch(...) {
      delete n;
      throw;
    }
  }
  return n;
};

template <typename T>
void Abin<T>::esborra_nodes(node* m) {
/* Pre: cert */
/* Post: no fa res si m és NULL, sinó allibera
   espai dels nodes de l'arbre binari apuntat per m */
  if (m != NULL) {
    esborra_nodes(m->f_esq);
    esborra_nodes(m->f_dret);
    delete m;
  }
};

template <typename T>
Abin<T>::Abin(Abin<T>& ae, const T& x, Abin<T>& ad) {
/* Pre: cert */
/* Post: el resultat és un arbre amb x com arrel, ae com a fill
esquerre i ad com a fill dret. No fa còpia dels arbres ae i ad */
  _arrel = new node;
  try {
    _arrel->info = x;
  }
  catch (...) {
    delete _arrel;
    throw;
  }
  _arrel->f_esq = ae._arrel;
  ae._arrel = NULL;
  _arrel->f_dret = ad._arrel;
  ad._arrel = NULL;
}

template <typename T>
Abin<T>::Abin(const Abin<T> &a) {
  _arrel = copia_nodes(a._arrel);
};

template <typename T>
Abin<T>::~Abin() {
  esborra_nodes(_arrel);
};

template <typename T>
Abin<T>& Abin<T>::operator=(const Abin<T>& a) {
  if (this != &a) {
    node* aux;
    aux = copia_nodes(a._arrel);
    esborra_nodes(_arrel);
    _arrel = aux;
  }
  return (*this);
};

template <typename T>
bool Abin<T>::es_buit() const {
/* Pre: cert */
/* Post: el resultat indica si el p.i. és buit o no */
  return (_arrel == NULL);
};

template <typename T>
typename Abin<T>::iterador Abin<T>::arrel() const {
/* Pre: cert */
/* Post: Retorna un iterador al node arrel. */
  iterador it;
  it._p = _arrel;
  return it;
};

template <typename T>
typename Abin<T>::iterador Abin<T>::final() const{
/* Pre: cert */
/* Post: Retorna un iterador no vàlid. */
  return iterador();
};

template <typename T>
Abin<T> Abin<T>::iterador::arbre() const {
/* Pre: cert */
/* Post: Retorna el subarbre al que apunta l'iterador; llança un error
si l'iterador no és vàlid. */
  if (_p == NULL)
    throw IteradorInvalid;
  Abin<T> a;
  a._arrel = copia_nodes(_p);;
  return a;
};

template <typename T>
T Abin<T>::iterador::operator*() const {
/* Pre: cert */
/* Post: Retorna l'element en el node al que apunta l'iterador, o
llança un error si l'iterador no és vàlid. */
  if (_p == NULL)
    throw IteradorInvalid;
  return _p->info;
};

template <typename T>
typename Abin<T>::iterador Abin<T>::iterador::fesq() const {
/* Pre: cert */
/* Post: Retorna un iterador al fill esquerre; llança
un error si l'iterador no és vàlid. */
  if (_p == NULL) 
    throw IteradorInvalid;
  iterador it;
  it._p = _p->f_esq;
  return it;
};

template <typename T>
typename Abin<T>::iterador Abin<T>::iterador::fdret() const {
/* Pre: cert */
/* Post: Retorna un iterador al fill dret; llança
un error si l'iterador no és vàlid. */
  if (_p == NULL) 
    throw IteradorInvalid;
  iterador it;
  it._p = _p->f_dret;
  return it;
};
      
int main()
{
  int ignore;
  cin >> ignore;
  Abin<int> a;
  a = a.crea();
  
  int e;
  while (cin >> e) {
    cout << e << " " << a.consulta_bst(e) << endl;
  }
  return 0;
}