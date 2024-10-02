#include <iostream>

using namespace std;

class Elem {
    public:
    Elem* link1;
    int data;
    Elem* link2;
};

Elem *p, *q;

int main()
{
    //tworzysz nowy obiek p i ustawiasz data 1
    p = new Elem;
    p -> data = 1;
    // tworzysz nowy obiekt q i usatwiasz data d
    q = new Elem;
    q -> data = 5;
    // link2 p wskazuje na q
    p -> link2 = q;
    // link 1 wskazuje z powrotem na p
    q -> link1 = p;
    // link 2 wskazuje sam na siebie
    q -> link2 = q;
    q -> link1 = p;
    // tworzony jest nowy obiekt q
    q = new Elem;
    q -> data = 7;
    /// nowy q wskazuje na null
    q -> link2 = nullptr;
    q = nullptr;


}
