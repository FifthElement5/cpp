#include <stdio.h>

int zwiekszacz(int n)
{
    n++;
    return n;
};

int main(void) {

    int n;
    printf("Podaj liczbe: ");
    scanf("%d", &n);


    for (int i=0; i<17; i++) {
    n = zwiekszacz(n);
    printf("Argument: %d, Zwiekszacz(%d) = %d\n",i ,i , n-1);
    }


}
