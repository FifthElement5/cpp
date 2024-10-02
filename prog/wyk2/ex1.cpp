#include <iostream>

using namespace std;
int* wsk;

int main()
{
    int a = 4 + NULL;
    // int b = 4 + nullptr;// błąd to nie int a adres zerowy
    cout << "a= " << a << endl;
    wsk = nullptr;
    cout << "wsk = " << wsk << endl;
}
