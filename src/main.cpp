#include <iostream>
#include <iomanip>
#include "SUklad.h"
#include "SWektor.h"
#include "rozmiar.h"
#include "LZespolona.hh"

using namespace std;

void dzialaj_dla_r(){
    SUklad<double, ROZMIAR>   UklRown;
    SWektor<double, ROZMIAR> Wx;
    SWektor<double, ROZMIAR> Wbledu;

    cin >> UklRown;
    cout << fixed << setprecision(2);
    cout <<endl<< UklRown;

    cout << "Rozwiazanie x = (x1, x2, x3, x4, x5):" << endl;
    Wx = UklRown.Oblicz();
    cout << Wx << endl;

    cout << scientific << setprecision(1);
    Wbledu = UklRown.get_A() * Wx - UklRown.get_b();
    cout << "Wektor bledu: Ax-b = " << Wbledu << endl;
}
void dzialaj_dla_z(){
    SUklad<LZespolona, ROZMIAR>   UklRown;
    SWektor<LZespolona, ROZMIAR> Wx;
    SWektor<LZespolona, ROZMIAR> Wbledu;

    cin >> UklRown;
    cout << fixed << setprecision(2);
    cout <<endl<< UklRown;

    cout << "Rozwiazanie x = (x1, x2, x3, x4, x5):" << endl;
    Wx = UklRown.Oblicz();
    cout << Wx << endl;

    cout << scientific << setprecision(1);
    Wbledu = UklRown.get_A() * Wx - UklRown.get_b();
    cout << "Wektor bledu: Ax-b = " << Wbledu << endl;
}
int main() {

    cout << endl << "Start programu " << endl ;
    cout<< "Dla liczb rzeczywitsych wprowadz znak: r"<<endl;
    cout<< "Dla liczb zespolonych wprowadz znak: z"<<endl;

    char typ_danych;
    cin >> typ_danych;

    switch (typ_danych) {
        case 'r' : dzialaj_dla_r();
            break;
        case 'z' : dzialaj_dla_z();
            break;

        default :
            cout << "Blad. Nie wprowadziles znaku typu danych lub znak jest niepoprawny."<<endl;
            cout << "Jesli chcesz, abu program dzialal dla liczb rzeczywistych wprowac znak: r"<<endl;
            cout << "Jesli chcesz, abu program dzialal dla liczb zespolonych wprowac znak: z"<<endl;
            exit(1);
    }

   return 0;
}
