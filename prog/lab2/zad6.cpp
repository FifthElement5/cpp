#include <iostream>

using namespace std;


//sparwdza dlugosc napisu
int strlen1(const char *s)
{
    int l = 0;
    while (*s != '\0')
    {
        s++;
        l++;

    }
    return l;
}
// kopiuje napisa z jednego miejca na drugie
void strcpy1(char* dest,  const char* source, int size)
{
    //sparwdza dlugosc docelowej tabeli i drukuje tylko tyle


    for (int i=0; i < size; i++)
    {
        *dest++ = *source++;
    }


}

int strcmp2(const char* n1, const char* n2) {
    while (*n1 && *n2 && *n1 == *n2) {
        n1++;
        n2++;
    }
    // Sprawdzenie czy oba napisy są zakończone (czy równość napisów)
    if (*n1 == '\0' && *n2 == '\0') {
        return 0; // Napisy są równe
    } else {
        return 1; // Napisy są różne
    }
}
//znajdowanie znaku
const char* strchr(const char* n, char z) {
    while (*n != '\0') {
        if (*n == z) {
            return n; // Znaleziono znak, zwraca wskaźnik do niego
        }
        n++;
    }
    return nullptr; // Nie znaleziono znaku, zwraca nullptr
}

//ODWROCENIE
void strrev(char* n) {
    int length = strlen1(n);
    for (int i = 0; i < length / 2; i++) {
        char temp = n[i];
        n[i] = n[length - i - 1];
        n[length - i - 1] = temp;
    }
}

char t1[] = "iza";
char t2[] = "?? ala i ola i ich kot";
const char t3[] = "ala";
char t4[100];


int main()
{

    // dlugosc
    int z = strlen1(t2);
    std::cout << "dlugosc: "<< z << endl;
    int size = sizeof(t1)/sizeof(t1[0]);
    strcpy1(t1, t2, size);
    cout << "skopiwonanie: " << t1 <<  endl;

    int rowne = strcmp2(t1, t2);
    cout << "rowne wynik: " << rowne << endl;

//// SZUKANIE ZNAKU
    char znak = 'a';
    const char* wynik = strchr(t1, znak);

        if (wynik != nullptr) {
        cout << "Znaleziono znak '" << znak << endl;
    } else {
        cout << "Nie znaleziono znaku '" << znak << endl;
    }

    //odwrcenie napisu
    cout << "napis przed: " << t2 << endl;
    strrev(t2);
    cout << "napis po: " << t2 << endl;



}


