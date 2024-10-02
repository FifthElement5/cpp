#include <iostream>

using namespace std;


class Zespolona {
    int re, im;
    public:
    Zespolona(int _re = 1, int _im = 1): re{_re}, im{_im} {}

    Zespolona operator+(Zespolona& a)
    {
        Zespolona tmp;
        tmp.re = re + a.re;
        tmp.im = im + a.re;
        return tmp;
    }
    Zespolona operator-(Zespolona& s)
    {
        Zespolona tmp;
        tmp.re= re - s.re;
        tmp.im= im - s.im;
        return tmp;
    }
    Zespolona& operator++()
    {
        re++;
        im++;
        return *this;


    }
    Zespolona operator++(int)
    {
        Zespolona tmp = *this;
        re++;
        im++;
        return tmp;
    }

    friend ostream& operator<<(ostream& ekran, const Zespolona& a);
    friend istream& operator>>(istream& klaw, Zespolona& a);


};

Zespolona z1, z3;
Zespolona z2(2,2);

int main()
{
  cout << z1;
  cout << z2;
  cin >> z1;
  cout << z1;
  cout << "dodane " << endl;
  z3 = z1 + z2;
  cout << z3;
  z3 = z1 - z2;
  cout << z3;
  ++z3;
  cout << z3;
  z3++;
  cout << z3;

}

ostream& operator<<(ostream& ekran, const Zespolona& a)
{
    ekran << a.re << " " << a.im << "i" << endl;
    return ekran;
}
istream& operator>>(istream& klaw, Zespolona& a)
{
    cout << "Podaj liczbe rzeczywista zespolonej: " << endl;
    klaw >> a.re;
    cout << "Podaj liczbe urojona zespolone: " << endl;
    klaw >> a.im;
    return klaw;
}
