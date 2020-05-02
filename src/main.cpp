#include <iostream>
#include "SUklad.h"
#include "SWektor.h"
#include "SMacierz.h"
#include "rozmiar.h"
#include "LZespolona.hh"

using namespace std;

void dzialaj_dla_r(){
    SUklad<double, ROZMIAR>   UklRown;
    SWektor<double, ROZMIAR> Wx;
    SWektor<double, ROZMIAR> Wbledu;

    cin >> UklRown;
    cout <<endl<< UklRown;

    cout << "Rozwiazanie x = (x1, x2, x3, x4, x5):" << endl;
    Wx = UklRown.Oblicz();
    cout << Wx << endl;

    Wbledu = UklRown.get_A() * Wx - UklRown.get_b();
    cout << "Wektor bledu: Ax-b = " << Wbledu << endl;
}
void dzialaj_dla_z(){
    SUklad<LZespolona, ROZMIAR>   UklRown;
    SWektor<LZespolona, ROZMIAR> Wx;
    SWektor<LZespolona, ROZMIAR> Wbledu;


    cin >> UklRown;
    cout <<endl<< UklRown;

    cout << "Rozwiazanie x = (x1, x2, x3, x4, x5):" << endl;
    Wx = UklRown.Oblicz();
    cout << Wx << endl;

    Wbledu = UklRown.get_A() * Wx - UklRown.get_b();
    cout << "Wektor bledu: Ax-b = " << Wbledu << endl;
}
int main() {

    cout << endl << "Start programu " << endl << endl;

    char typ_danych;
    cin >> typ_danych;

    switch (typ_danych) {
        case 'r' : dzialaj_dla_r();
        break;
        case 'z' : dzialaj_dla_z();
            break;

        default :
            cout << "Blad. Nie wprowadziles znaku typu danych lub znak jest niepoprawny"<<endl;
            cout << "Jesli chcesz, abu program dzialal dla liczb rzeczywistych wprowac znak: r"<<endl;
            cout << "Jesli chcesz, abu program dzialal dla liczb zespolonych wprowac znak: z"<<endl;
            break;
    }

/*
    2.00 1.00 1.00 1.00 2.00
    2.00 2.00 3.00 1.00 2.00
    1.00 1.50 1.00 1.00 0.00
    3.00 1.00 2.00 4.00 0.00
    3.00 2.00 2.00 0.00 1.00
    9.00 8.00 8.00 9.00 1.00

z
(2.00+1.00i) (1.00+1.00i) (1.00+1.00i) (1.00+2.00i) (2.00+3.00i)
(2.00+3.00i) (2.00+5.00i) (3.00+7.00i) (1.00+2.00i) (2.00+2.00i)
(1.00+2.00i) (1.50+3.00i) (1.00+1.00i) (1.00+1.00i) (0.00+2.00i)
(3.00+1.00i) (1.00+4.00i) (2.00+1.00i) (4.00+3.00i) (0.00+0.00i)
(3.00+2.00i) (2.00+2.00i) (2.00+0.00i) (0.00+1.00i) (1.00+1.00i)
(9.00+1.00i) (8.00+2.00i) (8.00+8.00i) (9.00+5.00i) (1.00+1.00i)
    */
   return 0;
}
