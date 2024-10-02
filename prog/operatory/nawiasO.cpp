#include <iostream>
using namespace std;

class Foo {
public:
    // Przeładowanie operatora () z dwoma argumentami
    int operator()(int a, int b) {
        return a + b;
    }
};

int main() {
    Foo foo;

    // Użycie obiektu foo jak funkcji
    int result = foo(10, 20);

    cout << "Wynik: " << result << endl;  // Wynik: 30

    return 0;
}
