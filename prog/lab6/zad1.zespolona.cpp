#include <iostream>

using namespace std;

class Zespolona {
    int re, im;
    public:
    //konstruktor
    Zespolona(int _re = 0, int _im = 0) : re{_re}, im{_im} {}

    //metoda obciazony prefix ++ opartor
    Zespolona& operator++();

    //metoda obciazony postfix opertaor ++ (zieksza urojona)
    Zespolona operator++(int);
    //Zespolona& operator+(const Zespolona&);

    Zespolona operator+(const Zespolona&);
    //obciazony zaprzyjaziony operator wyjscia
    friend ostream& operator<<(ostream&, const Zespolona&);
    //ociazony zaprzujaznion operator wejscia
    friend istream& operator>>(istream&, Zespolona&);

};

Zespolona z1(1, 2);
Zespolona z2, z3;

int main()
{
  cout << z1 << z2;
  cin >> z2 ;
  cout << z2;
  ++z2;
  cout << " ++z "<<z2;
  z2++;
   cout << "z+++ " << z2;
  cout << "dodanie z2 + z1 " << endl;
  z3 = z1 + z2;
  cout << z3;

}
ostream& operator<<(ostream& ekran, const Zespolona& a)
{
    ekran << a.re << " "<< a.im <<  "i" << endl;
    return ekran;
}

istream& operator>>(istream& klaw, Zespolona& a)
{
    cout << "podaj liczbe rzeczywista liczby zespolonej: " ;
    klaw >> a.re;
    cout << "podaj liczbe urojona liczby zespolonej:" ;
    klaw >> a.im;
    return klaw;
}
//zwieksza liczbe rzeczywista prefix
Zespolona& Zespolona::operator++()
{

  ++re; // powieksza ten objekt
return *this;

}

Zespolona Zespolona::operator++(int)
{
    Zespolona tmp = *this;
    re++;
    im++;
    return tmp;

}
Zespolona Zespolona::operator+(const Zespolona& a)
{
    Zespolona tmp;
    tmp.re = re + a.re;
    tmp.im = im + a.im;
    return tmp;
}
