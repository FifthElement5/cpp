#include <stdio.h>
#include <stdlib.h>

#define N 2
#define M 4

double znajdzMin(double tablica[N][M]) {

    //inicjalizacja min i max
    double min = tablica[0][0];



    for (int i =0; i < N; i++) {
        for (int j=0; j < M; j++) {
        if (tablica[i][j] < min) {
            min = tablica[i][j];

   }
        }

}
    return min;
}

double znajdzMax(double tablica[N][M])
{
    double max = tablica[0][0];

    for (int i=0; i < N; i++)
    {
        for (int j=0; j < M; j++)
        {
            if(tablica[i][j] > max)
            {
                max = tablica[i][j];
            }
        }
    }
    return max;
}
void drukujTablice(double tablica[N][M]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("%.2f ", tablica[i][j]);
        }
        printf("\n");
    }
}




int main(void)
{
    double min, max;

    double tablica[N][M] = {{9, 50, 6, 10}, {1, 2, 3, 4}};



   min = znajdzMin(tablica);
   max = znajdzMax(tablica);
   //max  = znajdzMax(tablica, n);

   drukujTablice(tablica);

    printf("Minimum: %.2f \n" , min);
    printf("Maximum: %.2f \n", max);

    return(0);
}

