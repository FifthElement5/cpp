#include <iostream>
#include <initializer_list>

using namespace std;

class PunktND {
    int roz;                //liczba wymiarów punktu
    int* wsk;               //wskaznik do tablicy przechowujacej wsplorzedne punktu
    static int liczba;      //liczba utworzonych obiektow klasy PunktND
    static long int pamiec; //calkowita ilosc pamieci zajmowana przez obiekty klasy PunktND
public:
    // konstruktro z lista inicjalizacyjna
    PunktND(initializer_list<int> n);

    // konstruktor z jednym argumentem - liczba wymiarow
    PunktND(int i) :roz{ i}, wsk{ new int[roz]} {liczba++; pamiec += (sizeof(int) * roz);}

    // operator przypisania
    PunktND& operator=(const PunktND& p);

    // konstruktor kopiujacy
    PunktND(const PunktND& p);

    //destruktor
    ~PunktND() {if (!wsk) delete[]wsk; }

    // metoda wypisujaca wspolrzedne punktu
    void out() const
    {
        for (int i = 0; i < roz; i++)
        {
            cout << wsk[i] << ", ";
        }
        cout << " liczba= " << liczba << " pamiec= " << pamiec << endl;

    }
};

// inicjalizacja staycznej zmiennej liczba
int PunktND::liczba = 0;

// inicjalizacja statycznej zmiennej pamiec
long int PunktND::pamiec = 0;


PunktND p1{ 1, 2, 4, 5, 77, 777};  // tworzenie p1 za pomoca listy inicjalizujacej
PunktND p2{ p1};                   // tworeznie p2 poprez kopiowanie p1
PunktND p3(3);
                  // tworzenie p3 z okreslona liczba (4)

int main()
{
    p1.out(); cout << endl;
    p2.out(); cout << endl;
    p3.out();
   // cout << liczba << endl;

    return 0;
}

// definicje metod klasy PunktND

PunktND::PunktND(initializer_list<int> n) :roz(n.size()), wsk{ new int[roz] } {
    //example PunktND p1{ 1, 2, 4, 5, 77, 777 };
    //  inicjalizacja obiektu za pomoca listy inicjalizacyjnej
    int* wskTmp = wsk;
    for (auto k : n) { *wskTmp = k; wskTmp++;}
    {
        liczba++;
        pamiec += (sizeof(int) * roz);
    }
}

PunktND& PunktND::operator=(const PunktND& p) {
    // przeciązony operator przypisania
    if (roz != p.roz ) {
        delete[] wsk;
        pamiec -= (sizeof(int) * roz);
        roz = p.roz;
        wsk = new int[roz];
        pamiec += (sizeof(int) * roz);

    }
    for (int i = 0; i < roz; i++)
    {
        wsk[i] = p.wsk[i];

    }
    return *this;
}

PunktND::PunktND(const PunktND& p) :roz(p.roz), wsk{ new int[roz] } {
    // konstruktor kopiujacy
    int* wsktmp = wsk;
    for (int i = 0; i <roz; i++) { wsktmp[i] = p.wsk[i]; }
    {
        liczba++;
        pamiec += (sizeof(int) * roz);
    }
}
