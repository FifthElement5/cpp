#include <iostream>

using namespace std;

class Prostokat {

    int bok1, bok2;
     public:

    void in(int x, int y)
    {
        bok1 = x;
        bok2 = y;
    }
    friend int pole(Prostokat &a);

};

    int pole(Prostokat &a)
    {
        int temp;
        temp = a.bok1 * a.bok2;
        return temp;

    }
    Prostokat p1, p2;

    int main()
    {
        p1.in(2, 3);
        int wynik = pole(p1);
        cout << wynik << endl;
    }
