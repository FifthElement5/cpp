#include <stdio.h>
#include <math.h>

int vektor(int x1[], int x2[])
{
    int suma = 0;
    for (int i=0; i<3 ; i++)
    {
        int r = x1[i] - x2[i];
        suma += (r*r);
    }
 return suma;

};


int main() {
    int x1[] = {3, 3, 3};
    int x2[] = {3, 3, 3};

    int V = vektor(x1, x2);
    printf("wynik: %d \n", V);
}
