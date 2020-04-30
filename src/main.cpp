#include <iostream>
#include "SUklad.h"
#include "SWektor.h"
#include "SMacierz.h"
#include "rozmiar.h"
#include "LZespolona.hh"

using namespace std;

int main() {
  SUklad<double,ROZMIAR>   UklRown;
    SWektor<double,ROZMIAR> Wx;
    SWektor<double,ROZMIAR> Wbledu;

    cout << endl << "Start programu " << endl << endl;
    cin >> UklRown;
    cout <<endl<< UklRown;

    cout << "Rozwiazanie x = (x1, x2, x3):" << endl;
    Wx = UklRown.Oblicz();
    cout << Wx << endl;

    Wbledu = UklRown.get_A() * Wx - UklRown.get_b();
    cout << "Wektor bledu: Ax-b = " << Wbledu << endl;

   return 0;
}


