#include <iostream>
#include <vector>
#include <list>

using namespace std;

typedef unsigned int nat;

class graf {
  // Graf dirigit i no etiquetat.
  // Les arestes es guarden en llistes d’adjacència (vector amb els successors).
  public:
    // Constructora per defecte. Crea un graf buit.
    graf();

    // Destructora
    ~graf();

    // Llegeix les dades del graf del canal d’entrada
    void llegeix();

    bool hi_ha_cami(nat ini, nat fi) const;
    // Pre: ini i fi són vèrtexs del graf (són menors que n)
    // Post: Retorna un booleà indicant si hi ha camí per anar d’ini a fi

  private:
    nat n; // Nombre de vèrtexs
    nat m; // Nombre d’arestes
    vector<vector<nat>> a; // Vectors amb els successors de cada vèrtex

    // Aquí va l’especificació dels mètodes privats addicionals
};

// Aquí va la implementació del mètode públic hi_ha_cami i privats addicionals

bool graf::hi_ha_cami(nat s, nat d) const
{
  bool hi_ha_cami = false;
  if (s == d) {
    hi_ha_cami = true;
  }
  else {
    // Marquem tots els vertex com a no visitats.
    vector<bool> visitats(a.size(), false);

    // Cua per el BFS
    list<int> queue;

    // Maquem el vertex actual com a vistat i l'encuem
    visitats[s] = true;
    queue.push_back(s);

    while (not queue.empty()) {
      s = queue.front();
      queue.pop_front();

      for (int i = 0; i < a[s].size(); ++i) 
      {
        if (a[s][i] == d)
          hi_ha_cami = true;
        else if (not visitats[a[s][i]]) {
          visitats[a[s][i]] = true;
          queue.push_back(a[s][i]);
        }
      }
    }
  }
    
  return hi_ha_cami;
}