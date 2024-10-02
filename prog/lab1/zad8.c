#include <stdio.h>

int main() {
    char tekst[] = "abc";

    for (char *ptr = tekst; *ptr != '\0'; ++ptr) {
        printf("znak %c liczba %d\n", *ptr, *ptr);
    }

    return 0;
}
