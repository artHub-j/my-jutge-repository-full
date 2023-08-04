#include <iostream>
using namespace std;

int main()
{
    double numero;
    int entera, enteraSuperior, arrodoniment;

    cin >> numero;

    entera = (int)numero;
    enteraSuperior = entera;
    arrodoniment = entera;

    double decimals = numero - entera;
    if (decimals != 0)
    {
        enteraSuperior += 1;
    }

    if (decimals >= 0.5)
    {
        arrodoniment += 1;
    }

    cout << entera << " " << enteraSuperior << " " << arrodoniment << endl;

    return 0;
}