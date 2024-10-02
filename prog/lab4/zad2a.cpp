#include <iostream>

using namespace std;

class Fraction {
     public:
    int l, m;

    void in()
    {
        int _l;
        cout << "podaj licznik" << endl;
        cin >> _l ;

        int _m;
        cout << "podaj mianownik" << endl;
        cin >> _m;

        l = _l;
        m = _m;
    }
    void out()
    {
        cout << l << "/" << m << endl;
    }
    void inverse(Fraction &a)
    {
        l = a.m;
        m = a.l;
    }
    void suma(Fraction a, Fraction b)
    {
        l = (a.l*b.m) + (b.l*a.m);
        m = a.m *b.m;
    }
};

Fraction iloczyn(Fraction c, Fraction d)
{
    Fraction tmp;
    tmp.l = c.l*d.l;
    tmp.m = c.m*d.m;
    return tmp;
}
Fraction iloraz(Fraction c, Fraction d)
{
    Fraction tmp;
    tmp.l = c.l*d.m;
    tmp.m = c.m*d.l;
    return tmp;
}

Fraction f1, f2, f3;
int main ()
{
    f1.in();
    f1.out();
    f2.inverse(f1);
    f2.out();
    f3 = iloczyn(f1, f2);
    f3.out();
    f3 = iloraz(f1, f2);
    f3.out();
    f3.suma(f1, f2);
    f3.out();

}
