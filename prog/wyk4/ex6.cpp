#include <iostream>

using namespace std;

class Point3D {
    int x, y, z;
public:
    //Point3D(int _x = 0, int _y = 0, int _z = 0) :x{ _x }, y{ _y }, z{ _z } {}
    // konstruktor , moze byc wywolany z 3 argumentami typu int, inicjuje zminne wartosciami
    Point3D(int _x = 0, int _y = 0, int _z = 4) :y{ _y }, x{ _x + y }, z{ _z } {}
    // funckja out
    void out() const { cout << "(" << x << ", " << y << ", " << z << ")"; }
    // funcja in
    void in(int _x, int _y, int _z) { x = _x, y = _y; z = _z; }
    /*Jest to metoda publiczna klasy Point3D, która
    przyjmuje referencję do obiektu Point3D jako argument p i zwraca nowy obiekt Point3D,
     który reprezentuje sumę współrzędnych
    obecnej instancji i obiektu przekazanego jako argument.*/
    Point3D dodajPoint3D(const Point3D& p) const;
};

Point3D p1(3, 4, 5);
Point3D p2(1, 3, 5);
Point3D p3;

const Point3D pointRef(10, 10, 10);


int main()
{
    p3 = p1.dodajPoint3D(p2);
    p3.out(); cout << endl;

}


Point3D Point3D::dodajPoint3D(const Point3D& p) const
{  Point3D tmp;
   tmp.x = p.x + x;
   tmp.y = p.y + y;
   tmp.z = p.z + z;
   return tmp;
}
