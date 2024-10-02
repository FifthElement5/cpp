#include <stdio.h>

void odwrocona(char *tablica)
{
    // int rozmiar = sizeof(tablica)/sizeof(tablica[0])-1;

    int rozmiar = 0;
    while (tablica[rozmiar] != '\0') {
        rozmiar++;
    }

    //odwracamy tablice
    for (int i=0; i < rozmiar/2; i++)
    {
        char temp = tablica[i];
        tablica[i] = tablica[rozmiar - 1 -i];
        tablica[rozmiar-1-i] = temp;
    }
}
int main()
{
    char tekst[] = "abcd";
    odwrocona(tekst);

    printf("wynik: %s", tekst);

    return 0;
}
