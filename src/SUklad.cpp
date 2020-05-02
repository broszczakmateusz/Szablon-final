//
// Created by mati on 30.04.2020.
//

#include "SUklad.h"

template <class TYP, int Rozmiar>
std::istream &operator>>(std::istream &Strm, SUklad<TYP,Rozmiar> &UklRown) {
    SMacierz<TYP,Rozmiar> tmpA;
    SWektor<TYP,Rozmiar> tmpb;

    Strm >> tmpA;
    Strm >> tmpb;
    UklRown.set_A(tmpA);
    UklRown.set_b(tmpb);
    return Strm;
}
template <class TYP, int Rozmiar>
std::ostream &operator<<(std::ostream &Strm, const SUklad<TYP,Rozmiar> &UklRown) {
    Strm << "Macierz A^T: " << std::endl;
    Strm << UklRown.get_A() << std::endl;
    Strm << "Wektor wyrazów wolnych b:" << std::endl;
    Strm << UklRown.get_b() << std::endl << std::endl;
    return Strm;
}

/*###########################################################*/
template <class TYP, int Rozmiar>
const SMacierz<TYP,Rozmiar> &SUklad<TYP,Rozmiar>::get_A() const {
    return A;
}
template <class TYP, int Rozmiar>
const SWektor<TYP,Rozmiar> &SUklad<TYP,Rozmiar>::get_b() const {
    return b;
}
template <class TYP, int Rozmiar>
void SUklad<TYP,Rozmiar>::set_A(const SMacierz<TYP,Rozmiar> &AA) {
    A=AA;
}
template <class TYP, int Rozmiar>
void SUklad<TYP,Rozmiar>::set_b(const SWektor<TYP,Rozmiar> &bb) {
    b=bb;
}

/*###########################################################*/
/* Rozwiazuje uklad rownan liniowych 3x3. (Dla innego rozmiaru nie bedzie daialac poprawnie)
 * Transponuje wejsciowa macierz i dziala na macierzy tranposnowanej do wejsciowej.
 * Zwraca wektor rozwiazan ukladu.
*/
template <class TYP, int Rozmiar>
SWektor<TYP,Rozmiar> SUklad<TYP,Rozmiar>::Oblicz() const {
    SMacierz<TYP,Rozmiar>  tmpA = get_A();
    SWektor<TYP,Rozmiar> tmpb = get_b();

    for (int i = 0; i < ROZMIAR; i++) {
        for (int j = i + 1; j < ROZMIAR; j++) {
            for (int k = i + 1; k < ROZMIAR; k++) {
                if (tmpA[i][i] == 0) {
                    if (tmpA[k][i] != 0) {
                        std::swap(tmpA[i], tmpA[k]);
                        std::swap(tmpb[i], tmpb[k]);

                        tmpb[j] = tmpb[j] - tmpb[i] * tmpA[j][i] / tmpA[i][i];
                        tmpA[j] = tmpA[j] - tmpA[i] * tmpA[j][i] / tmpA[i][i];
                    }
                } else {
                    tmpb[j] = tmpb[j] - tmpb[i] * tmpA[j][i] / tmpA[i][i];
                    tmpA[j] = tmpA[j] - tmpA[i] * tmpA[j][i] / tmpA[i][i];
                    break;
                }
            }
        }
    }
    SWektor<TYP,Rozmiar> Wynik;
    Wynik[ROZMIAR - 1] = tmpb[ROZMIAR - 1] / tmpA[ROZMIAR - 1][ROZMIAR - 1];

    for (int i = ROZMIAR - 1; i >= 0; i--) {
        if (i != ROZMIAR - 1) {
            Wynik[i] = tmpb[i];

            for (int j = ROZMIAR - 1 ; j >= i + 1 ; j--) {
                Wynik[i] = (Wynik[i] - (tmpA[i][j] * Wynik[j]));
            }
            Wynik[i] = Wynik[i] / tmpA[i][i];
        }
    }

    return Wynik;
}




