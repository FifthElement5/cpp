#include <iostream>

using namespace std;

class Ulamek {
    public:
    int l, m;

    Ulamek(int, int);
    Ulamek() { l = 1; m = 1;}
    void out();
    void in(int, int);
    Ulamek iloczyn(const Ulamek&);
};

Ulamek u1(4, 1);
Ulamek u2, u3;

int main()
{
    u1.out(); cout << endl;
	u2.in(2, 4);
	u3 = u1.iloczyn(u2);
	u3.out(); cout << endl;
    Ulamek(); cout << endl;
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
void Ulamek::out()
{
	cout << this->l << "\\" << m;
}
Ulamek Ulamek::iloczyn(const Ulamek& b)
{
	Ulamek res;
	res.l = b.l * l;
	res.m = b.m * m;
	return res;
}
