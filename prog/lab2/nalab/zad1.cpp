#include <iostream>

using namespace std;

struct Elem {
	int data;
	Elem* link;
};

Elem* p, *q;

int main()
{
	p =  new Elem;
	p->data = 1;
	q = new Elem;
	q->data = 5;
	p->link = q;
	q = new Elem;
	q->data = 7;
	p->link->link = q;
	q->link = p;

	// DO SCHEMTU LISTA WSKAZNIKI 2
}
