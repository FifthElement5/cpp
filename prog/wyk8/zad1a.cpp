#include <iostream>

using namespace std;

// Bazowa klasa abstrakcyjna z punktami x i y.
// Zawiera czysto wirtualne metody rysuj() i dajPole().
// Implementuje metody dostępu i zmiany punktów oraz operatory wejścia/wyjścia.
class Figura
{
protected:
	int x, y;
public:
	//konstruktor z argumentami
	Figura(int _x, int _y ) : x{ _x }, y{ _y } { }
	// konstruktor domyslny 1 1
	Figura() : x{ 1}, y{ 1 } { }
	// metdody dostepowe do punktow i zmieniajace
	int getX() { return x; }
	int getY() { return y; }
	void setX(int i) { x = i; }
	void setY(int j) { y = j; }
	// metoda przesuwajaca punkt o zadane przesuniecie
	void zmianaWsp(int dx, int dy) { x += dx; y += dy; }

	//zaprzyjaznione operatory wejscia i wyjscia
	friend ostream& operator << (ostream& out, const Figura& p);
	friend istream& operator >> (istream& in, Figura& p);

	// MEDTODY VIRTUALNE CZYSTO ABSTRAKCYJNE ktore musza byc zaimplementowane w klasach pochodnych
	virtual void rysuj() = 0; // { cout << " rysuje Fig choc nie umiem " << endl; cout << *this; };
	virtual double dajPole() = 0;
    virtual void rysuj(unsigned int _x, unsigned int _y) = 0;
};


class Kwadrat : public Figura
{
protected:
	// dodatkowy atrybut
	unsigned int a;
public:
	// konstruktor inicjujacy , wykorzystuje konstruktor klasy bazowej
	Kwadrat(int _x , int _y , unsigned int _a ) : Figura(_x, _y), a{ _a } { }
	// konstruktor domyslny , wykorzytuje konstruktor klasy bazowej
	Kwadrat() : Figura(), a{ 1 } { }
	int getA() { return a; }
	void setA(unsigned int _a ) { a = _a; }
	// przeciazone operatory wejscia i wyjscia
	friend ostream& operator << (ostream& out, const Kwadrat& k);
	// dziedziczy z operatora figury
	friend istream& operator >> (istream& in, Kwadrat& p);

	// metody napisuja metody wirtulane z klasy figura
	virtual void rysuj() override { cout << " rysuje Kwadrat o parametrach "; cout << *this; }
	virtual double dajPole() override { return a * a; }
	// METODA napisana zmieniajaca wspolrzedne i rysujaca kwadrat
    void rysuj(unsigned int _x, unsigned _y) override {
		x = _x; y = _y;
		cout << " rysuje Kwadrat o PARAMETRACH "; cout << *this;
	};
};
class Okrag : public Figura
{
protected:
	// dodatkowy artybut r
	unsigned int r;
public:
	Okrag(int _x, int _y, unsigned int _r) : Figura(_x, _y), r{ _r } { }
	Okrag () : Figura(), r{ 1 } { }
	int getR() { return r; }
	void setR(unsigned int _r) { r = _r; }
	friend ostream& operator << (ostream& out, const Okrag& k);
	friend istream& operator >> (istream& in, Okrag& p);
	// merody napisujace metody wirtualne z klasy figura
	virtual void rysuj() { cout << " rysuje Okrag o parametrach "; cout << *this; }
	virtual double dajPole() { return 3.14*r * r; }
	// metoda napisujaca zmieniajaca wspolrzedne i rysujaca okrag
	void rysuj(unsigned int _x, unsigned int _y) override {
		x = _x; y = _y;
		cout << " rysuje Okrag o parametrach "; cout << *this;
	};
};

// klasa dziedziczy po Kwadracie
class Prostokat : public Kwadrat
{
protected:
	unsigned int b;
public:
	// konstruktor inicjalizyjacy x y a i b , dziedziczy konstruktor Kwadrat
	Prostokat(int _x = 1, int _y = 1, unsigned int _a = 1, unsigned int _b = 1) : Kwadrat(_x, _y, _a), b{ _b } {}
	Prostokat(): b{ 1 } {}
	int getB() { return b; }
	void setB(unsigned int _b) { b = _b; }
	friend ostream& operator << (ostream& out, const Prostokat& k);
	friend istream& operator >> (istream& in, Prostokat& p);

	//nadpisane metody wirtuane
	virtual  void rysuj() { cout << " rysuje Prostokat o parametrach "; cout << *this; }
	virtual double dajPole() { return a * b; };
    virtual void rysuj(unsigned int _x, unsigned int _y) override {
		x = _x; y = _y; cout << " rysuje Prostokat o parametrach ";
		cout << *this;
	}
};

// funkcje globalne do rysowania , przyjmuja wskazniki djako argument
void rysujFig(Figura* wskFig)  // rysujFig(&p1);
{
	//wywolujemetode rysuj na obiekcie wskazanym przez wskFig,
	//nawet jesli wskaznik jest do klasy bazowej , bedzie wywolana odpowiednia metoda
	wskFig->rysuj();
}

//referncja do obiekty klasa figura
void rysujFig(Figura & refFig)  // // rysujFig(p1);
{
	// wywoluje metode wysuj na obiekcie referenjonowanym przez refFig
	refFig.rysuj();
}

 //Figura f1(1, 2);              // blad bo abstrakcyjna
Kwadrat k2, k1(2, 3, 4);
Prostokat p1(4, 5, 5, 6);
Okrag o1(4, 5, 6), o2(40, 50, 10);

Figura* wskFig;

int main()
{


	k2.rysuj();
	k2.rysuj(33, 44);
	cout << endl;
	rysujFig(p1);
	cout << endl;
	rysujFig(o1);
	cout << endl;
	rysujFig(o2);
	cout << endl;
	cout << "Figura " << sizeof(Figura) << endl;
	cout << "Kwadrat " << sizeof(Kwadrat) << endl;
	cout << "Prostokat " << sizeof(Prostokat) << endl;
	// wskFig = &f1;
	// rysujFig(&f1);
	// cout << endl;

	// wskFig->rysuj(); cout << endl;  cout << endl;
	wskFig = &k1;
	wskFig->rysuj(); cout << endl;  cout << endl;
	wskFig = &p1;
	wskFig->rysuj(); cout << endl;  cout << endl;
	/*rysujFig(&k1);
	cout << endl;
	rysujFig(&p1);
	cout << endl;*/
}

ostream& operator << (ostream& out, const Figura& p) {
	out << "(x = " << p.x << ", y = " << p.y << ") ";
	return out;
}
istream& operator >> (istream& in, Figura& p) {
	cout << " x = "; in >> p.x;
	cout << " y = "; in >> p.y;
	return in;
}

ostream& operator << (ostream& out, const Kwadrat& k) {
	out << "(x = " << k.x << ", y = " << k.y << " , a = " << k.a << ") ";
	return out;
}

istream& operator >> (istream& in, Kwadrat& k) {
	in >> (Figura&)k;
	cout << " a = "; in >> k.a;
	return in;
}

ostream& operator << (ostream& out, const Prostokat& pr) {
	out << "(x = " << pr.x << ", y = " << pr.y << ", a = " << pr.a << ", b = " << pr.b << ")";
	return out;
}

istream& operator >> (istream& in, Prostokat& pr) {
	in >> (Kwadrat&)pr;
	cout << " b = "; in >> pr.a;
	return in;
}

ostream& operator << (ostream& out, const Okrag& k)
{
	out << "(x = " << k.x << ", y = " << k.y << " , r = " << k.r << ") ";
	return out;
}
istream& operator >> (istream& in, Okrag& p)
{
	in >> (Figura&)p;
	cout << " r = "; in >> p.r;
	return in;
}
