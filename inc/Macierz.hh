#ifndef MACIERZ_HH
#define MACIERZ_HH

#include "rozmiar.h"
#include "Wektor.hh"
#include <iostream>

 /**  Klasa modeluje pojecie macierzy kwadratowej o wymiarach ROZMIAR x ROZMIAR.*/


class Macierz {
    Wektor tab[ROZMIAR];
  public:

  Macierz();
  Macierz(Wektor Wie1, Wektor Wie2, Wektor Wie3);

  const Wektor & operator[] (int indeks) const;
  Wektor & operator[] (int indeks);
  const double & operator() (int ind1, int ind2) const {return tab[ind1][ind2]; }
  double & operator() (int ind1, int ind2) {return tab[ind1][ind2]; }

  const Wektor & get_wiersz(int indeks) const;
  void set_wiersz(const Wektor &bb);

  Macierz skopiuj() const;
  Macierz  transpozycja() const;
  Wektor  operator * (const Wektor & W) const;
  double wyznacznik() const;
};

/* * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt */



/* Wczytuje 3 wektory i tworzy z nich macierz.*/

std::istream& operator >> (std::istream &Strm, Macierz &Mac);

/* Wsywietla na standardowym wyjsciu macierz.*/

std::ostream& operator << (std::ostream &Strm, const Macierz &Mac);


#endif
