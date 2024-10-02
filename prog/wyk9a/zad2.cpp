#include <iostream>
#include <typeinfo>

using namespace std;

//deklaracja klasy szblonowej kontener
template <typename T>
class Kontener
{
    unsigned int roz;      //romziar kontenera
    T* wsk;                //wskaznk na tablice elemntow typu T
    static int ile;         // statyczna zmienna do sledzenia ilosci utworzonych kontenerow
public:
    // konstruktor domyslny z argumentem
    Kontener(unsigned int = 0);
    // konstruktor kopiujacy
    Kontener(const Kontener&);

    //operator przypisania
    Kontener& operator=(const Kontener<T>&);
    //przyjazn funkcji
    friend ostream& operator<<(ostream& out, const Kontener<T>& k)
    {
        for (unsigned int i = 0; i < k.roz; i++)
            out << k.wsk[i] << " , ";
        return out;
    }

    // stayczna medoda klasy do pobrania ilosci utworzonyhc koneterow
    static int dajIle();

    //destrukor
    ~Kontener() {
        //zwiekszenie licznika
        ile++;
        //wyswietlenie typu T
        cout << "Destruktor typu = " << typeid(T).name() << endl;
        // zwolnienie pamieci
        delete[] wsk;

    }
};


// inicjalizacja statycznej zmiennej klasy kontener
template <typename T>
int Kontener<T>::ile = 0;

//implementacja konstruktora kontener

template <typename T>
Kontener<T>::Kontener(unsigned int r) : roz{ r }, wsk{ new T[roz] } {
    for (unsigned int i = 0; i < roz; i++) wsk[i] = 0;
    ile++;
}
//implementacja konstruktora kopiujacego Kontener
template <typename T>
Kontener<T>::Kontener(const Kontener& k) : roz{ k.roz }, wsk{ new T[roz] } {
    for (unsigned int i = 0; i < roz; i++) wsk[i] = k.wsk[i];
    ile++;
}

//implementacja operatora przypisania
template <typename T>
Kontener<T>& Kontener<T>::operator=(const Kontener<T>& k) {
    if (this != &k) { // Sprawdzenie, czy nie jest to przypisanie samego sobie
        if (roz != k.roz) {
            delete[] wsk;
            roz = k.roz;
            wsk = new T[roz];
        }
        for (unsigned int i = 0; i < roz; i++) wsk[i] = k.wsk[i];
    }
    return *this;
}

//implementacja statycznej metody dajIle()
template<typename T>
int Kontener<T>::dajIle() {
    return ile;
}

Kontener<int> kInt1(5), kInt2(7);
Kontener<double> kDouble1(2), kDouble2(5), kDouble3, kDouble4;
Kontener<unsigned int> kUInt1(2);

int main()
{
    //wyswietlanie zawartosci konetnero
    cout << kInt1 << endl;
    cout << kDouble1 << endl;

    // wywolywanie metody dajile()
    cout << kDouble1.dajIle() << endl;
    // wywolanie metody bez potrzbay posiadania obketu
    cout << Kontener<double>::dajIle() << endl;

    return 0;
}

