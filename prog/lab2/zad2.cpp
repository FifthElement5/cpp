#include <iostream>

class Elem {
public:
    int data;
    Elem* link;
};

int main() {
    // a) tworzy obiekt za pomoca wskaznika i ustawia pole data i link nullptr
    Elem* p_a = new Elem;
    (*p_a).data = 4;
    (*p_a).link = nullptr;

    // b) tworzy obiekt za pomoca wskazika i ustawia date na 7 i pole sam na siebie
    Elem* p_b = new Elem;
    p_b->data = 7;
    p_b->link = p_b;

    // c)
    Elem* q = new Elem;
    (*q).data = 2;
    q->link = nullptr;

    // d)tworzy obiekt za pomoca wskaznika , ustawia pole data na 1 i link na wskaznik do obiektu q
    Elem* p_d = new Elem;
    p_d->data = 1;
    (*p_d).link = q;

    // e) twory obiekt za pomoca wskaznika ustawia pole na 5  i pole link za wskaznik do nowo utworzonego obiektu
    Elem* p_e = new Elem;
    p_e->data = 5;
    p_e->link = new Elem;
    //zawratos jest kopiowana z nowego obiektu do p_e
    *(p_e->link) = *p_e;

    // Drukowanie wartości danych
    std::cout << "a) " << p_a->data << " adres " << &p_a << std::endl;
    std::cout << "b) " << p_b->data << " " << p_b->link->data << std::endl;
    std::cout << "c) " << q->data << std::endl;
    std::cout << "d) " << p_d->data << " " << p_d->link->data << std::endl;
    std::cout << "e) " << p_e->data << " " << p_e->link->data << std::endl;

    return 0;
}


