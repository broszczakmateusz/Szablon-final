#ifndef LZESPOLONA_HH
#define LZESPOLONA_HH

#include <iostream>
/*!
 *  Plik zawiera definicje struktury LZesplona oraz zapowiedzi
 *  przeciazen operatorow arytmetycznych dzialajacych na tej 
 *  strukturze.
 */

/*!
 * Modeluje pojecie liczby zespolonej
 */
struct  LZespolona {
  double   re;    /*! Pole repezentuje czesc rzeczywista. */
  double   im;    /*! Pole repezentuje czesc urojona. */

  LZespolona();
  LZespolona(double _re, double _im);
  LZespolona(LZespolona const &L2);
  explicit LZespolona(double _re);

    LZespolona &  operator = ( double _re);
    LZespolona  operator * (double skl2);

    /* Konstruktor kopiujacy nie dziala przy wczytaniu wektora, wiec uzyam tego przeciazenia*/
    LZespolona & operator = (const LZespolona& L);
};

std::istream & operator >> (std::istream & Strm, LZespolona &);
std::ostream & operator << (std::ostream & Strm, const LZespolona &out);

LZespolona  operator + (LZespolona  Skl1,  LZespolona  Skl2);
LZespolona  operator - (LZespolona  Skl1,  LZespolona  Skl2);

LZespolona  operator * (LZespolona  Skl1,  LZespolona  Skl2);
LZespolona  operator * (LZespolona  Skl1,  double skl2);
double  operator * (double skl1, LZespolona  Skl2);

LZespolona  operator / (LZespolona  Skl1,  LZespolona  Skl2);
LZespolona  operator / (LZespolona  Skl1,  double skl2);

bool operator == (const LZespolona&  L1,  LZespolona  L2);
bool operator != (const LZespolona&  L1,  const LZespolona&  L2);

bool operator == (const LZespolona&  L1,  double l2);
bool operator != (const LZespolona&  L1,  double l2);

LZespolona Sprzerzenie (LZespolona);
double Modul2(LZespolona);

#endif
