#include <iostream>

using namespace std;

class Point3D {
    int x, y, z;
    public:
    void in(int _x, int _y, int _z)
    {
        x = _x;
        y = _y;
        z = _z;
    }
    void out()
    {
        cout << x << "," << y << "," << z << endl;
    }
    void przesun(Point3D& a, int n)
    {

        x = a.x + n;
        y = a.y + n;
        z = a.z + n;



    }

};

Point3D p1, p2;

int main()
{
    p1.in(1, 2, 3);
    p1.out(); cout << endl;
    p2.przesun(p1, 2);
    p2.out(); cout << endl;
}
