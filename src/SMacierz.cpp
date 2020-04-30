//
// Created by mateusz on 24.04.2020.
//

#include "SMacierz.h"
#include <SWektor.h>

/* *  Tutaj nalezy zdefiniowac odpowiednie metody
 *  klasy Macierz, ktore zawieraja wiecej kodu
 *  niz dwie linijki.
 *  Mniejsze metody mozna definiwac w ciele klasy.*/


template <class TYP, int Rozmiar>
SMacierz<TYP, Rozmiar>::SMacierz() {
    for (int i = 0; i < ROZMIAR; i++) {
        SMacierz<TYP, Rozmiar>::tab[i] = SWektor<TYP, ROZMIAR>();
    }
}

template <class TYP, int Rozmiar>
SMacierz<TYP, Rozmiar>::SMacierz(SWektor<TYP, Rozmiar> Wie1, SWektor<TYP, Rozmiar> Wie2, SWektor<TYP, Rozmiar> Wie3) {

    SMacierz<TYP, Rozmiar>::tab[0] = Wie1;
    SMacierz<TYP, Rozmiar>::tab[1] = Wie2;
    SMacierz<TYP, Rozmiar>::tab[2] = Wie3;
}

/*****************************************************************/

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


/*****************************************************************/
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
TYP SMacierz<TYP, Rozmiar>::wyznacznik() const {
    SMacierz<TYP, Rozmiar>  tmp;
    tmp = SMacierz<TYP, Rozmiar>::skopiuj();
    LZespolona det(1,0);
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
    for(int i = 0; i < ROZMIAR; i++) {
        det = tmp.tab[i][i] * det;
    }

    if (przestW % 2)
        return det * -1;
    else
        return det;
}






template <class TYP, int Rozmiar>
std::istream & operator >> (std::istream &Strm, SMacierz<TYP, Rozmiar> &Mac) {
    SWektor<TYP, Rozmiar> Wie1, Wie2, Wie3;
    Strm >> Wie1;
    Strm >> Wie2;
    Strm >> Wie3;

/*    SMacierz<TYP, ROZMIAR> tmp( Wie1, Wie2, Wie3);
     Mac = tmp.transpozycja();*/

    return Strm;
}
template <class TYP, int Rozmiar>
std::ostream& operator << (std::ostream &Strm, const SMacierz<TYP, Rozmiar> & Mac) {
    
/*    for (int i = 0; i < ROZMIAR; i++) {
        Strm << Mac[i] << std::endl;
    }*/
    return Strm;
}
