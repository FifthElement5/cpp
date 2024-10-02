#include <iostream>

using namespace std;

int a = 3;
double b;

int* wsk1;
double* wsk2;

int main()
{
    cout << "rozmiar int = " << sizeof(a) << endl;
    cout << "rozmiar double = " << sizeof(b) << endl;
    cout << "rozmiar long double = " << sizeof(long  double) << endl;
    cout << "rozmiar int * = " << sizeof(wsk1) << endl;
    cout << "rozmiar double * = " << sizeof(double*) << endl;
    cout << "rozmiar char * = " << sizeof(char*) << endl;
    cout << "rozmiar long long * = " << sizeof(long long*) << endl;
}
