#include <stdio.h>

// Struktura reprezentująca liczbę zespoloną
typedef struct {
    float rzeczywista;
    float urojona;
} LiczbaZespolona;

// Funkcja do obliczania iloczynu dwóch liczb zespolonych
LiczbaZespolona obliczIloczyn(LiczbaZespolona z1, LiczbaZespolona z2) {
    LiczbaZespolona iloczyn;
    iloczyn.rzeczywista = z1.rzeczywista * z2.rzeczywista - z1.urojona * z2.urojona;
    iloczyn.urojona = z1.rzeczywista * z2.urojona + z1.urojona * z2.rzeczywista;
    return iloczyn;
}

// Funkcja do obliczania ilorazu dwóch liczb zespolonych
LiczbaZespolona obliczIloraz(LiczbaZespolona z1, LiczbaZespolona z2) {
    LiczbaZespolona iloraz;
    float mianownik = z2.rzeczywista * z2.rzeczywista + z2.urojona * z2.urojona;
    iloraz.rzeczywista = (z1.rzeczywista * z2.rzeczywista + z1.urojona * z2.urojona) / mianownik;
    iloraz.urojona = (z1.urojona * z2.rzeczywista - z1.rzeczywista * z2.urojona) / mianownik;
    return iloraz;
}

int main() {
    // Definicja dwóch liczb zespolonych
    LiczbaZespolona z1 = {3, 2};
    LiczbaZespolona z2 = {1, -1};

    // Wyznaczenie iloczynu
    LiczbaZespolona iloczyn = obliczIloczyn(z1, z2);
    printf("Iloczyn: %.2f + %.2fi\n", iloczyn.rzeczywista, iloczyn.urojona);

    // Wyznaczenie ilorazu
    LiczbaZespolona iloraz = obliczIloraz(z1, z2);
    printf("Iloraz: %.2f + %.2fi\n", iloraz.rzeczywista, iloraz.urojona);

    return 0;
}
