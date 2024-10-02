#include <iostream>

using namespace std;

// Klasa szablonowa Punkt2D reprezentująca punkt w przestrzeni 2D
template <typename T>
class Punkt2D
{
protected:
	T x, y; // Współrzędne x i y
public:
	// Konstruktor inicjujący współrzędne punktu
	Punkt2D(T _x, T _y) : x{ _x }, y{ _y } { }

	// Konstruktor domyślny, inicjujący współrzędne punktu wartościami domyślnymi (1, 1)
	Punkt2D() : x{ 1 }, y{ 1 } { }

	// Metody dostępowe do współrzędnych x i y
	T getX() { return x; }
	T getY() { return y; }

	// Metody ustawiające współrzędne x i y
	void setX(T i) { x = i; }
	void setY(T j) { y = j; }

	// Metoda wypisująca współrzędne punktu na standardowe wyjście
	void wypisz() {
		cout << "x = " << x << ", y = " << y;
	}
};

// Klasa szablonowa Punkt3D dziedzicząca publicznie po Punkt2D<T>
template<typename T>
class Punkt3D : public Punkt2D<T>
{
	T z; // Trzecia współrzędna z
public:
	// Konstruktor inicjujący współrzędne x, y i z punktu 3D
	Punkt3D(T _x, T _y, T _z) : Punkt2D<T>(_x, _y), z{ _z } { }

	// Konstruktor domyślny, inicjujący współrzędną z wartością domyślną (1)
	Punkt3D() : z{ 1 } { }

	// Metoda dostępu do współrzędnej z
	T getZ() { return z; }

	// Metoda ustawiająca współrzędną z
	void setZ(T i) { z = i; }

	// Metoda wypisująca współrzędne punktu 3D na standardowe wyjście
	void wypisz() {
		Punkt2D<T>::wypisz(); // Wywołanie metody wypisz z klasy bazowej Punkt2D
		cout << ", z = " << z << endl;
	}
};

// Utworzenie obiektu p1 typu Punkt2D<int> o współrzędnych (3, 6)
Punkt2D<int> p1(3, 6);

// Utworzenie obiektu p2 typu Punkt3D<double> o współrzędnych (4.4, 4.7, 6.77)
Punkt3D<double> p2(4.4, 4.7, 6.77);

// Funkcja główna programu
int main()
{
	// Wywołanie metody wypisz dla obiektu p1 (Punkt2D<int>)
	p1.wypisz();
	cout << endl << endl;

	// Wywołanie metody wypisz dla obiektu p2 (Punkt3D<double>)
	p2.wypisz();
	cout << endl << endl;

	return 0;
}
