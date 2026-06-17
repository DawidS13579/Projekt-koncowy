#include <iostream>

using namespace std;

int main() {
    double jedzenie = 0;
    double rachunki = 0;
    double higiena = 0;
    double przyjemnosci = 0;
    double kwota;
    double budzet;
    int wybor;

    cout << "Podaj miesieczny budzet: ";
    cin >> budzet;

    while (true) {
        cout << "\n--- MENU ---" << endl;
        cout << "1. Dodaj wydatek" << endl;
        cout << "2. Pokaz podsumowanie" << endl;
        cout << "3. Wyzeruj dane" << endl;
        cout << "4. Wyjscie" << endl;
        cout << "Wybor: ";
        cin >> wybor;

        if (wybor == 1) {
            cout << "\nKategorie:" << endl;
            cout << "1. Jedzenie" << endl;
            cout << "2. Rachunki" << endl;
            cout << "3. Higiena" << endl;
            cout << "4. Przyjemnosci" << endl;

            int kategoria;
            cout << "Wybierz kategorie: ";
            cin >> kategoria;

            cout << "Podaj kwote: ";
            cin >> kwota;

            if (kategoria == 1)
                jedzenie += kwota;
            else if (kategoria == 2)
                rachunki += kwota;
            else if (kategoria == 3)
                higiena += kwota;
            else if (kategoria == 4)
                przyjemnosci += kwota;
            else {
                cout << "Bledna kategoria!" << endl;
                continue;
            }

            double suma = jedzenie + rachunki + higiena + przyjemnosci;

            cout << "\nWydatek dodany!" << endl;

            if (suma <= budzet)
                cout << "Pozostalo z budzetu: "
                     << budzet - suma << " PLN" << endl;
            else
                cout << "Przekroczono budzet o "
                     << suma - budzet << " PLN" << endl;
        }

        else if (wybor == 2) {
            double suma = jedzenie + rachunki + higiena + przyjemnosci;

            cout << "\n--- PODSUMOWANIE ---" << endl;
            cout << "Jedzenie: " << jedzenie << " PLN" << endl;
            cout << "Rachunki: " << rachunki << " PLN" << endl;
            cout << "Higiena: " << higiena << " PLN" << endl;
            cout << "Przyjemnosci: " << przyjemnosci << " PLN" << endl;
            cout << "Suma wydatkow: " << suma << " PLN" << endl;

            double maxKwota = jedzenie;
            string maxKategoria = "Jedzenie";

            if (rachunki > maxKwota) {
                maxKwota = rachunki;
                maxKategoria = "Rachunki";
            }

            if (higiena > maxKwota) {
                maxKwota = higiena;
                maxKategoria = "Higiena";
            }

            if (przyjemnosci > maxKwota) {
                maxKwota = przyjemnosci;
                maxKategoria = "Przyjemnosci";
            }

            cout << "Najwieksze wydatki: "
                 << maxKategoria
                 << " (" << maxKwota << " PLN)" << endl;

            if (suma <= budzet)
                cout << "Pozostalo z budzetu: "
                     << budzet - suma << " PLN" << endl;
            else
                cout << "Przekroczono budzet o "
                     << suma - budzet << " PLN" << endl;
        }

        else if (wybor == 3) {
            jedzenie = 0;
            rachunki = 0;
            higiena = 0;
            przyjemnosci = 0;

            cout << "Wszystkie dane zostaly wyzerowane." << endl;
        }

        else if (wybor == 4) {
            cout << "Koniec programu." << endl;
            break;
        }

        else {
            cout << "Bledny wybor!" << endl;
        }
    }

    return 0;
}