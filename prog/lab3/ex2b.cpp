#include <iostream>
#include <cstring>

using namespace std;

class Elem {
    public:
    char* wsk;
    int data;
    Elem *link;
};
int main()
{
    // twoorze nowy dynamiczny obiekt p
    Elem *p = new Elem;
    // alokuje pamiec na tablice
    p -> wsk = new char[2];
    // tworzy nowy dynamiczny obiekt q
    Elem *q = new Elem;
    // ustawia data na 2 w q
    q ->data = 2;
    // ustawia data na 0 w p
    p ->data = 0;
    // przypisuje wskaznik obiektu p do pola obiektu q
    q ->wsk = p->wsk;

    p->link = q;
    q->link = q;
    strcpy(p->wsk, "a");
    //p->wsk = 'a';
}
