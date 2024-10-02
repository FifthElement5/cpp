#include<iostream>
using namespace std;


class Punkt2D
{
protected:
	int x, y;
public:
	Punkt2D(int _x, int _y) :x{ _x }, y{ _y } { cout << "konstruktor 2D" << endl; }
	Punkt2D() :x{ 10 }, y{ 10 } { cout << "konstruktor 2D domyslny " << endl; }
    //metody dostepy do wspołrzednych
    // zwraca wartosc x, const : metoda nie moze modyfikowac zadnych zmiennych czlonkowskich obiekty
	int getX() const { return x; }
	int getY() const { return y; }

    //ustawiane wartosc x, przyjmuje int ktory reprezentuje nowa wspolrzedna x
    // przypisuje wartosc parametru i do zmiennej x
	void setX(int i) { x = i; }
	void setY(int j) { y = j; }

    // funkcja skladowa wypisujaca wspolrzedne puntu
	void wypisz() {
		cout << x << ", 2D , " << y;
	}

    // przeciazenie operatora << do wypisywania punktu 2D
	friend ostream& operator << (ostream& out, const Punkt2D& p) {
		out << "(" << p.x << ", " << p.y << ") " << endl;
		return out;
	}

    //przeciazenie operatora >> do wczytywania punktu 2D
	friend istream& operator >> (istream& in, Punkt2D& p) {
		cout << " x = "; in >> p.x;
		cout << " y = "; in >> p.y;
		//cout << " cin >> z 2D" << endl;
		return in;
	}
};

class Punkt3D : public Punkt2D
{
	int z;
public:
	//Punkt3D () : Punkt2D(1,1), z{1}{}
    // konstruktor z parametrami
	Punkt3D(int _x, int _y, int _z) : Punkt2D(_x, _y), z{ _z } { cout << "konstruktor 3D z param " << endl; }
	Punkt3D() : Punkt2D(), z{ 10 } { cout << "konstruktor 3D domyslny " << endl; }

    // metoda dostepu do wspolrzedej z
    int getZ() { return z; }
	void setZ(int i) { z = i; }

    //metoda wypisujaca wspolrzedne punktu
	void wypisz() {
		Punkt2D::wypisz();
		cout << ", lol " << z;
	}

    // [rzeciazenie operatora >> do wczytywanie punktu 3D]
	friend ostream& operator << (ostream& out, const Punkt3D& p) {
		out << "(" << p.x << ", " << p.y << ", " << p.z << ") ";
		return out;
	}
	friend istream& operator >> (istream& in, Punkt3D& p) {
		in >> (Punkt2D&)p;
		cout << " z = "; in >> p.z;
		return in;
	}
};


Punkt2D p1, p2; // p1(2,3);


Punkt3D p3, p4;



int main()
{
 p1.wypisz();cout << endl;
 p3.wypisz();
 int x = p1.getX(); cout << endl;
 cout << x << endl;
 p3.setX(300);
 p3.setY(400);
 p3.setZ(500);

 cout << p3;
 p3.wypisz();
 cout << "----------" << endl;
 p1 = p3; // p3 = p1 blad
 cout << p3;
 cout << p1;
 cin >> p4;
 cout << p4;

 cout << "---------" << endl;
 	p1 = p4;
	//p2 = p1;  blą
	cout << " sizeof(Punkt2D) = " << sizeof(Punkt2D) << endl;
	cout << " sizeof(Punkt3D) = " << sizeof(Punkt3D) << endl;
	cin >> p2;
	p2.wypisz();  cout << endl;

}


