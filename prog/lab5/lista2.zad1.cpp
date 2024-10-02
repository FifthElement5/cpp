#include <iostream>

using namespace std;

class Ulamek {
    float l, m;
    public:
    Ulamek(float _l = 1, float _m = 1):l{_l}, m{_m} {}
    void out() { cout << l << "\\" << m << endl; }
    friend Ulamek operator*(const Ulamek& a, const Ulamek& b);
    friend Ulamek operator+(const Ulamek& a, const Ulamek& b);
    friend Ulamek operator-(const Ulamek& a, const Ulamek& b);
    friend Ulamek operator/(const Ulamek& a, const Ulamek& b);
    friend bool operator==(const Ulamek& a, const Ulamek& b);
    friend bool operator!=(const Ulamek& a, const Ulamek& b);
};

Ulamek u1(3, 5);
Ulamek u2(1, 5);
Ulamek u3, u4;

int main()
{
    // operator *
    u3 = u1*u2;
    u3.out();
    //operato +
    u3 = u1+u2;
    u3.out();
    //operator -
    u3 = u1-u2;
    u3.out();
    //operator /
    u3 = u1 / u2;
    u3.out();
    int wynik = (u1==u2);
    cout << wynik << " wynik =1 to prawda, 0 to falsz" << endl;
    wynik = (u1 != u2);
    cout << wynik << endl;

}
Ulamek operator*(const Ulamek& a, const Ulamek& b)
{
    Ulamek tmp;
    tmp.l = a.l * b.l;
    tmp.m = a.m * b.m;
    return tmp;
}
Ulamek operator+(const Ulamek& a, const Ulamek& b)
{
    Ulamek tmp;
    tmp.l = a.l + b.l;
    tmp.m = a.m + b.m;
    return tmp;
}
Ulamek operator-(const Ulamek& a, const Ulamek& b)
{
    Ulamek tmp;
    tmp.l = a.l - b.l;
    tmp.m = a.m - b.m;
    return tmp;
}
Ulamek operator/(const Ulamek& a, const Ulamek& b)
{
    Ulamek tmp;
    tmp.l = a.l *b.m;
    tmp.m = a.m*b.l;
    return tmp;
}
bool operator==(const Ulamek& a, const Ulamek& b)
{
    if(a.l == b.l && a.m == b.m)
    {
        cout << " rowne " << endl;
        return true;
    }
        return false;
}
bool operator!=(const Ulamek& a, const Ulamek& b)
{
    if((a.l != b.l && a.m != b.m) || (a.l == b.l && a.m != b.m) || (a.l != b.l && a.m == b.m))
    {
        cout << "nierowne" << endl;
        return true;
    }
    return false;
}
// bool operator>(const Ulamek& a, const Ulamek& b)
// {

// }
