#include <iostream>

using namespace std;

class Ulamek {

	int l, m;
public:
	Ulamek(int, int);
	Ulamek() { l = 1; m = 1; }
	void in(int, int);
	//Ulamek operator*(const Ulamek&) const ;  //u3 = u1.operator*(u2);
	friend Ulamek operator*(const Ulamek& a, const Ulamek& b);
	friend Ulamek operator*(const Ulamek& a, int b);
	friend Ulamek operator*(int b, const Ulamek& a);
	friend bool operator<(const Ulamek& a, const Ulamek& b);
	friend ostream& operator<<(ostream & ekran, const Ulamek& b);
	friend istream& operator>>(istream& klaw, Ulamek& b);
};

Ulamek u1(4, 7);
Ulamek u2(2, 3), u3;

//deklaracja zmiennej o nazwie ekran
ostream& ekran = cout;
bool wynik;


int main()
{
	//ekran << "Marysia" << endl;
	cout << u1 << " ulamek u1 przed zmiana" << endl;
	cin >> u1; cout << u1 << "ulamek u1 po zmianie z klawiatury" << endl;

    u3 = u1 * u2;     // u3 = u1.operator*(u2);
	cout << u3 << endl; // operator <<
	u3 = u1 * 2;     // u3 = u1.operator*(24);
	cout << u3 << endl; // operator <<
	cout << "ukamke po mnozeniu " << endl;
	cin >> u1; cin >> u2; // operator >> ulamek
	u3 = u2 * u1;
	cout << "u1 = " << u1 << ",   u2 = " << u2 << ",   u3 = " << u3 << endl;

	wynik = u2 < u1;
	cout << wynik << " wynik " << endl;
}

Ulamek::Ulamek(int _l, int _m) {
	l = _l;
	if (_m == 0) m = 1;
	else m = _m;
}

void Ulamek::in(int _l, int _m)
{
	this->l = _l;
	if (_m == 0) this->m = 1;  // this->m
	else this->m = _m;
}
ostream & operator<<(ostream& ekran, const Ulamek& b)
{
	cout << b.l << "\\\\" << b.m;
	//cout << " operator << napisany " << endl;
	return ekran;
}
istream& operator>>(istream& klaw, Ulamek& b)
{
	cout << " licznik = "; klaw >> b.l;
	cout << " mianownik = "; klaw >> b.m;  // spr w domu czy nie wpisano 0
	return klaw;
}
/*Ulamek Ulamek::operator*(const Ulamek& b) const  // u3 = u1.iloczyn(u2);
{
	Ulamek res;
	res.l = b.l * l;
	res.m = b.m * m;
	return res;
}*/

Ulamek operator * (const Ulamek& a, const Ulamek& b)   //  // u3 = iloczyn(u1, u2);
{
	Ulamek res;
	res.l = b.l * a.l;
	res.m = b.m * a.m;
	return res;
}
Ulamek operator * (int b, const Ulamek& a)
{
	Ulamek res;
	res.l = a.l * b;
	res.m = a.m;
	return res;
}
Ulamek operator * (const Ulamek& a, int b)
{
	Ulamek res;
	res.l = a.l * b;
	res.m = a.m;
	return res;
}

bool operator<(const Ulamek& a, const Ulamek& b)
{

	return true;
	///return true;

}
