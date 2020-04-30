//
// Created by mateusz on 24.04.2020.
//
#include "SMacierz.cpp"
#include "rozmiar.h"
#include "LZespolona.hh"
#include <iostream>

template <> class SMacierz<double, ROZMIAR>;
template std::istream& operator >> (std::istream & Strm, SMacierz<double, ROZMIAR> &Mac);
template std::ostream& operator << (std::ostream & Strm, const SMacierz<double, ROZMIAR> & Mac);


template class SMacierz<LZespolona, ROZMIAR>;
template std::istream& operator >> (std::istream & Strm, SMacierz<LZespolona, ROZMIAR> &Mac);
template std::ostream& operator << (std::ostream & Strm, const SMacierz<LZespolona, ROZMIAR> & Mac);

