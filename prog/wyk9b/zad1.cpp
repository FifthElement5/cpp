#include <iostream>

using namespace std;

// Szablon funkcji porównującej dwie wartości i zwracającej większą z nich
template <typename T>
T wieksza(T a, T b)
{
	static int i = 0; // Zmienna statyczna do zliczania wywołań funkcji szablonowej
	i++;
	cout << "szablon " << i << endl;
	return (a > b) ? a : b; // Zwraca większą z dwóch wartości
}

// Specjalizacja funkcji porównującej dwie wartości typu float
float wieksza(float i, float j)
{
	cout << "specjalizacja " << endl;
	return (i > j) ? i : j; // Zwraca większą z dwóch wartości typu float
}

// Zmienne globalne
int a = 4, b = 11;
float x = (float)22, y = (float)33.3;

int main()
{
	// Wywołanie funkcji szablonowej z typem int
	cout << wieksza(a, b) << endl;
	// Wywołanie specjalizacji funkcji z typem float
	cout << wieksza(x, y) << endl;
	// Wywołanie funkcji szablonowej z typem char
	cout << wieksza('A', 'Z') << endl;
	// Kolejne wywołanie funkcji szablonowej z typem int
	wieksza(2, 2);
	return 0;
}
