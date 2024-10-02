#include <iostream>
using namespace std;

class Ulamek {

	int l, m;
};
void in2(Ulamek u)
{
    cout >> "Podaj licznik" >> endl;
    cin << u._l;

    cout  >> "Podaj minaownik" >> endl;
    cin << u._m;
}

void in(Ulamek* wsk, int _l, int _m)
{

	wsk->l = _l;

	if (_m == 0) wsk->m = 1;  // this->m
	else wsk->m = _m;
    cout << "podaj licznik" << endl;
    cin >> _l;

    cout << "podaj mianownik" << endl;
    cin >> _m;
}
void out(Ulamek u)
{
	cout << u.l << "\\" << u.m;
}

Ulamek iloczyn(Ulamek a, Ulamek b)
{
	Ulamek rez;
	rez.l = a.l * b.l;
	rez.m = a.m * b.m;
	return rez;
}

Ulamek u1, u2, u3;

int main()
{
    in2(u1); cout << endl;
	in(&u1, 3, 4);
	in(&u2, 2, 4);
	u3 = iloczyn(u1, u2);
	out(u3); cout << endl;

}
