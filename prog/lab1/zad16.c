#include <stdio.h>

int suma(int N, int tablica[])

{
    int suma = 0;
    for (int i=0; i < N; i++)
    {
        suma += tablica[i];
    }
    return suma;
}

int srednia(int N, int suma)
{
    return suma/N;
}

int main(void)
{
    int tablica[]= {1, 2, 3};
    int N = sizeof(tablica)/sizeof(tablica[0]);

    printf("suma: %d\n", suma(N, tablica));
    printf("srednia: %d\n", srednia(N, suma(N, tablica)));
}
