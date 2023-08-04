#include<iostream>
#include<vector>

using namespace std;

typedef vector<vector <int> > Matriu;
int combinacions(const Matriu &mat) {
// Pre: mat ´es una matriu d’enters que cont´e nom´es
// 1, 2 i 3.
// Post: retorna el nombre de combinacions [2 3] en
// vertical i horitzontal de mat.
unsigned int cont = 0;
int filas=int(mat.size());
int columnas=int(mat[0].size());

for (int i = 0; i < filas; ++i) {
// Inv: cont cont´e el n´umero de combinacions [2 3]
// que han aparegut a les files anteriors a i.
	for (int j = 0; j < columnas; ++j) {
// Inv: cont cont´e el n´umero de combinacions [2 3]
// que han aparegut a les files anteriors a i,
// m´es les que han aparegut a la fila i
// anteriors a la columna j.
		if (mat[i][j]==2){
		if (j+1<columnas)
			if (mat[i][j+1]==3) ++cont;
		if (j-1>=0)
			if (mat[i][j-1]==3) ++cont;
		if (i+1<filas)
			if (mat[i+1][j]==3) ++cont;
		if (i-1>=0)
			if (mat[i-1][j]==3) ++cont;
		}
	}
}
return cont;
}

