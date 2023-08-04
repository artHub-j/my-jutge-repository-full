#include <iostream>
#include <vector>

using namespace std;

struct Jugador
{
    string nom;
    int salari;
    int punts;
};

typedef vector<Jugador> Jugadors;

// Llegeix el nom, el salari i els punts d'un jugador de l'entrada estandar,
// crea el jugador amb aquestes dades i el retorna.
Jugador llegirJugador()
{
    Jugador j;
    cin >> j.nom >> j.salari >> j.punts;
    return j;
}

// Retorna cert sii el jugador que és rep com a paràmetre té un nombre de punts
// dins de l'interval [p1,p2].
bool pertanyAInterval(const Jugador &jugador, int p1, int p2)
{
    if (jugador.punts >= p1 and jugador.punts <= p2)
    {
        // cout << "Jugador " << jugador.nom << " pertany a l'interval [" << p1 << ", " << p2 << "]" << endl;
        return true;
    }
    else
        return false;
}

int main()
{
    int n;
    cin >> n;
    Jugadors llista(n);

    for (int i = 0; n > 0; i++)
    {
        Jugador j = llegirJugador();
        llista[i] = j;
        // cout << llista[i].nom << " " << llista[i].salari << " " << llista[i].punts << endl;
        n--;
    }

    int m;
    cin >> m;
    while (m > 0)
    {
        int p1, p2;
        cin >> p1 >> p2;
        int sum = 0;
        vector<string> noms;
        for (int i = 0; i < llista.size(); i++)
        {
            if (pertanyAInterval(llista[i], p1, p2))
            {
                sum += llista[i].salari;
                noms.push_back(llista[i].nom);
            }
        }
        cout << sum;
        for (int i = 0; i < noms.size(); i++)
        {
            cout << " ";
            cout << noms[i];
        }
        cout << endl;
        m--;
    }
}