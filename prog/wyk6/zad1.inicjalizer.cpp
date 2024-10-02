#include <iostream>
#include <initializer_list>

using namespace std;

//incjiowanie listy liczbami calkowitumi
initializer_list<int> listaInt{3, 4, 5, 6};

int main()
{
    //wskaznik do stałej liczby całkowitej
    const int* wsk = {listaInt.begin() };
    //petla for przechodzi przez elementy listy zaczynajac od begin
    for(; wsk!= listaInt.end(); wsk++)
    {
        cout << *wsk << " ";
    }
    cout << endl;
    ///iteracja przez elementy
    for (auto i : listaInt)
    {
        cout << i << " ";
    }
    cout << endl;
    //pierwsza zawartosc
    cout << *(listaInt.begin()) << endl;

    ///adress pocztaku listy
    cout << listaInt.begin() << endl;

    return 0;
}
