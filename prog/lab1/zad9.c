#include <stdio.h>

void wypiszTrojkat() {
    int cyfra = 1;

    for (int i = 1; i <= 9; ++i) {
        for (int j = 1; j <= i; ++j) {
            printf("%d ", cyfra);
        }
        cyfra++;
        printf("\n");
    }
}

int main() {
    wypiszTrojkat();

    return 0;
}
