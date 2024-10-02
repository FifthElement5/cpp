#include <iostream>
using namespace std;

//deklaracja klasy
class Ulamek {
	int l, m;
public:
    //funkcja skladowa bierze dwie zmienne inty
	void in()
	{
        //wskazuje na licznik i zmienia
        int _l;
        cout << "podaj licznik ";
        cin >> _l;

		l = _l;
		//if (_m == 0) this->m = 1;  // this->m
        // wskazuje na mianownik
        int _m;

        cout << "podaj mianownik ";
        cin >> _m;
        if (_m == 0)
        {
            m = 1;
        }
        else
        {
        m = _m;
        }
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
	u1.in();
	u2.in();
    u3 =  u1.iloczyn(u1);
    u1.out(); cout << endl;
    // u2.out(); cout << endl;
	 u3.out(); cout << endl;

}
