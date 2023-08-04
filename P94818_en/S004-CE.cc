#include "abin.hpp"
#include <iostream>
#include <iomanip>

using namespace std;

template <typename T>
void Abin<T>::insereix_bst(const T &k)
{ 
  _arrel = insereix_bst(_arrel, k);
};

template <typename T>
typename Abin<T>::node* Abin<T>::insereix_bst(node *n, const T &k)
{
  if (n == nullptr)
  {
    node *aux = new node;
    aux->info = k;
    return aux;
  }

  else {
    if (k < n->info)
      n->f_esq = insereix_bst(n->f_esq, k);
    else if (k > n->info)
      n->f_dret = insereix_bst(n->f_dret, k);
    else 
      n->info = k;
  }

  return n;
};

template <typename T>    
void Abin<T>::imprimeix_inordre() const
{
  int nivell = 1;
  imprimeix_inordre(_arrel, nivell);
}

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

int main ()
{
    Abin<int> a;

    int e;
    while (cin >> e) 
        a.insereix_bst(e);

    a.imprimeix_inordre();

    return 0;
}