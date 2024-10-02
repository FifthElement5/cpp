#include <iostream>
#include <string>

// Funkcja do odwracania stringa
void odwroc(std::string& tekst) {
    int rozmiar = tekst.size();
    for (int i = 0; i < rozmiar / 2; ++i) {
        std::swap(tekst[i], tekst[rozmiar - 1 - i]);
    }
}

int main() {
    std::string tekst = "abcd";
    odwroc(tekst);
    std::cout << "Wynik: " << tekst << std::endl;
    return 0;
}
