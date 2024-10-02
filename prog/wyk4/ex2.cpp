#include <iostream>
using namespace std;

void fun3(char a, double b) { cout << " char , double" << endl; }
//void fun3(double a, char b) { cout << " double, char " << endl; }
//void fun2(const double* a) { cout << " const double * " << endl; }
//void fun2(double* a) { cout << "  double * " << endl; }
//void fun1(const double & a) { cout << " const double * " << endl; }
//void fun1(double & a) { cout << "  double * " << endl; }
int fun() { cout << " nic na wejsciu " << endl; return 0; }  // fun();
int fun(char c) { cout << " char  " << endl; return 0; }
//int fun(int a) { cout << " int" << endl;  return 0; }
//int fun(int a, int b) { cout << " int, int" << endl; return 0; }
int fun(int a, int b = 11, int c = 0) { cout << " int, int, int" << endl; return 0; }



int main()
{

    cout << endl;
    fun('a');
    int x;
	x = fun(4, 4, 4);
    //cout << "lol " << x << endl;
    fun();
    fun3('b', 44);
    //fun(3b, 33);
    //fun(7, 77, 777);
}
