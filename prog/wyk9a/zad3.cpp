#include <iostream>

using namespace std;

// deklaracja klasy szblonowej kontener
template <typename T, int r>
class Kontener
{
	T tab[r]; // tabliza elementow typu T o romziarze r
	static int ile;  // statyczna zmienna do sledzenia ilosci utworzonych konetenrow
public:
    //konstruktor
	Kontener();

    //przeciazony operator wypisywania dla klasy konener
	friend ostream& operator<<(ostream& out, const Kontener<T,r>& k)
	{
        // wypisuje zawartosc tablicy tab do strumienia out
		for (unsigned int i = 0; i < r; i++)
			out << k.tab[i] << " , ";
		return out;
	}

    // stayczna metoda klasy do pobierania ilosci utworzonyhc kontenerow
	static int dajIle();

	};

// implementacja konstruktoa kontner
template <typename T, int r>
Kontener<T,r>::Kontener(){
    //konstruktor klasy kontener
    // incjalizuje tablice tab wartoscimai domysnymi typu T
	for (unsigned int i = 0; i < r; i++) tab[i] = 0;
	ile++; // zwieksza licznik utworzonych konenerow
}

// incjalizacja statycznje zmiennej klasy konener
template <typename T, int r>
int Kontener<T,r>::ile = 0;

// deklaracja instancji klasy kontener z roznymi parametrami szbalonu
Kontener<int,11> kInt1, kInt2;
Kontener<double, 5> kDouble1;
Kontener<double,15> kDouble2, kDouble3;



int main()
{
	cout << kInt1 << endl;
	cout << kDouble1 << endl;

    //wywolanie metody dajIle()
	cout << kDouble1.dajIle() << endl;

    // wywolanie metodu dajIle() bez potrzbey posaidania obiektu
	cout << Kontener<double,5>::dajIle() << endl;
	cout << Kontener<double, 15>::dajIle() << endl;
	//kDouble1 = kDouble2;
	cout << kDouble1 << endl;
}


// definicja statycznej metody dajIle() klasy konener
template<typename T,int r>
int Kontener<T,r>::dajIle()
{ return ile; }  // zwraca ilosc utworzonych klas konener
