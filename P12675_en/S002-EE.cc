#include <iostream>
#include <vector>
using namespace std;

int common_elements(const vector<int> &X, const vector<int> &Y)
{
    int r = 0;
    if (X[X.size() - 1] < Y[0])
        return r;
    else
    {
        if (X.size() <= Y.size())
        {
            for (int i = 0; i < X.size(); i++)
            {
                int a = X[i];
                for (int j = 0; j < Y.size(); j++)
                {
                    if (Y[j] == a)
                        r++;
                }
            }
        }
        else
        {
            return common_elements(Y, X);
        }
    }

    return r;
}

int main()
{
    int n, m;
    while (cin >> m >> n)
    {

        vector<int> X(m);
        for (int i = 0; i < m; ++i)
            cin >> X[i];

        vector<int> Y(n);
        for (int i = 0; i < n; ++i)
            cin >> Y[i];

        cout << common_elements(X, Y) << endl;
    }
    return 0;
}
