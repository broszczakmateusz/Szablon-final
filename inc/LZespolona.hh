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
  LZespolona &  operator = (const LZespolona  &Skl2);
  LZespolona &  operator = ( double podstawiana);

    LZespolona  operator * (double skl2);
};

//LZespolona Utworz (double, double);
//LZespolona Wczytaj (void);

/*
  Dalej powinny pojawic sie zapowiedzi definicji przeciazen operatorow
 */

std::istream & operator >> (std::istream & Strm, LZespolona &);
std::ostream & operator << (std::ostream & Strm, const LZespolona &out);
LZespolona  operator + (LZespolona  Skl1,  LZespolona  Skl2);
LZespolona  operator - (LZespolona  Skl1,  LZespolona  Skl2);
LZespolona  operator * (LZespolona  Skl1,  LZespolona  Skl2);

LZespolona  operator / (LZespolona  Skl1,  LZespolona  Skl2);
LZespolona  operator / (LZespolona  Skl1,  double skl2);
bool operator == (LZespolona  L1,  LZespolona  L2);
bool operator != (LZespolona  L1,  LZespolona  L2);
bool operator == (LZespolona  L1,  double l2);
bool operator != (LZespolona  L1,  double l2);
LZespolona Sprzerzenie (LZespolona);
double Modul2(LZespolona);


#endif
