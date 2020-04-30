#include "UkladRownanLiniowych.hh"

std::istream &operator>>(std::istream &Strm, UkladRownanLiniowych &UklRown) {
    Macierz tmpA;
    Wektor tmpb;

    Strm >> tmpA;
    Strm >> tmpb;
    UklRown.set_A(tmpA);
    UklRown.set_b(tmpb);
    return Strm;
}

std::ostream &operator<<(std::ostream &Strm, const UkladRownanLiniowych &UklRown) {
    Strm << "Macierz A^T: " << std::endl;
    Strm << UklRown.get_A() << std::endl;
    Strm << "Wektor wyrazów wolnych b:" << std::endl;
    Strm << UklRown.get_b() << std::endl << std::endl;
    return Strm;
}

/*###########################################################*/

const Macierz &UkladRownanLiniowych::get_A() const {
    return A;
}

const Wektor &UkladRownanLiniowych::get_b() const {
    return b;
}

void UkladRownanLiniowych::set_A(const Macierz &AA) {
    A=AA;
}

void UkladRownanLiniowych::set_b(const Wektor &bb) {
    b=bb;
}

/*###########################################################*/
/* Rozwiazuje uklad rownan liniowych 3x3. (Dla innego rozmiaru nie bedzie daialac poprawnie)
 * Transponuje wejsciowa macierz i dziala na macierzy tranposnowanej do wejsciowej.
 * Zwraca wektor rozwiazan ukladu.
*/
Wektor UkladRownanLiniowych::Oblicz() const {
    Macierz  tmpA = get_A();
    Wektor tmpb = get_b();

    for (int i = 0; i < ROZMIAR; i++) {
        for (int j = i + 1; j < ROZMIAR; j++) {
            for (int k = 1; k < ROZMIAR; k++) {
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

    Wektor Wynik;
    Wynik[ROZMIAR - 1] = tmpb[ROZMIAR - 1] / tmpA[ROZMIAR - 1][ROZMIAR - 1];

    for (int i = ROZMIAR - 2; i >= 0; i--) {
        for (int j = ROZMIAR - 1; j >= i + 1; j--) {
            if (j == ROZMIAR - 1 ) {
                Wynik[i] = (tmpb[i] - Wynik[j] * tmpA[i][j] ) / tmpA[i][i];
            } else {
                Wynik[i] = (tmpb[i] - (Wynik[j] * tmpA[i][j] + Wynik[j + 1] * tmpA[i][j + 1])) / tmpA[i][i];
            }
        }
    }
    return Wynik;
}




