#include <iostream>

using namespace std;

// Szablon funkcji szablonF, przyjmującej dwa argumenty różnego typu T1 i T2, zwracającej wartość typu T2
template <typename T1, typename T2>
T2 szablonF(T1 a, T2 b)
{
    T2 tmp; // Tworzy tymczasową zmienną typu T2
    return tmp; // Zwraca tymczasową zmienną
}

// Szablon funkcji szablonF2, przyjmującej dwa argumenty tego samego typu T1 i zwracającej wartość typu T2
template <typename T1, typename T2>
T2 szablonF2(T1 a, T1 b)
{
    T2 tmp; // Tworzy tymczasową zmienną typu T2
    return tmp; // Zwraca tymczasową zmienną
}

int main()
{
    // Wywołanie funkcji szablonF2 z argumentami 3 i 4 typu int
    // Kompilator dedukuje typy: T1 jako int, T2 jako domyślny typ zwracany (w tym przypadku int)
    cout << szablonF2<int, int>(3, 4) << endl; // Wypisuje wynik działania funkcji szablonF2

    return 0;
}
