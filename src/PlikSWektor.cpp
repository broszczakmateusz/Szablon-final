//
// Created by mateusz on 24.04.2020.
//
#include "SWektor.cpp"
#include "rozmiar.h"
#include "LZespolona.hh"

template class SWektor<double, ROZMIAR>;

template std::istream& operator >> (std::istream & Strm, SWektor<double, ROZMIAR> &Wek);
template std::ostream& operator << (std::ostream & Strm, const SWektor<double, ROZMIAR> & Wek);


template class SWektor<LZespolona, ROZMIAR>;

template std::istream& operator >> (std::istream & Strm, SWektor<LZespolona, ROZMIAR> &Wek);
template std::ostream& operator << (std::ostream & Strm, const SWektor<LZespolona, ROZMIAR> & Wek);

//template <> LZespolona SWektor<LZespolona, ROZMIAR>::dlugosc() const;