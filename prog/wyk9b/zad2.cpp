#include <iostream>
using namespace std;

// Szablon funkcji sortuj dla jednowymiarowej tablicy dowolnego typu
template <typename T>
void sortuj(T tab[], int roz)
{
    cout << "sortuje 1wymiar typu " << typeid(T).name() << endl;
}

// Szablon funkcji sortuj dla dwuwymiarowej tablicy o drugim wymiarze wielkości 5
template <typename T>
void sortuj(T tab[][5], int roz)
{
    cout << "sortuje 2wymiar typu " << typeid(T).name() << endl;
}

// Specjalizacja funkcji sortuj dla tablicy wskaźników na char
void sortuj(char * tab[], int roz)
{
    cout << "sortuje tablice char* " << endl;
}

// Deklaracje zmiennych globalnych
int a[4];            // Jednowymiarowa tablica typu int
double b[5];         // Jednowymiarowa tablica typu double
char* c[7];          // Jednowymiarowa tablica wskaźników na char (char*)
double d[4][5];      // Dwuwymiarowa tablica typu double o drugim wymiarze wielkości 5

int main()
{
    // Wywołanie funkcji sortuj dla jednowymiarowej tablicy typu int
    sortuj(a, 4);
    // Wywołanie funkcji sortuj dla jednowymiarowej tablicy typu double
    sortuj(b, 5);
    // Wywołanie specjalizacji funkcji sortuj dla tablicy wskaźników na char
    sortuj(c, 7);
    // Wywołanie funkcji sortuj dla dwuwymiarowej tablicy typu double
    sortuj(d, 4);
    return 0;
}
