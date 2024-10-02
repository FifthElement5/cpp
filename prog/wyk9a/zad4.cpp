#include <iostream>

using namespace std;

// Declaration of template class Punkt2D
template <typename T>
class Punkt2D
{
protected:
    T x, y;
public:
    // Constructor initializing coordinates
    Punkt2D(T _x, T _y) : x{ _x }, y{ _y } { }
    // Default constructor, initializing coordinates with default values
    Punkt2D() : x{ 1 }, y{ 1 } { }

    // Accessor methods for coordinates
    T getX() { return x; }
    T getY() { return y; }

    // Mutator methods for coordinates
    void setX(T i) { x = i; }
    void setY(T j) { y = j; }

    // Method to print coordinates of the point
    void wypisz() {
        cout << "(" << x << ", " << y << ")";
    }

    // Friend function for output stream operator <<
    friend ostream& operator<<(ostream& out, const Punkt2D<T>& p) {
        out << "(" << p.x << ", " << p.y << ") ";
        return out;
    }

    // Friend function for input stream operator >>
    friend istream& operator>>(istream& in, Punkt2D<T>& p) {
        cout << " x = "; in >> p.x;
        cout << " y = "; in >> p.y;
        return in;
    }
};

// Class Punkt3D inheriting publicly from Punkt2D<int>
class Punkt3D : public Punkt2D<int>
{
    int z; // Third coordinate of the 3D point
public:
    // Constructor initializing coordinates
    Punkt3D(int _x, int _y, int _z) : Punkt2D<int>(_x, _y), z{ _z } {
        cout << "konstruktor 3D" << endl;
    }

    // Default constructor
    Punkt3D() : z{ 1 } {
        cout << "konstruktor 3D domyslny " << endl;
    }

    // Accessor method for coordinate z
    int getZ() { return z; }

    // Mutator method for coordinate z
    void setZ(int i) { z = i; }

    // Method to print coordinates of the 3D point
    void wypisz(int i) {
        Punkt2D<int>::wypisz();
        cout << " z = " << z << endl;
    }

    // Friend function for output stream operator << for Punkt3D
    friend ostream& operator<<(ostream& out, const Punkt3D& p) {
        out << static_cast<const Punkt2D<int>&>(p);  // Access base class part
        out << " z = " << p.z;
        return out;
    }

    // Friend function for input stream operator >> for Punkt3D
    friend istream& operator>>(istream& in, Punkt3D& p) {
        in >> static_cast<Punkt2D<int>&>(p);  // Access base class part
        cout << " z = "; in >> p.z;
        return in;
    }
};

// Object of Punkt2D<int> with coordinates (3, 6)
Punkt2D<int> p1(3, 6);
// Object of Punkt3D
Punkt3D p2(4, 4, 6);

// Main function
int main()
{
    // Input from user for p1 and p2
    cin >> p1;
    cin >> p2;

    // Output coordinates of p1 and p2
    cout << p1 << endl;
    cout << p2 << endl;
    cout << p1 << endl;

    // Call method wypisz() for p2
    p2.wypisz(2);

    return 0;
}
