#include <iostream>
using namespace std;

class ArrayWrapper {
private:
    int array[5];  // Przykładowa tablica przechowywana w klasie
public:
    // Przeładowanie operatora []
    int& operator[](int index) {
        if (index < 0 || index >= 5) {
            cout << "Indeks poza zakresem!" << endl;
            // Można rzucić wyjątek lub zwrócić odpowiednią wartość domyślną
            // W tym przypadku zwracamy pierwszy element w przypadku błędnego indeksu
            return array[0];
        }
        return array[index];
    }
};

int main() {
    ArrayWrapper arr;

    // Użycie operatora [] do odczytu i zapisu elementów
    arr[0] = 10;
    arr[1] = 20;

    cout << "Element 0: " << arr[0] << endl;  // Output: Element 0: 10
    cout << "Element 1: " << arr[1] << endl;  // Output: Element 1: 20

    // Próba dostępu do elementu poza zakresem
    cout << "Element 5: " << arr[5] << endl;  // Output: Indeks poza zakresem!

    return 0;
}

