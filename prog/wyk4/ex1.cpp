#include <iostream>
using namespace std;

//deklaracja klasy
class Ulamek {
	int l, m;
public:
    //funkcja skladowa bierze dwie zmienne inty
	void in(int _l, int _m)
	{
        //wskazuje na licznik i zmienia
		l = _l;
		if (_m == 0) this->m = 1;  // this->m
        // wskazuje na mianownik
		else this->m = _m;
	}
    // drukuje ulamek
	void out()
	{
		cout << l << "\\" << m;
	}
    // funkcja zwraca ulamek , bierze referencje do adresu b
	Ulamek iloczyn (const Ulamek &b)
	{
        //zmienna lokalna ulamek
		Ulamek res;
        // mnozy licznik z res z licznikiem tego co wprowadzone
		res.l = b.l *l;
		res.m = b.m *m;
		return res;
	}
}; // koniec klasy

Ulamek u1, u2, u3;

int main()
{
	u1.in(3, 4);
	u2.in(2, 4);
	u3 = u2.iloczyn(u2);
    u1.out(); cout << endl;
    u2.out(); cout << endl;
	u3.out(); cout << endl;

}
