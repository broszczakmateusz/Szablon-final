#include "SUklad.cpp"
#include "rozmiar.h"
#include "LZespolona.hh"

template class SUklad<double, ROZMIAR>;
template std::istream& operator >> (std::istream & Strm, SUklad<double, ROZMIAR> &UklRown);
template std::ostream& operator << (std::ostream & Strm, const SUklad<double, ROZMIAR> & UklRown);

template class SUklad<LZespolona, ROZMIAR>;
template std::istream& operator >> (std::istream & Strm, SUklad<LZespolona, ROZMIAR> &UklRown);
template std::ostream& operator << (std::ostream & Strm, const SUklad<LZespolona, ROZMIAR> & UklRown);