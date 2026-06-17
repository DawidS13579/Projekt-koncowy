#include <iostream>
#include <string>

using namespace std;

struct Kategoria {
    string nazwa;
    double suma;
};

void dodaj_wydatek(Kategoria kategorie[], int liczba_kategorii, double &suma_calkowita) {
    int wybor;
    double kwota;

    cout << "\n--- DOSTEPNE KATEGORIE ---" << endl;
    for (int i = 0; i < liczba_kategorii; i++) {
        cout << i + 1 << ". " << kategorie[i].nazwa << endl;
    }

    cout << "Wybierz numer kategorii (1-" << liczba_kategorii << "): ";
    cin >> wybor;

    if (wybor < 1 || wybor > liczba_kategorii) {
        cout << "Blad! Nieznana kategoria." << endl;
        return;
    }

    cout << "Podaj kwote wydatku: ";
    cin >> kwota;

    if (kwota <= 0) {
        cout << "Blad! Kwota musi byc wieksza od zera." << endl;
        return;
    }

    kategorie[wybor - 1].suma += kwota;
    suma_calkowita += kwota;

    cout << "-> Wydatek pomyslnie dodany do kategorii: " << kategorie[wybor - 1].nazwa << "!" << endl;
}

void pokaz_podsumowanie(Kategoria kategorie[], int liczba_kategorii, double suma_calkowita) {
    cout << "\n--- PODSUMOWANIE WYDATKOW ---" << endl;
    if (suma_calkowita == 0) {
        cout << "Brak zapisanych wydatkow." << endl;
    } else {
        for (int i = 0; i < liczba_kategorii; i++) {
            cout << "- " << kategorie[i].nazwa << ": " << kategorie[i].suma << " PLN" << endl;
        }
        cout << "-----------------------------" << endl;
        cout << "Laczna suma wydatkow: " << suma_calkowita << " PLN" << endl;
    }
}

int main() {
    const int liczba_kategorii = 4;
    Kategoria kategorie[liczba_kategorii] = {
        {"Jedzenie", 0.0},
        {"Rachunki", 0.0},
        {"Higiena", 0.0},
        {"Przyjemnosci", 0.0}
    };

    double suma_calkowita = 0.0;
    char opcja;

    cout << "Witaj w Menedzerze Wydatkow!" << endl;

    while (true) {
        cout << "\n===================================" << endl;
        cout << "1. Dodaj nowy wydatek" << endl;
        cout << "2. Pokaz podsumowanie" << endl;
        cout << "3. Zakoncz program" << endl;
        cout << "Wybierz opcje (1-3): ";
        cin >> opcja;

        switch (opcja) {
            case '1':
                dodaj_wydatek(kategorie, liczba_kategorii, suma_calkowita);
                break;
            case '2':
                pokaz_podsumowanie(kategorie, liczba_kategorii, suma_calkowita);
                break;
            case '3':
                cout << "Zamykanie programu. Do widzenia!" << endl;
                return 0;
            default:
                cout << "Nieznana opcja. Sprobuj ponownie." << endl;
                break;
        }
    }

    return 0;
}