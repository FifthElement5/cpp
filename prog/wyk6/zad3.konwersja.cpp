#include <iostream>
using namespace std;

//definicja klasy Ulamek
class Ulamek {
	int l, m;
public:
	//komstruktor z dwoma argumentami, gdzie _l to icznik a _m mianownik
	//uzywamy explicit aby uniknac niejawnej konwersacji
	explicit  Ulamek(int _l, int _m) :l{ _l } { if (_m == 0) m = 1;

	 //konstruktor kopiujacy                                             else m = _m; }
	Ulamek(const Ulamek&);
	//konstruktor domyślny, ustawiajacy licznik i mianownik na 1
	Ulamek() :l{ 1 }, m{ 1 } {}
	//konstruktor jednoparametrowy, ustawiający licznik na podana watosc a mianownik na 1
	Ulamek(int _l ) :l { _l }, m{ 1 } {}
	//operator przypisania
	Ulamek &operator = (const Ulamek& u);
	// metoda do ustawiania licznika i mianownika
	void in(int, int);

	//deklaracja funckcji zaprzyjaznionych do mnożenia ułamków oraz operacji wejscia/wyjscia
	friend Ulamek operator*(const Ulamek&, const Ulamek&);
	//friend Ulamek operator*(const Ulamek&, int);
	//friend Ulamek operator*(int, const Ulamek&);
	friend ostream& operator <<(ostream&, const Ulamek&);
	friend istream& operator >> (istream&, Ulamek&);
};
//przykładow obiekty klasy ułamek
Ulamek u1(7, 7);
Ulamek u2(3, 4);
Ulamek u4(1, 2);
Ulamek u3;

int main()
{
	//wczytanie wartości ułamka u1 z wejscia
	cin >> u1;
	//mnozenie dwóch ułaknow
	u3 = u1 * u2;
	//u3 = u1 * 1;
	//u3 = 7 * u2;
	cout << " u1 = " << u1 << " u2 = " << u2 << endl << "u3 = " << u3;

	// tworzy obiekt u1 jako kopie u3 tutaj wywołany zostanie konstruktor kopiujący
	Ulamek u1 = u3;
	// operator przypisania, wyswietla komunikat operator
	u4 = u1;
	cout<< u1 << "witaj" << u2 << endl;
	return 0;
}

//definicja konstruktora kopiujacego, wyswietlajacego kominkat
Ulamek::Ulamek(const Ulamek& u) : l(u.l), m(u.m) { cout << " kopiujący" << endl; }

//definicja operatora przypisania(funcka składowa ), wyswietlajacego kominikat
Ulamek & Ulamek::operator = (const Ulamek& u) {
	l = u.l;  m = u.m;  cout << " operator ="; return *this;
}

// definicja operatora mnożenia dwóch ułamków (funkcja zaprzyjażniona)
Ulamek operator*(const Ulamek &b, const Ulamek &a)
{
	Ulamek rez;
	rez.l = a.l * b.l;
	rez.m = a.m * b.m;
	return rez;
}
/*Ulamek operator*(const Ulamek& a, int b)
{
	Ulamek rez;
	rez.l = a.l * b;
	rez.m = a.m;
	return rez;

}
Ulamek operator*(int b, const Ulamek& a)
{
	Ulamek rez;
	rez.l = a.l * b;
	rez.m = a.m;
	return rez;

}*/

// definicja operatora wejścia (wczytywanie ułamka z wejscia)
istream& operator >> (istream& klaw, Ulamek& u)
{
	cout << "l = ";
	klaw >> u.l;
	int temp;
	cout << "m = ";
	klaw >> temp;
	if (temp == 0) u.m = 1;  // this->m
	else u.m = temp;
	return klaw;
}

// definicja operatora wyjscia (wysiwtelanie ułamka)
ostream& operator <<(ostream& ekran, const Ulamek& u)
{
	cout << u.l << "/" << u.m << endl ;
	return ekran;
}
