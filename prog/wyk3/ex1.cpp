#include <iostream>

using namespace std;

class Ulamek
{
    int l, m;
    public:
    void in(int _l, int _m)
    {
        this->l = _l;
        if(_m == 0)
        {
            m=1;
        }
        this->m = _m;
    }
    void out()
    {
        cout << "wartosc this = " << this << endl;
        cout << "adres l      = " << &l   << endl;
        cout << "adres m      = " << &m << endl;
        cout << l << "\\" << m << endl;
    }

}; ///koniec klasy

Ulamek u1, u2, u3;
Ulamek *wsk = &u1;

int main()
{
    u1.in(3, 5);
    u2.in(4, 5);
    u1.out(); cout << endl;
    u2.out(); cout << endl;
    cout << "adres u1 = " << wsk << endl;

}
