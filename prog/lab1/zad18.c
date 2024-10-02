#include <stdio.h>

#define K 2
#define W 4


void wypiszTablice(int t[W][K]) {
    // cyfra wypelnia liczby
    int cyfra = 0;

    for (int i = 0; i < W; ++i) {

        for (int j = 0; j < K; ++j) {
            cyfra++;
            t[i][j] = cyfra;
            printf("%3d ", t[i][j]);
        }

        printf("\n");

    }
}

void wypiszTablicePo(int t[W][K], int v[K]) {
    // cyfra wypelnia liczby
    int cyfra = 0;

    for (int i = 0; i < W; ++i) {

        for (int j = 0; j < K; ++j) {
            cyfra++;
            t[i][j] = cyfra;
            printf("%3d ", t[i][j]);
        }
        // drukuje vektor
        printf("\n");
        for (int k = 0; k < K; k++) {
            printf("%3d ", v[k]);
        }
        printf("\n");
    }
}


int main(void)
{
    int tablica[W][K];

   printf("PRZED: \n");
    wypiszTablice(tablica);

    int Vektor[] = {10, 20};
    printf("PO: \n");
    wypiszTablicePo(tablica, Vektor);
}

