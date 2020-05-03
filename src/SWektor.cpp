#include "SWektor.h"

/* Konstruktory*/
template<class TYP, int Rozmiar>
SWektor<TYP, Rozmiar>::SWektor(TYP x, TYP y, TYP z) {

    dane[0] = x;
    dane[1] = y;
    dane[2] = z;
}
template <class TYP, int Rozmiar>
SWektor<TYP, Rozmiar>::SWektor(TYP wspolrzedne[ROZMIAR]) {
    for (int i=0; i < ROZMIAR; i++) {
        dane[i] = wspolrzedne[i];
    }
}
/*****************************************************************/
/* Wczytuje tablice wartowsci double lub liczb zespolonych, tworzy z nich wektor.*/
template <class TYP, int Rozmiar>
std::istream& operator >> (std::istream & Strm, SWektor<TYP, Rozmiar> &Wek){
    TYP wspolrzedne[ROZMIAR];
    for (int i = 0; i < ROZMIAR; i++){
        Strm >> wspolrzedne[i];
    }
    SWektor<TYP, Rozmiar> tmp(wspolrzedne);
    Wek = tmp;

    return Strm;
}

/* Wsywietla na standardowym wyjsciu wektor.*/
template <class TYP, int Rozmiar>
std::ostream& operator << (std::ostream & Strm, const SWektor<TYP, Rozmiar> & Wek){
    for (int i = 0; i < ROZMIAR; i++) {
        Strm << Wek[i] << " ";
    }
    return Strm;
}
/*****************************************************************/
/* operatory []*/
template <class TYP, int Rozmiar>
const TYP & SWektor<TYP, Rozmiar>::operator[](int indeks) const {
    if (indeks < 0 || indeks >= Rozmiar) {
        std::cerr << "blad: zly indeks wektora";
        exit(1);
    }
    return dane[indeks];
}

template <class TYP, int Rozmiar>
TYP & SWektor<TYP, Rozmiar>::operator[](int indeks) {
    if (indeks < 0 || indeks >= Rozmiar) {
        std::cerr << "blad: zly indeks wektora";
        exit(1);
    }
    return dane[indeks];
}

/*****************************************************************/
/* Suma dwóch wektrów*/
template <class TYP, int Rozmiar>
SWektor<TYP, Rozmiar> SWektor<TYP, Rozmiar>::operator + (const SWektor<TYP, Rozmiar> &W2) const {
    SWektor<TYP, Rozmiar> Wynikowy;
    for (int i = 0; i < Rozmiar; i++)
        Wynikowy[i] =  dane[i] + W2.dane[i] ;

    return Wynikowy;
}

/* Różnica dwóch wektrów*/
template <class TYP, int Rozmiar>
SWektor<TYP, Rozmiar> SWektor<TYP, Rozmiar>::operator - (const SWektor<TYP, Rozmiar> &W2) const {
    SWektor<TYP, Rozmiar> Wynikowy;
    for (int i = 0; i < Rozmiar; i++)
        Wynikowy[i] =  dane[i] - W2.dane[i] ;

    return Wynikowy;
}

/* Iloczyn skalarny */
template <class TYP, int Rozmiar>
TYP SWektor<TYP, Rozmiar>::operator * (const SWektor<TYP, Rozmiar> &W2) const {
    TYP Wynik;
    Wynik = 0;
    for (int i = 0; i < Rozmiar; i++)
        Wynik = Wynik + dane[i] * W2.dane[i];

    return Wynik;
}

/*****************************************************************/
/* Iloczyn Wektor * liczba */
template <class TYP, int Rozmiar>
SWektor<TYP, Rozmiar> SWektor<TYP, Rozmiar>::operator * (TYP liczba) const {
    SWektor<TYP, Rozmiar> Wynikowy;
    for (int i = 0; i < Rozmiar; i++)
        Wynikowy.dane[i] = dane[i] * liczba;

    return Wynikowy;
}

/* Iloraz Wektor / liczba */
template <class TYP, int Rozmiar>
SWektor<TYP, Rozmiar> SWektor<TYP, Rozmiar>::operator / (TYP liczba) {
    if (liczba != 0) {
        SWektor<TYP, Rozmiar> Wynikowy;
        for (int i = 0; i < Rozmiar; i++)
            Wynikowy.dane[i] = dane[i] / liczba;

        return Wynikowy;
    } else {
        std::cerr << "Błąd! Dzielisz wektor przez 0." << std::endl;
        exit(1);
    }
}





