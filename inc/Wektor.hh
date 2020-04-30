#ifndef WEKTOR_HH
#define WEKTOR_HH

#include "rozmiar.h"
#include <iostream>
#include <cmath>
/*
 *  Klasa modeluje pojecie wektora o wymiarze ROZMIAR;
 */

class Wektor {

    double dane[ROZMIAR]{};

public:
    Wektor();
    Wektor(double wsporzedne[ROZMIAR]);
    const double & operator[] (int indeks) const;
    double & operator[] (int indeks);

    Wektor operator + (const Wektor & W2) const;
    Wektor operator - (const Wektor & W2) const;
    double operator * (const Wektor & W2) const;

    Wektor  operator * (  double liczba) const;
    Wektor  operator / (  double liczba) ;
    double dlugosc() const;
};
/* Wczytuje 3 wartosci double, tworzy z nich wektor.*/
std::istream& operator >> (std::istream & Strm, Wektor &Wek);

/* Wsywietla na standardowym wyjsciu wektor.*/
std::ostream& operator << (std::ostream & Strm, const Wektor & Wek);

#endif
