#include <iostream>
using namespace std;

double volumCub(double longi, double alc, double ampl)
{
    return longi * alc * ampl;
}

double volumPiramide(double longi, double alc, double ampl)
{
    return (longi * ampl * alc) / 3;
}

double volumPentagon(double longi, double alc, double apot)
{
    return (5 * longi * alc * apot) / 2;
}

int main()
{
    char fig;
    double longi, alc, ampl_ap;

    cin >> fig >> longi >> alc >> ampl_ap;

    if (fig == 'C')
        cout << volumCub(longi, alc, ampl_ap);
    else if (fig == 'R')
        cout << volumPiramide(longi, alc, ampl_ap);
    else if (fig == 'P')
        cout << volumPentagon(longi, alc, ampl_ap);
    cout << endl;
}