#include <stdio.h>

int main()
{
    char tekst[] = "abc";
    int N = sizeof(tekst)/sizeof(tekst[0]);
    char odwrocony[N];
    printf("to %d \n", N);

    int index = 0; // index w tablicy odwrocony

    for (char *ptr = tekst; *ptr != '\0'; ++ptr)
    {
        odwrocony[N-1-index] = *ptr;
        index++;

    }
    for (int i=1; i<N; i++)
    {
        printf("%c", odwrocony[i]);
    }
    printf("\n");

    return 0;

}
