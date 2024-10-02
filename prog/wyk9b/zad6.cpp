#include <iostream>
using namespace std;

// Funkcja szablonowa rosnoco, przyjmuje tablicę dowolnego typu i jej rozmiar
template <typename T>
void rosnoco(T tab[], int roz) {
    cout << " rosnaco "; // Wypisuje " rosnaco "
}

// Funkcja szablonowa malejaco, przyjmuje tablicę dowolnego typu i jej rozmiar
template <typename T>
void malejaco(T tab[], int roz) {
    cout << " malejaco "; // Wypisuje " malejaco "
}

// Funkcja szablonowa sortuj, przyjmuje tablicę dowolnego typu, jej rozmiar i wskaźnik na funkcję sortującą
template <typename T>
void sortuj(T tab[], int roz, void (*jak)(T tab[], int roz)) {
    cout << "sortuje 1wymiar typu " << typeid(T).name() << " ";
    // Wypisuje "sortuje 1wymiar typu" i nazwę typu T
    jak(tab, roz); // Wywołuje przekazaną funkcję sortującą
    cout << endl; // Wypisuje nową linię
}

// Funkcja przeciążona sortuj dla tablicy wskaźników na char
void sortuj(char* tab[], int roz) {
    cout << "sortuje tablice char* " << endl; // Wypisuje "sortuje tablice char*"
}

// Deklaracje tablic globalnych
int a[4];       // Tablica typu int
double b[5];    // Tablica typu double

int main() {
    // Wywołanie funkcji sortuj dla tablicy a typu int i funkcji rosnoco
    sortuj(a, 4, rosnoco); // Wypisuje "sortuje 1wymiar typu i rosnaco"

    // Wywołanie funkcji sortuj dla tablicy b typu double i funkcji malejaco
    sortuj(b, 5, malejaco); // Wypisuje "sortuje 1wymiar typu d malejaco"

    return 0;
}
