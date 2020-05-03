//
// Created by mateusz on 24.04.2020.
//

#ifndef SZABLON_Z4_MASTER_SMACIERZ_H
#define SZABLON_Z4_MASTER_SMACIERZ_H

#include "rozmiar.h"
#include "SWektor.h"
#include "LZespolona.hh"
#include <iostream>
/*
*  Klasa modeluje pojecie szablonu macierzy kwadratowej o wymiarach ROZMIAR x ROZMIAR.
*/

template <class TYP, int Rozmiar>
class SMacierz {
    SWektor<TYP,ROZMIAR> tab[Rozmiar];
public:

    SMacierz();
    explicit SMacierz(SWektor<TYP,Rozmiar> Wiersze[ROZMIAR]);

    const SWektor<TYP,Rozmiar> & operator[] (int indeks) const;
    SWektor<TYP,Rozmiar> & operator[] (int indeks);
    const TYP & operator() (int ind1, int ind2) const {return tab[ind1][ind2]; }
    TYP & operator() (int ind1, int ind2) {return tab[ind1][ind2]; }

    SMacierz<TYP,Rozmiar> skopiuj() const;
    SMacierz<TYP,Rozmiar>  transpozycja();
    SWektor<TYP,Rozmiar>  operator * (const SWektor<TYP,Rozmiar> & W) const;
    double wyznacznik() const;
};

/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt
*/



/* Wczytuje 3 wektory i tworzy z nich macierz.*/

template <class TYP, int Rozmiar>
std::istream& operator >> (std::istream &Strm, SMacierz<TYP,Rozmiar> &Mac);

/* Wsywietla na standardowym wyjsciu macierz.*/

template <class TYP, int Rozmiar>
std::ostream& operator << (std::ostream &Strm, const SMacierz<TYP,Rozmiar> & Mac);

#endif //SZABLON_Z4_MASTER_SMACIERZ_H
