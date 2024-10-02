#include <stdio.h>
#include <stdlib.h>

float znajdzMin(float tablica[], int n) {

    //inicjalizacja min i max
    float min = tablica[0];



    for (int i =0; i < n; i++) {
        if (tablica[i] < min) {
            min = tablica[i];

   }

}
    return min;
}

float znajdzMax(float tablica[], int n)
{
    float max = tablica[0];
    for (int i=0; i < n; i++)
    {
        if(tablica[i] > max)
        {
            max = tablica[i];
        }
    }
    return max;
}

int main(void)
{
    float min, max;

    float tablica[] = {1.5, 5.2, 6.3, 8.2, 1};
      int n = sizeof(tablica)/sizeof(tablica[0]);



   min = znajdzMin(tablica, n);
   max  = znajdzMax(tablica, n);

    printf("Minimum: %.2f \n" , min);
    printf("Maximum: %.2f \n", max);
    return(0);
}




// #include <stdio.h>
// #include <stdlib.h>

// void znajdz(float tablica[], int n,  float *min, float *max) {

//     //inicjalizacja min i max
//     *min = tablica[0];
//     *max = tablica[0];

//     for (int i =0; i < n; i++) {
//         if (tablica[i] < *min) {
//             *min = tablica[i];
//         }
//         if (tablica[i] > *max) {
//             *max = tablica[i];
//         }
//    }

// }

// int main(void)
// {
//     float min, max;
//     float tablica[] = {1.5, 5.2, 6.3, 8.2};


//     int n = 4;
//     znajdz(tablica, n, &min, &max);

//     printf("Minimum: %.2f \n" , min);
//     printf("Maximum: %.2f \n", max);
//     return(0);
// }

