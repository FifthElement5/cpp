#include <iostream>

using namespace std;

class Point3D {
    int x, y, z;
public:
    Point3D(int _x=0, int _y=0, int _z=0) { x = _x; y = _y; z = _z; cout << " konstruktor 1 " << endl; }
    void out() { cout << "(" << x << ", " << y << ", " << z << ")"; }
    void in(int _x, int _y, int _z) { x = _x, y = _y; z = _z; }
};

Point3D p1(3, 4, 5);
Point3D p2(1, 3, 5);
Point3D p3;




//const Point3D p3=p1;


int main()
{
    p1.out(); cout << endl;
    p2.out(); cout << endl;
    p3.out(); cout << endl;

    p1.in(6, 6, 6); cout << endl;
    p1.out(); cout << endl;
}
