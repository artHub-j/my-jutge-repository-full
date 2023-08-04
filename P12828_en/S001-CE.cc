#include <iostream>
using namespace std;
int main() {
// Atura l’aerogenerador si hi ha tres mesures
// consecutives majors a 25.0.
double e;
bool trobat = false;
int num = 0;
while (cin >> e and not trobat) {
// Inv: num indica el nombre de mesures
// consecutives majors de 25.0 i num ´es menor que 3.
if (e > 25.0) ++num;
else num = 0;
if (num == 3) trobat = true;
}
if (trobat) atura();
}

