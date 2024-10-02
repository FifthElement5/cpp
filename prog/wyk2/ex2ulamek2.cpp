#include <iostream>
using namespace std;

//deklaracja klasy o nazwie ulmake
class Ulamek {
	public:
	int l, m;
};

// deklaracja funkcji in kotra bierze wskaznik do zmiennej ulamke i dwie liczby i wpisuje je w ulamel
void in(Ulamek* wsk)
{
	int _l;
    cout << "podaj licznik";
    cin >> _l;
	wsk->l = _l;

    int _m;
    cout << "podaj mianownik";
    cin >> _m;
	 wsk->m = _m;
}

/// funckja ktora drukuje ulamke (bierze zmienna ulamek i drukuje licznik i mianownik)
void out(Ulamek u)
{

	cout << u.l << "\\" << u.m;
}

// funkcja mnozaca ulamki, bierze dwa ulamki i mnozy i w rezultacie drukuje ulamek
Ulamek iloczyn(Ulamek a, Ulamek b)
{
	//zmienna lokalna typu ulamke
	Ulamek rez;
	// mnozy licznik a i licznik b, zapisuje w ulamku rez
	rez.l = a.l * b.l;
	rez.m = a.m * b.m;
	//zwraca rez
	return rez;
}

//deklaracja ulamkow
Ulamek u1, u2, u3;

int main()
{
	in(&u1);
	//in(&u2, 2, 4);
	//u3 = iloczyn(u1, u2);
    cout << " ulamek1 " ; out(u1);
	cout << endl;

	 //cout << " ulamek2 "; out(u2);
	 cout << endl;
    //out(u3); cout << " wynik mnozenia " << endl;

}
