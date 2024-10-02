#include <iostream>

using namespace std;

struct Elem {
	int data;
	Elem* link;
};

Elem* p, *q;

int main()
{
	// tworzy nowy obiekt przypisuje date
	p =  new Elem;
	p->data = 1;
	// tworzy now obiekt przypisuje date
	q = new Elem;
	q->data = 5;
	// lączy p z q
	p->link = q;
	//tworzy nowy obiekt przypisuje 7
	q = new Elem;
	q->data = 7;
	//p->link->link = q;
	q->link = p;

	cout << "p data " << p->data << " p link addres " << q->link->data  << " "<< p->link->data << endl;


	// DO SCHEMTU LISTA WSKAZNIKI 2
}
