#include <iostream>

class punktND {
private:
    int n; // Liczba wymiarów
    double* wspolrzedne; // Tablica przechowująca współrzędne

public:
    // Konstruktor
    punktND(int wymiary) {
        n = wymiary;
        wspolrzedne = new double[n]; // Rezerwacja pamięci dla współrzędnych
        for (int i = 0; i < n; ++i) {
            wspolrzedne[i] = 0.0; // Inicjalizacja współrzędnych wartościami domyślnymi (0)
        }
    }

    // Destruktor
    ~punktND() {
        delete[] wspolrzedne; // Zwolnienie zaalokowanej pamięci
    }

    // Metoda ustawiająca współrzędne
    void ustawWspolrzedne(double* noweWspolrzedne) {
        for (int i = 0; i < n; ++i) {
            wspolrzedne[i] = noweWspolrzedne[i];
        }
    }

    // Metoda zwracająca współrzędne
    double* pobierzWspolrzedne() {
        return wspolrzedne;
    }

    // Metoda wyświetlająca współrzędne
    void wyswietlWspolrzedne() {
        std::cout << "(";
        for (int i = 0; i < n; ++i) {
            std::cout << wspolrzedne[i];
            if (i < n - 1) {
                std::cout << ", ";
            }
        }
        std::cout << ")" << std::endl;
    }
};

int main() {
    // Utworzenie obiektu punktND
    punktND punkt3D(5); // Punkty w 3 wymiarach

    // Ustawienie współrzędnych
    double wspolrzedne3D[] = {1.0, 2.0, 3.0};
    punkt3D.ustawWspolrzedne(wspolrzedne3D);

    // Wyświetlenie współrzędnych
    std::cout << "Wspolrzedne punktu 3D: ";
    punkt3D.wyswietlWspolrzedne();

    return 0;
}
