#include <iostream>
#include <vector>
using namespace std;
bool es_anagrama(string s1, string s2) {
// Pre: s1 i s2 son dos cadenes de car`acters
// Post: retorna true els car`acters de s1 i s2
// s´on els mateixos, encara que estiguin ordenats
// de forma diferent, altrament retorna false.
unsigned n1=s1.size(), n2=s2.size();
vector<bool> v(n1,false);
bool anagrama=false;
if (n1==n2) {
unsigned i=0;
bool trobat2=false;
while (i<n1 and not trobat2) {
// Inv: tots els car`acters entre 0 i i - 1 de s1
// s’han trobat a s2
unsigned int j=0;
bool trobat1=false;
while (j<n2 and not trobat1) {
// Inv: el car`acter i de s1 no est`a a les
// posicions entre 0 i j - 1 de s2
if (s1[i]==s2[j] and v[j]==false){
trobat1=true;
v[j]=true;
}
else ++j;
}
if (not trobat1) trobat2=true;
else ++i;
}
if (i==n1){
bool trobat3=false;
i=0;
while (i<n1 and not trobat3){
// Inv: totes les possicions del vector v
// anteriors a i contenen true
if (v[i]==false) trobat3=true;
else ++i;
}
if (not trobat3) anagrama=true;
}
}
return anagrama;
}
5
int main() {
string x, y;
cin >> x >> y;
int cont=0;
while (y!="."){
// Inv: cont cont´e el nombre d’anagrames de x llegits
// pel canal d’entrada sense comptar l’actual.
if (es_anagrama (x,y)) ++cont;
cin>>y;
}
cout<<x<<" t´e "<<cont<<" anagrames en el flux."<<endl;
}

