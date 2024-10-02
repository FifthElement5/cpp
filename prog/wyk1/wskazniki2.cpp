#include <iostream>
#include <stdio.h>

using std::cout; using std::cin; using std::endl;

int a = 4, b = 5;
char t[] = "ALA";
int * wsk1, *wsk2;
char* wsk3;
void* wskV;
int** wsk11;
int** wsk22;

int main()
{

    wsk1 = &a;
    wsk2 = &b;
    wsk11 = &wsk1;
    cout << " wsk11 = " << wsk11 << endl;
    cout << " * wsk11 = " << *wsk11 << endl;
    cout << " wsk1 = &a= wskazuje na adres" << wsk1 << endl;
    cout << " wsk2 = &b= wskazuje na adres" << wsk2 << endl;
     cout << " ** wsk11 = " << **wsk11 << endl;
    cout << " * wsk1 wskazuje na to co jest w adresie= " << *wsk1 << endl;
    cout << " * wsk2 wskazuje na to co jest w adresie= " << *wsk2 << endl;
    wskV = &a;
    wsk3 = &t[0];
    wsk22 = &wsk2;
    cout << "wsk22 adres wsk2 = " << wsk22 << endl;
    cout << "*wsk22 adres b = " << *wsk22 << endl;
    cout << "**wsk22 to co jest pod adresem b = " << **wsk22 << endl;
    cout << "wskV = " << wskV << endl;
    cout << " *wsk3 = " << *wsk3 << endl;
    cout << "wsk3 = " << wsk3 << endl;

    printf("lol");

 }
