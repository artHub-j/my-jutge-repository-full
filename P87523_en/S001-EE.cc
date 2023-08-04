#include <iostream>
#include <vector>

using namespace std;

bool hello(string s) {

    bool trobat = false;
    for (int i = 0; not trobat and i < s.size(); ++i) {

        if (trobat)
            break;

        string aux = "";
        if (s[i] == 'h') {
            aux += s[i]; 
            for (int j = i+1; j < s.size(); ++j) {
                aux += s[j]; 
                //cout << aux << endl;
                if (aux == "hello")
                    trobat = true;
            }
        }
        else 
            aux = "";
    }

    return trobat;
}

int main() {
    string s;
    cin >> s;
    if (hello(s))
        cout << "hello" << endl;
    else 
        cout << "bye" << endl;
}

// void resposta(vector<vector<pair<char, int>>> lletres, string s)
// {
//     vector<bool> trobats(s.size(), false);
//     int max = 0;
//     for (int i = 0; i < lletres.size(); ++i) {
//         for (int j = 0; j < lletres[i].size(); ++j) {
//             if (lletres[i][j].first == s[j])
//                 trobat[j] = true;
//         }

//         bool correcte = true;
//         for (int k = 0; correcte and k < s.size(); ++k) {
//             if (trobats[k] != true)
//                 correcte = false;
//         }
//     }
// }

// int main() 
// {
//     int n, m;
//     cin >> n >> m;

//     vector<vector<pair<char, int>>> lletres;
//     for (int i = 0; i < n; ++i) {
//         for (int j = 0; j < m; ++j) {
//             cin >> lletres[i][j].first;
//         }
//     }

//     for (int i = 0; i < n; ++i) {
//         for (int j = 0; j < m; ++j) {
//             cin >> lletres[i][j].second;
//         }
//     }

//     int query;
//     cin >> query;
//     for (int i = 0; i < query; ++i) {
//         string s;
//         cin >> s;
//         resposta(lletres, s);
//     }
// }