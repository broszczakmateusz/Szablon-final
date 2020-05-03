#ifndef SZABLON_SUKLAD_H
#define SZABLON_SUKLAD_H

#include <iostream>
#include <SWektor.h>
#include <SMacierz.h>

/* KLasa modeluje pojecie szablonu dla ukladu rownan liczb rzeczywistych lub zespolonych, sklada sie z:
 *  - szablonu macierzy kwadratowej wspolczynnikow stojacych przy x_n
 *  - szablonu wektora wyrazow wolnych
 */
template <class TYP, int Rozmiar>
class SUklad {

    SMacierz<TYP,Rozmiar> A;
    SWektor<TYP,Rozmiar> b;

public:
    SUklad() {};
    SUklad(SMacierz<TYP,Rozmiar> AA, SWektor<TYP,Rozmiar> bb) : A(AA), b(bb) {};

    const SMacierz<TYP,Rozmiar> & get_A() const;
    const SWektor<TYP,Rozmiar> & get_b() const;
    void set_A(const SMacierz<TYP,Rozmiar> & AA);
    void set_b(const SWektor<TYP,Rozmiar> & bb);

    SWektor<TYP,Rozmiar> Oblicz() const;
};

/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt
 */
template <class TYP, int Rozmiar>
std::istream& operator >> (std::istream &Strm, SUklad<TYP,Rozmiar>&UklRown);

/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt
 */
template <class TYP, int Rozmiar>
std::ostream& operator << (std::ostream &Strm, const SUklad<TYP,Rozmiar> &UklRown);



#endif //SZABLON_SUKLAD_H
