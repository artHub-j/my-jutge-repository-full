#include <iostream>

using namespace std;

bool estat_fila(int Matriu[9][9], int val, int fila)
{
	bool r;
	for (int i = 0; i < 9; ++i)
	{
		r = val == Matriu[fila][i];
	}
	return r;
}

bool estat_columna(int Matriu[9][9], int val, int columna)
{
	bool r;
	for (int i = 0; i < 9; ++i)
	{
		r = val == Matriu[i][columna];
	}
	return r;
}

void limit_regio(const int &regio, int &i, int &j, int &i_final, int &j_final)
{
	int aux = regio;

    while (aux >= 0)
    {
        if (j == 6)
        {
            i = i + 3;
            j = 0 - 3;
        }
        if (j_final == 8)
        {
            i_final = i_final + 3;
            j_final = 2-3;
        }
        j = j + 3;
        j_final = j_final + 3;
        --aux;
    }
}

bool estat_regio(int Matriu[9][9], int val, int regio)
{
	int i = 0, j = -3, i_final = 2, j_final = -1;
	limit_regio(regio, i, j , i_final, j_final);
	
	bool r = false;
	for (int k = i; k <= i_final and not r; ++k)
	{
		for (int l = j; l <= j_final and not r; ++l)
		{
			r = Matriu[k][l] != val;
		}
	}
	return r;
}

int selector_regio(int fila, int columna)
{
    int regio;
    for (int i = 0, j = 2; i < 9 and j < 9; i = i + 3, j = j + 3)
    {
        if (fila >= i and fila <= j)
        {
            if (columna >= 0 and columna <= 2)
                regio = 0 + i;
            else if (columna >= 3 and columna <= 5)
                regio = 1 + i;
            else if (columna >= 6 and columna <= 8)
                regio = 2 + i;
        }
    }
    return regio;
}

int main()
{
	int n;
	cin >> n;
	
	while (n > 0)
	{
		int Matriu[9][9];
		for (int i = 0; i < 9; ++i)
		{
			for (int j = 0; j < 9; ++j)
			{
				cin >> Matriu[i][j];
			}
		}
		
		bool r;
		
		for (int i = 0; i < 9; ++i)
		{
			for (int j = 0; j < 9; ++j)
			{
				int regio = selector_regio(i, j);
				for (int val = 1; val <= 9; ++val)
				{
					r = not estat_fila(Matriu, val, i) and
						not estat_columna(Matriu, val, j) and
						not estat_regio(Matriu, val, regio);
						
					//cout << not estat_fila(Matriu, val, i) << endl;
					//cout << not estat_columna(Matriu, val, j) << endl;
					//cout << not estat_regio(Matriu, val, regio) << endl;
				}
			}
		}
		if (r) cout << "yes" << endl;
		else cout << "no" << endl;
		--n;
	}
}
