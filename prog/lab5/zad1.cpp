#include <iostream>

using namespace std;

class Ulamek {
    int l, m;
    public:
    //a bezargumantowy konctruktor
    Ulamek() {
        l = 2;
        m = 3;
    }
    //b konstruktor z dowma arg -wyswietla komunikat gdy zle
    Ulamek(int _l, int _m)
    {
        if (_m == 0)
        {
            m = 2;
            l = 1;
            cout << "zle podany ulamek" << endl;
        } else {
        l = _l;
        m = _m; };

    }
    // c
    void out(){cout << l << "\\" << m << endl;}
    Ulamek inverse(Ulamek& b)
    {
        Ulamek tmp;
        tmp.l = b.m;
        tmp.m = b.l;
        return tmp;
    }
    // zamiana licznika
    Ulamek licznik(Ulamek& b, int x)
    {
        Ulamek tmp;

        if(x == 0){
            cout << "bez sensu" << endl;
        } else {
          tmp.l = b.l *x;
        }
        return tmp;
    }
    Ulamek mianownik(Ulamek& b, int x)
    {
        Ulamek tmp;
        if(x != 0)
        {
            tmp.m = x;
        } else {
            cout << "ulamek nie moze miec o" << endl;
        }
        return tmp;
    }
};

Ulamek u1, u3, u4, u5;
Ulamek u2(6, 7);
int main(){
    u1.out(); cout << endl;
    cout << "ulamke 1 out" << endl;
    u2.out(); cout << endl;
    u4 = u3.inverse(u1);
    u4.out();
    u5 = u3.inverse(u2);
    u5.out();
    u5 = u4.licznik(u2, 6);
    u5.out();
    u5 = u4.mianownik(u2, 1);
    u5.out();
}
