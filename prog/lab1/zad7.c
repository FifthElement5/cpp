#include <stdio.h>

int max(int a, int b, int c) {
    int M = a;
    if (b > M)
    {
        M = b;

    }
    if (c > M)
    {
        M = c;
    }
    return M;
}

int main() {
    int a = 9;
    int b = 1;
    int c = 9;

    int wynik = max(a, b, c);

    printf("Max to: %d\n", wynik);

}
