#include <iostream>

using namespace std;

class Point3D {
    public:
    int x, y, z;

    void setx(int _x)
    {
        x = _x;

    }
    int getx()
    {
        return x;
    }
    void sety(int _y)
    {
        y = _y;
    }
    int gety()
    {
        return y;
    }


};
void out(Point3D a)
{
    cout << a.x << "," << a.y << endl;
}
Point3D u1;

int main()
{
    u1.setx(5);
    cout << u1.getx() << endl;
    u1.sety(9);
    cout << u1.gety() << endl;
    out(u1);
}


