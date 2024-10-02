#include <stdio.h>

struct Date {
    int day;
    int month;
    int year;
};

// Funkcja porównująca daty
int compareDates(struct Date date1, struct Date date2) {
    if (date1.year < date2.year)
        return -1;
    else if (date1.year > date2.year)
        return 1;
    else {
        if (date1.month < date2.month)
            return -1;
        else if (date1.month > date2.month)
            return 1;
        else {
            if (date1.day < date2.day)
                return -1;
            else if (date1.day > date2.day)
                return 1;
            else
                return 0;  // Daty są identyczne
        }
    }
}

int main() {
    struct Date date1, date2;

    // Wczytanie daty 1
    printf("Podaj datę 1 (dzień miesiąc rok): ");
    scanf("%d %d %d", &date1.day, &date1.month, &date1.year);

    // Wczytanie daty 2
    printf("Podaj datę 2 (dzień miesiąc rok): ");
    scanf("%d %d %d", &date2.day, &date2.month, &date2.year);

    // Porównanie dat i wyświetlenie wyniku
    int result = compareDates(date1, date2);
    if (result < 0)
        printf("Data 1 jest wcześniejsza.\n");
    else if (result > 0)
        printf("Data 2 jest wcześniejsza.\n");
    else
        printf("Obie daty są identyczne.\n");

    return 0;
}
