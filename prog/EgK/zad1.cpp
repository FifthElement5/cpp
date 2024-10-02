#include <iostream>
#include <typeinfo>
#include <stdexcept> // do obsługi wyjątków

using namespace std;

// szablon klasy Kontener
template <typename T>
class Kontener {
    unsigned int roz; // rozmiar kontenera
    T* wsk;           // wskaźnik do dynamicznej tablicy typu T
public:
    // konstruktor domyślny z argumentami
    Kontener(unsigned int = 0);
    // konstruktor kopiujący
    Kontener(const Kontener&);
    // operator przypisania
    Kontener& operator=(const Kontener<T>&);
    // zaprzyjaźniony operator dla kontenera
    friend ostream& operator<<(ostream& out, const Kontener<T>& k) {
        for (unsigned int i = 0; i < k.roz; i++)
            out << k.wsk[i] << " , ";
        return out;
    }

    // destruktor
    ~Kontener() {
        // wypisuje typ elementów
        cout << "Destruktor typu = " << typeid(T).name() << endl;
        // usuwa dynamicznie alokowaną tablicę
        delete[] wsk;
    }

    // funkcja szukajMax
    T szukajMax() const {
        if (roz == 0) {
            throw runtime_error("Kontener jest pusty");
        }
        T maxElement = wsk[0];
        for (unsigned int i = 1; i < roz; i++) {
            if (wsk[i] > maxElement) {
                maxElement = wsk[i];
            }
        }
        return maxElement;
    }

    // operator indeksowania []
    T& operator[](unsigned int index) {
        if (index >= roz) {
            throw out_of_range("Indeks poza zakresem");
        }
        return wsk[index];
    }

    const T& operator[](unsigned int index) const {
        if (index >= roz) {
            throw out_of_range("Indeks poza zakresem");
        }
        return wsk[index];
    }
};

// definicja konstruktora domyślnego
template <typename T>
Kontener<T>::Kontener(unsigned int r) : roz{ r }, wsk{ new T[roz] } {
    for (unsigned int i = 0; i < roz; i++) wsk[i] = 0;
}

// definicja konstruktora kopiującego
template <typename T>
Kontener<T>::Kontener(const Kontener& k) : roz{ k.roz }, wsk{ new T[roz] } {
    for (unsigned int i = 0; i < roz; i++) wsk[i] = k.wsk[i];
}

// definicja operatora przypisania
template <typename T>
Kontener<T>& Kontener<T>::operator=(const Kontener<T>& k) {
    if (this != &k) { // Sprawdzenie, czy nie jest to przypisanie samego sobie
        if (roz != k.roz) {
            delete[] wsk;  // usuwa starą tablicę
            roz = k.roz;   // aktualizuje rozmiar
            wsk = new T[roz]; // alokuje nową tablicę
        }
        for (unsigned int i = 0; i < roz; i++) wsk[i] = k.wsk[i];
    }
    return *this;
}

// tworzenie obiektów klasy Kontener dla różnych typów
Kontener<int> kInt1(5), kInt2(7);
Kontener<double> kDouble1(2), kDouble2(5);
Kontener<unsigned int> kUInt1(2);

int main() {
    cout << kInt1 << endl;
    cout << kDouble2 << endl;

    try {
        cout << "Największy element w kInt1: " << kInt1.szukajMax() << endl;
        cout << "Największy element w kDouble2: " << kDouble2.szukajMax() << endl;
    } catch (const runtime_error& e) {
        cout << "Błąd: " << e.what() << endl;
    }

    // Użycie operatora []
    kInt1[2] = 10;
    cout << "kInt1[2] po zmianie: " << kInt1[2] << endl;

    return 0;
}
