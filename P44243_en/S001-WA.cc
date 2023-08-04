#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    while (cin >> n)
    {
        char M[n][n];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (j == n - 1 or i == n - 1)
                    M[i][j] = 'X';
                else
                {
                    if (i == 0 and j >= 1)
                        M[i][j] = 'X';
                    else
                    {
                        if (i < n - 2 and (j == 1 or (j == n - 3 and i != 1) or (j == n - 4 and i == 2)))
                            M[i][j] = 'X';
                        else
                        {
                            if (i == n - 3 and j != 0 and j != n - 2)
                                M[i][j] = 'X';
                            else
                            {
                                M[i][j] = '.';
                                // if () ;
                                // else
                                //     M[i][j] = '.';
                            }
                        }
                    }
                }
                cout << M[i][j];
            }
            cout << endl;
        }
    }
}
