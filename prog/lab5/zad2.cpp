#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

using namespace std;
class Punkt {
    int x, y;
    public:
    //konstruktor
    Punkt(int _x = 0, int _y = 0) :y{_y}, x{_x} {}
    //a inine
    inline void out(){
        cout << "(" << x << "," << y << ")" << endl;
    }
    //b random
    Punkt random()
    {
        Punkt tmp;
        srand(time(NULL));
        tmp.x = rand() % 100;
        tmp.y = rand() % 10;
        return tmp;
    }
    Punkt odbicie(Punkt& a)
    {
        Punkt tmp;
        tmp.x = -a.x;
        tmp.y = -a.y;
        return tmp;

    }
    Punkt dodaj(Punkt& a)
    {
        Punkt tmp;
        tmp.x = x + a.x;
        tmp.y = y + a.y;
        return tmp;
    }

};

Punkt p1, p2, p4;
Punkt p3(1, 5);
int main(){
    p3.out(); cout << endl;
    p2 = p1.random(); p2.out();
    p3 = p4.odbicie(p2);
    p3.out();
    p4 = p3.dodaj(p2);
    p4.out();

}


