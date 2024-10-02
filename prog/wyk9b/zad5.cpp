#include <iostream>

using namespace std;

// Szablon funkcji wieksza przyjmujący dwa argumenty tego samego typu
template <typename jakis_typ>
jakis_typ wieksza(jakis_typ a, jakis_typ b)
{
    cout << "szablon " << endl;
    return (a > b) ? a : b; // Zwraca większą z dwóch wartości
}

// Specjalizacja funkcji wieksza dla typu float
float wieksza(float i, float j)
{
    cout << "specjalizacja " << endl;
    return (i > j) ? i : j; // Zwraca większą z dwóch wartości typu float
}

// Deklaracje zmiennych globalnych
int a = 4, b = 11;       // Zmienne typu int
float x = 22, y = 33.3;  // Zmienne typu float

int main()
{
    // Wywołanie funkcji szablonowej wieksza z argumentami typu int
    cout << wieksza(a, b) << endl; // Wypisuje "szablon" i zwraca 11

    // Wywołanie specjalizacji funkcji wieksza z argumentami typu float
    cout << wieksza(x, y) << endl; // Wypisuje "specjalizacja" i zwraca 33.3

    // Wywołanie funkcji szablonowej wieksza z argumentami typu char
    cout << wieksza('A', 'Z') << endl; // Wypisuje "szablon" i zwraca 'Z'

    // Wywołanie funkcji szablonowej wieksza z argumentami typu int (nie wypisuje wyniku, bo nie ma cout)
    wieksza(2, 2); // Wypisuje "szablon", ale wynik nie jest wypisywany

    return 0;
}
