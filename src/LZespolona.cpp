#include <iostream>
#include "LZespolona.hh"
/*!
 *  Wczytuje ze standardowego wejscia liczbe zespoloną
 * */
std::istream & operator >> (std::istream & Strm, LZespolona &in) {
    char znak;
    Strm >> znak;
    if (znak != '(') {
        Strm.setstate(std::ios::failbit);
    }
    Strm >> in.re;
    Strm >> in.im;
    Strm >> znak;
    if (znak != 'i') {
        Strm.setstate(std::ios::failbit);
    }
    Strm >> znak;
    if (znak != ')') {
        Strm.setstate(std::ios::failbit);
    }
    return Strm;
}

/*!
 * Wyswietla liczbę zespolona na standardoe wyjscie w postaci (0+0i)
 */
std::ostream & operator << (std::ostream & Strm, const LZespolona &out) {

  Strm << "(" << out.re << std::showpos << out.im << std::noshowpos << "i)";
    return Strm;
}
/*****************************************************************/
/* Konstruktory*/
LZespolona::LZespolona() {
    re = 0;
    im = 0;
}
LZespolona::LZespolona(double _re) {
    re = _re;
    im = 0;
}
LZespolona::LZespolona(double _re, double _im) {
    re = _re;
    im = _im;
}
LZespolona::LZespolona(LZespolona const &L2) {
    re = L2.re;
    im = L2.im;
}
/*****************************************************************/
LZespolona & LZespolona::operator = (double _re) {
    re = _re;
    im = 0;
    return *this;
}

/* Konstruktor kopiujacy nie dziala przy wczytaniu wektora, wiec uzyam tego przeciazenia*/
LZespolona & LZespolona::operator=(const LZespolona& L) {
    re= L.re;
    im = L.im;
    return  *this;
}
/*****************************************************************/
/*!
 * Realizuje dodanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik dodawania,
 *    Skl2 - drugi skladnik dodawania.
 * Zwraca:
 *    Sume dwoch skladnikow przekazanych jako parametry.
 */

LZespolona operator+(LZespolona Skl1, LZespolona Skl2) {
    LZespolona  Wynik;

    Wynik.re = Skl1.re + Skl2.re;
    Wynik.im = Skl1.im + Skl2.im;

    return Wynik;
}

/*!
 * Realizuje odejmowanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik odejmowania,
 *    Skl2 - drugi skladnik odejmowania.
 * Zwraca:
 *    Różnicę dwoch skladnikow przekazanych jako parametry.
 */
LZespolona  operator - (LZespolona  Skl1,  LZespolona  Skl2)
{
    LZespolona  Wynik;

    Wynik.re = Skl1.re - Skl2.re;
    Wynik.im = Skl1.im - Skl2.im;

    return Wynik;
}
/*!
 * Realizuje mnożenie dwoch liczb zespolonych.
 *
 * Argumenty:
 *    Skl1 - pierwszy skladnik mnożenia,
 *    Skl2 - drugi skladnik mnożenia.
 * Zwraca:
 *    Iloczyn dwoch skladnikow przekazanych jako parametry.
 */
LZespolona  operator * (LZespolona  Skl1,  LZespolona  Skl2) {
    LZespolona  Wynik;

    Wynik.re = Skl1.re * Skl2.re - Skl1.im * Skl2.im;
    Wynik.im = Skl1.re * Skl2.im + Skl1.im * Skl2.re;

    return Wynik;
}

/*!
 * Realizuje dzielenie dwoch liczb zespolonych.
 *
 * Argumenty:
 *    Skl1 - pierwszy skladnik dzielenia,
 *    Skl2 - drugi skladnik dzielenia.
 * Zwraca:
 *    Iloraz dwoch skladnikow przekazanych jako parametry.
 */
LZespolona  operator / (LZespolona  Skl1,  LZespolona  Skl2) {

    LZespolona Sprzerzona, Wynik;
    double modul2;

    Sprzerzona = Sprzerzenie(Skl2);
    modul2 = Modul2(Skl2);
    if (modul2 != 0) {
        Wynik.re = (Skl1.re * Sprzerzona.re - Skl1.im * Sprzerzona.im) / modul2;
        Wynik.im = (Skl1.re * Sprzerzona.im + Skl1.im * Sprzerzona.re) / modul2;
        return Wynik;
    }
    else {
        std::cerr << "Błąd! Nie dziel przez 0";
        exit(1);
    }
}

/* Iloczyn LZespolonej przez double*/
LZespolona  LZespolona::operator * (double skl2) {

    LZespolona Skl2, Wynik;
    Skl2= skl2;
    Wynik = *this * Skl2;
    return Wynik;
}
double operator * (double skl1, LZespolona  Skl2) {
    double wynik;
    wynik = skl1 * Skl2.re;
    return wynik;
}



/* Iloraz LZespolonej przez double*/
LZespolona  operator / (LZespolona  Skl1,  double skl2) {
    if(skl2 != 0) {
        LZespolona Skl2, Wynik;
        Skl2= skl2;
        Wynik = Skl1 / Skl2;
        return Wynik;
    } else {
        std::cerr << "Błąd! Nie dziel przez 0." << std::endl;
        exit(1);
    }
}

bool operator == (const LZespolona&  L1,  LZespolona  L2) {
    return (L1.re == L2.re) && (L1.im == L2.im);
}

bool operator != (const LZespolona&  L1,  const LZespolona&  L2) {
    return !(L1 == L2);
}

bool operator == (const LZespolona&  L1,  double l2) {
    return (L1.re == l2) && (L1.im == l2);
}

bool operator != (const LZespolona&  L1,  double l2) {
    return !(L1 == l2);
}

LZespolona Sprzerzenie (LZespolona Liczba)  {

    LZespolona Lsprzerzenie;

    Lsprzerzenie.re = Liczba.re;
    Lsprzerzenie.im = -Liczba.im;

    return Lsprzerzenie;
}

double Modul2(LZespolona Liczba)  {
    double modul2;
    modul2 = Liczba.re * Liczba.re + Liczba.im * Liczba.im;

    return modul2;
}

