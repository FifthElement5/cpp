#include <iostream>

using namespace std;

void strcpy1(char* dest, const char* source)
{
    while (*dest++ = *source++);
}

 char t1[40];
char t2[] = "ala i ola i ich kot";
const char t3[] = "????";
char t4[100];


int main()
{
    cout << t2 << "przed: "<< t1 << endl;
    strcpy1(t1, t2);
    cout <<"wynik: " << t1 << endl;
    strcpy1(t1, t3);
    cout << "wynik2: " << t1 << endl;
    strcpy1(t1, "Marysia");
    cout << "wynik3: " << t1 << endl;
}
