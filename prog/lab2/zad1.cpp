#include <iostream>
using namespace std;

void referencje(int& x)
{
    x += 2;
}

void wskaznik(int* wskX)
{
    *wskX += 2;

}

int main()
{
    int x = -1;
    int* wskX = &x;
    // cout << "Liczba calkowita " << x << endl;
    // referencje(x);
    // cout << "Liczba zwiekszona: " << x << endl;

    // cout << endl;
    cout << "adres zmiennej x " << wskX << endl;
    cout << "Wartosc wskaznika przed zwiekszniem " << *wskX << endl;
    wskaznik(wskX);
    cout << "Liczba calkowita po wskazniku " << *wskX << endl;

}
