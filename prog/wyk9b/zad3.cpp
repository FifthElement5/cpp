#include <iostream>

using namespace std;

// Definicja klasy Ulamek reprezentującej ułamek
class Ulamek {
    int l, m; // Licznik (l) i mianownik (m)
public:
    // Konstruktor z parametrami domyślnymi
    Ulamek(int i = 1, int j = 1) : l(i), m(j) {}

    // Metoda wypisz() do wypisywania ułamka
    void wypisz() const { cout << l << "/" << m << endl; }

    // Deklaracja przyjaciela operatora > dla porównywania ułamków
    friend int operator >(Ulamek, Ulamek);
};

// Definicja operatora > dla klasy Ulamek
int operator >(Ulamek a, Ulamek b)
{
    // Porównuje dwa ułamki na podstawie iloczynu przekątnych
    if (a.l * b.m > b.l * a.m) return 1;
    else return 0;
}

// Szablon funkcji wieksza dla dowolnego typu
template <typename jakis_typ>
jakis_typ wieksza(jakis_typ a, jakis_typ b)
{
    // Zwraca większą z dwóch wartości na podstawie operatora >
    return (a > b) ? a : b;
}

// Deklaracje obiektów klasy Ulamek
Ulamek u1(1, 3), u2(2, 9), u3;

int main()
{
    // Wywołanie funkcji szablonowej wieksza dla obiektów klasy Ulamek

    u3 = wieksza(u1, u2);
    u3.wypisz();
    return 0;
}
