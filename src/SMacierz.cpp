#include "SMacierz.h"
#include <SWektor.h>
/* Konstruktory*/
template <class TYP, int Rozmiar>
SMacierz<TYP, Rozmiar>::SMacierz() {
    for (int i = 0; i < ROZMIAR; i++) {
        SMacierz<TYP, Rozmiar>::tab[i] = SWektor<TYP, ROZMIAR>();
    }
}

template <class TYP, int Rozmiar>
SMacierz<TYP, Rozmiar>::SMacierz(SWektor<TYP, Rozmiar> Wiersze[ROZMIAR]) {

    for (int i = 0; i < ROZMIAR; i++) {
        SMacierz<TYP, Rozmiar>::tab[i] = Wiersze[i];
    }

}
/*****************************************************************/
/* Operatory []*/
template <class TYP, int Rozmiar>
SWektor<TYP, Rozmiar> & SMacierz<TYP, Rozmiar>::operator[] (int indeks) {
    if (indeks < 0 || indeks >= ROZMIAR) {
        std::cerr << "blad: zly indeks macierzy";
        exit(1);
    }
    return SMacierz<TYP,Rozmiar>::tab[indeks];
}
template <class TYP, int Rozmiar>
const SWektor<TYP, Rozmiar> & SMacierz<TYP, Rozmiar>::operator[] (int indeks) const {
    if (indeks < 0 || indeks >= ROZMIAR) {
        std::cerr << "blad: zly indeks macierzy";
        exit(1);
    }
    return SMacierz<TYP,Rozmiar>::tab[indeks];
}
/******************************************************************/
/* Tworzy kopie macierzy*/
template <class TYP, int Rozmiar>
SMacierz<TYP, Rozmiar> SMacierz<TYP, Rozmiar>::skopiuj() const {
    SMacierz<TYP, Rozmiar> kopia;

    for (int i = 0; i < ROZMIAR; i++) {
        kopia.tab[i] = tab[i];
    }
    return kopia;
}

/* Transponuje macierz*/
template <class TYP, int Rozmiar>
SMacierz<TYP, Rozmiar> SMacierz<TYP, Rozmiar>::transpozycja() {
    SMacierz<TYP, Rozmiar> Transponowana, tmp;

    tmp = SMacierz<TYP, Rozmiar>::skopiuj();

    for (int i = 0; i < ROZMIAR; i++) {
        for (int j = 0; j < ROZMIAR; j++) {
            Transponowana.tab[i][j] = tmp.tab[j][i];
        }
    }
    return Transponowana;
}

/* Iloczyn Macierzy i wektora. Zwraca wektor */
template <class TYP, int Rozmiar>
SWektor<TYP, Rozmiar> SMacierz<TYP, Rozmiar>::operator*(const SWektor<TYP, Rozmiar> &W) const {
    SWektor<TYP, Rozmiar> Wynikowy;

    for (int i = 0; i < ROZMIAR; i++) {
        for (int j = 0; j < ROZMIAR; j++) {
            Wynikowy[i] = Wynikowy[i] + W[j] * tab[i][j];
        }
    }
    return Wynikowy;
}

/* Oblicza wyznacznik macierzy, zwraca wartosc double - wyznacznik macierzy*/
template <class TYP, int Rozmiar>
double SMacierz<TYP, Rozmiar>::wyznacznik() const {
    SMacierz<TYP, Rozmiar>  tmp;
    tmp = SMacierz<TYP, Rozmiar>::skopiuj();

    double det = 1;
    int przestW = 0;

    for (int i = 0; i < ROZMIAR; i++) {
        for (int j = i + 1; j < ROZMIAR; j++) {
            for (int k = 1; k < ROZMIAR; k++) {
                if (tmp.tab[i][i] == 0) {
                    if (tmp.tab[k][i] != 0) {
                        std::swap(tmp.tab[i], tmp.tab[k]);
                        przestW++;
                        tmp.tab[j] = tmp.tab[j] - tmp.tab[i] * tmp.tab[j][i] / tmp.tab[i][i];
                    }
                } else {
                    tmp.tab[j] = tmp.tab[j] - tmp.tab[i] * tmp.tab[j][i] / tmp.tab[i][i];
                }
            }
        }
    }
    if (przestW % 2) det * -1;

    for(int i = 0; i < ROZMIAR; i++) {
        det = det * tmp.tab[i][i];
    }
    return det;
}

/*****************************************************************/
/* Operatory << >>*/
template <class TYP, int Rozmiar>
std::istream & operator >> (std::istream &Strm, SMacierz<TYP, Rozmiar> &Mac) {
    SWektor<TYP, Rozmiar> Wiersze[ROZMIAR];
    for(int i = 0; i < ROZMIAR; i++){
        Strm >> Wiersze[i];
        //std::cout << std::endl<<Wiersze[i]<< std::endl;
    }
    SMacierz<TYP, ROZMIAR> tmp( Wiersze);
     Mac = tmp.transpozycja();

    return Strm;
}
template <class TYP, int Rozmiar>
std::ostream& operator << (std::ostream &Strm, const SMacierz<TYP, Rozmiar> & Mac) {

    SMacierz<TYP, ROZMIAR> tmp;
    tmp = Mac;

    for (int i = 0; i < ROZMIAR; i++) {
        Strm << tmp.transpozycja()[i] << std::endl;
    }
    return Strm;
}
