#include <iostream>
#include <typeinfo>

using namespace std;

//szablon klasy Kontener
template <typename T>
class Kontener
{
    unsigned int roz; // romzair kontenera
    T* wsk;            // wskaznik do dynamicznje tablicy typu T
public:
    // konstruktor domyslny z argumentami
    Kontener(unsigned int = 0);
    // konstruktor kopiujacy
    Kontener(const Kontener&);
    // operator przypisania
    Kontener& operator=(const Kontener<T>&);
    // zaprzyjazniony operator dla konetenera
    friend ostream& operator<<(ostream& out, const Kontener<T>& k){
        for (unsigned int i = 0; i < k.roz; i++)
            out << k.wsk[i] << " , ";
        return out;
    }

    // destruktor
    ~Kontener() {
        // wypisuje typ elementow
        cout << "Destruktor typu = " << typeid(T).name() << endl;
        // usuwa dynamicznie alokowana tablice
        delete[] wsk;

    }
};

// definicja konstruktora domyslenego
template <typename T>
Kontener<T>::Kontener(unsigned int r) :roz{ r }, wsk{ new T[roz] } {
    for (unsigned int i = 0; i < roz; i++) wsk[i] = 0;
}

//definicja konstruktora kopiujacego
template <typename T>
Kontener<T>::Kontener(const Kontener& k) : roz{ k.roz }, wsk{ new T[roz] } {
    for (unsigned int i = 0; i < roz; i++) wsk[i] = k.wsk[i];
}


//definicja opartora przypisania
template <typename T>
Kontener<T>& Kontener<T>::operator=(const Kontener<T>& k) {
    if (this != &k) { // Sprawdzenie, czy nie jest to przypisanie samego sobie
        if (roz != k.roz) {
            delete[] wsk;  // usuwa stra tablice
            roz = k.roz;   // aktualny rozmiar
            wsk = new T[roz]; // alokuje nowa tablice
        }
        for (unsigned int i = 0; i < roz; i++) wsk[i] = k.wsk[i];
    }
    return *this;
}

// tworzenie obiektow klasy Kontener dla roznych typow
 Kontener<int> kInt1(5), kInt2(7);
 Kontener<double> kDouble1(2), kDouble2(5);
 Kontener<unsigned int> kUInt1(2);

int main()
{
    cout << kInt1<< endl;
    cout << kDouble2 << endl;
}
