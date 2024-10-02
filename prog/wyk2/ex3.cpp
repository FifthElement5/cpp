#include <iostream>

void strcpy1(char* s1, const char* s2){while (*s1++ = *s2++);}

using namespace std;


int* wsk1, * wsk2;

char* wsk3;

char t[] = "Marysia";

int main()
{
	wsk1 = new int;
	*wsk1 = 44;
    cout << *wsk1 <<endl;
	delete wsk1;
	wsk1 = new int[4];
	wsk1[3] = 44;
	delete [] wsk1;
	wsk3 = new char[30];
	strcpy1(wsk3, t);
	cout << wsk3 << endl;
	strcpy1(wsk3, "ALA");
	cout << wsk3 << endl;
}
