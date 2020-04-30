#ifndef UKLADROWNANLINIOWYCH_HH
#define UKLADROWNANLINIOWYCH_HH

#include <iostream>
#include "Macierz.hh"
#include "Wektor.hh"


/* KLasa modeluje pojecie ukladu rownan, sklada sie z:
 *  - macierzy kwadratowej wspolczynnikow stojacych przy x_n
 *  - wektora wyrazow wolnych
 */
class UkladRownanLiniowych {

    Macierz A;
    Wektor b;

  public:
    UkladRownanLiniowych() {};
    UkladRownanLiniowych(Macierz AA, Wektor bb) : A(AA), b(bb) {};

    const Macierz & get_A() const;
    const Wektor & get_b() const;
    void set_A(const Macierz & AA);
    void set_b(const Wektor & bb);

    Wektor Oblicz() const;
};


/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt 
 */
std::istream& operator >> (std::istream &Strm, UkladRownanLiniowych &UklRown);

/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt 
 */
std::ostream& operator << (std::ostream &Strm, const UkladRownanLiniowych &UklRown);


#endif
