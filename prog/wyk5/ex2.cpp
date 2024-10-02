#include <iostream>

using namespace std;

class Point3D {
    int x, y, z;
public:
    Point3D(int _x = 0, int _y = 0, int _z = 0 ) :x{ _x}, y{ _y}, z{ _z} {}
    void out() const {
        cout << "(" << x << "," << y << "," << z << ")" << endl;
    }
    void in(int _x, int _y, int _z) {
        x = _x;
        y = _y;
        z = _z;
    }
    Point3D dodajPoint3D(const Point3D& p) const;
    Point3D& operator+=(int a);
    Point3D& operator+=(const Point3D&);
    friend ostream& operator<<(ostream& ekran, const Point3D& b)
    {
        cout << "(" << b.x << "," << b.y << "," << b.z << ")"
    }
};

Point3D p1, p2, p3, p4;
const Point3D pointRef(10, 10 , 10);
int main()
{
    p1.in(6, 5, 4);


     p1.out(); cout << endl;
    cout << "pierwszy---------" << endl;
    pointRef.out(); cout << endl;
    p3 = p1.dodajPoint3D(pointRef);

    p3.out();
 cout << "dodade-----" << endl;
    p2.in(1, 2, 3);
    p2.out() ;cout << endl;
    p2 += 1;
    p2.out();
    cout << "z operatorem int ---" << endl;
    p4 = (p2 += p1);
    p4.out();
    cout << "z operatorem classa---" << endl;

}
Point3D Point3D::dodajPoint3D(const Point3D& p) const
{
    Point3D tmp;
    tmp.x = p.x + x;
    tmp.y = p.y + y;
    return tmp;
}
Point3D& Point3D::operator+=(int a) {
    x += a;
    y += a;
    z += a;
    return *this;
}
Point3D& Point3D::operator+=(const Point3D& p) {
    x += p.x;
    y += p.y;
    z += p.z;
    return *this;
}
