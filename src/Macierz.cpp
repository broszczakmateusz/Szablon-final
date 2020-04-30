#include <SWektor.h>
#include "Macierz.hh"

/*
 *  Tutaj nalezy zdefiniowac odpowiednie metody
 *  klasy Macierz, ktore zawieraja wiecej kodu
 *  niz dwie linijki.
 *  Mniejsze metody mozna definiwac w ciele klasy.
 */

Macierz::Macierz() {
    for (int i = 0; i < ROZMIAR; i++) {
        Macierz::tab[i] = Wektor();
    }
}

Macierz::Macierz(Wektor Wie1, Wektor Wie2, Wektor Wie3) {

    Macierz::tab[0] = Wie1;
    Macierz::tab[1] = Wie2;
    Macierz::tab[2] = Wie3;
}

/*###########################################################*/

Wektor & Macierz::operator[] (int indeks) {
    if (indeks < 0 || indeks >= ROZMIAR) {
        std::cerr << "blad: zly indeks macierzy";
        exit(1);
    }
    return this->tab[indeks];
}

const Wektor & Macierz::operator[] (int indeks) const {
    if (indeks < 0 || indeks >= ROZMIAR) {
        std::cerr << "blad: zly indeks macierzy";
        exit(1);
    }
    return this->tab[indeks];
}

const Wektor &Macierz::get_wiersz(int indeks) const {
    return this->tab[indeks];
}

void Macierz::set_wiersz(const Wektor &bb){
   // get_wiersz();
   // tab = bb;
}

std::istream & operator >> (std::istream &Strm, Macierz &Mac) {
    Wektor Wie1, Wie2, Wie3;
    Strm >> Wie1;
    Strm >> Wie2;
    Strm >> Wie3;

    Macierz tmp( Wie1, Wie2, Wie3);
    Mac = tmp.transpozycja();

    return Strm;
}

std::ostream& operator << (std::ostream &Strm, const Macierz &Mac) {
    Macierz tmp;
    tmp = Mac.transpozycja();
        for (int i = 0; i < ROZMIAR; i++) {
            Strm << tmp[i] << std::endl;
        }
    return Strm;
}

/*###########################################################*/


/* Tworzy kopie macierzy*/

Macierz Macierz::skopiuj() const {
    Macierz kopia;

    for (int i = 0; i < ROZMIAR; i++) {
        kopia.tab[i] = tab[i];
    }
    return kopia;
}

/* Transponuje macierz*/

Macierz Macierz::transpozycja() const {
    Macierz Transponowana, tmp;

    tmp = Macierz::skopiuj();

    for (int i = 0; i < ROZMIAR; i++) {
        for (int j = 0; j < ROZMIAR; j++) {
            Transponowana.tab[i][j] = tmp.tab[j][i];
        }
    }
    return Transponowana;
}

/* Iloczyn Macierzy i wektora. Zwraca wektor */

Wektor Macierz::operator*(const Wektor &W) const {
    Wektor Wynikowy;

    for (int i = 0; i < ROZMIAR; i++) {
        for (int j = 0; j < ROZMIAR; j++) {
            Wynikowy[i] += W[j] * tab[i][j];
        }
    }
    return Wynikowy;
}

/* Oblicza wyznacznik macierzy, zwraca wartosc double - wyznacznik macierzy. */

double Macierz::wyznacznik() const {
    Macierz  tmp = Macierz::skopiuj();
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
    for(int i = 0; i < ROZMIAR; i++) {
        det *=  tmp.tab[i][i];
    }

    if (przestW % 2)
        return -det;
    else
        return det;
}



