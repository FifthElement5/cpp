#include <iostream>

using namespace std;

class Punkt2D {
    int x, y;
public:
    // konstruktor
    Punkt2D(int _x = 0, int _y = 0) : y{_y}, x{_x} {}

    // przeladowanie operator wyjscia
    friend ostream& operator<<(ostream& ekran, const Punkt2D& a);

    // przeladowanie operator wejscia
    friend istream& operator>>(istream& klaw, Punkt2D& a);
};

Punkt2D p1(1, 1);
Punkt2D p2, p3;

int main() {
    cout << p1;
    cin >> p3;
    cout << p3; // Dodano, aby zobaczyć wynik wprowadzonych danych
    return 0;
}

// Definicja operatora << dla klasy Punkt2D
ostream& operator<<(ostream& ekran, const Punkt2D& a) { // zmieniono przekazywanie przez wartość na referencję const
    ekran << "x= " << a.x << " y= " << a.y << endl; // Dodano spację po 'x='
    return ekran;
}

// Definicja operatora >> dla klasy Punkt2D
istream& operator>>(istream& klaw, Punkt2D& a) {
    cout << "podaj punkt x ";
    klaw >> a.x;
    cout << "podaj punkt y ";
    klaw >> a.y;
    return klaw;
}
