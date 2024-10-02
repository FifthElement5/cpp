#include <iostream>

using namespace std;

class Punkt2D {
    int x, y;
public:
    //konstruktor
    Punkt2D(int _x = 0, int _y = 0) :y{_y}, x{_x} {}
    //przeladowanie operator wyjsci a
    friend ostream& operator<<(ostream& ekran, const Punkt2D& a);
    //przeladowanie operator wejscie
    friend istream& operator>>(istream& klaw , Punkt2D& a);
};

class Krzywa {
    public:
    int w;
    Punkt2D *wsk;

    //konstruktor inicjuje krzywa z wszystkimi zerowymi punktami
    // w to liczba wymiaroww
    Krzywa (int _w) : w{_w}, wsk{new Punkt2D[w]}
        {
            for (int i = 0; i < w; i++){
                wsk[i]=0;
            }
        }
    // konstruktor kopiujacej
    Krzywa(const Krzywa& a) : w{a.w}, wsk{ new Punkt2D[w]}
    {
        Punkt2D* wsktmp = wsk;
        for (int i = 0; i <w; i++)
        {
            wsktmp[i] = a.wsk[i];
        }
    }

    //operator przypisania
    Krzywa& operator=(const Krzywa& a);

    //funkcja skladowa dodajace punkty krzywej
    void add(int _w);
    void usun(int _w);
    ~Krzywa()
    {
        delete[] wsk;
    }
    friend ostream& operator<<(ostream& ekran, const Krzywa& a);
};
ostream& operator<<(ostream& ekran, const Krzywa& a)
{
    for (int i = 0; i < a.w; i++)
    {
     ekran << "punkt " << i+1 << a.wsk[i];

    }
    return ekran;
}
istream& operator>>(istream& klaw, Krzywa& b)
{
    for (int i = 0; i < b.w; i++)
    {
        cout << i+1 << " wspolrzedna do krzywej " << endl;
        klaw >> b.wsk[i];


    }
       return klaw;
}

Punkt2D p1(1, 1);
Punkt2D p2, p3;
Krzywa t1(2);
Krzywa t3(3);
Krzywa t2{ t3};
//Krzywa t4;
int main()
{
    cout << p1;
    cin >> p1;
    cout << p1;
    cout << t1;
    cin >> t1;
    cout << t1;
    cout << "------- konstruktor kopiujacy" << endl;
    cout << t3;
    cout << "------- konstruktor kopiujacy" << endl;
    cout << t2;
    cout << "--------operator przypisania " << endl;
    t3 = t1;
    cout << t3;
    cout << "------dodawanie puntow na koncu" << endl;
    t1.add(3);
    cout << t1;
    cout << "------- odejmowanie puntow z konca" << endl;
    t1.usun(3);
    cout << t1;
    return 0;
}

// przeciazony operator wyjscia dla punkt2d

ostream& operator<<(ostream& ekran, const Punkt2D& a)
{
    ekran << " x= " << a.x << " y= " << a.y << endl;
    return ekran;
}

//przeciaznony operator wejscia dla 2d
istream& operator>>(istream& klaw, Punkt2D& a)
{
    cout << "podaj punkt x " ;
    klaw >> a.x;
    cout << "podaj punkt y " ;
    klaw >> a.y;
    return klaw;
}

Krzywa& Krzywa::operator=(const Krzywa& a) {
    if(w != a.w)
    {
        delete[] wsk;
        w = a.w;
        wsk = new Punkt2D[w];

    }
    for (int i=0; i<w; i++)
    {
        wsk[i] = a.wsk[i];
    }
    return *this;
}

void Krzywa::add(int count) {
    Punkt2D* newWsk = new Punkt2D[w + count];  // Tworzenie nowej tablicy o większym rozmiarze

    for (int i = 0; i < w; i++) {
        newWsk[i] = wsk[i];  // Kopiowanie istniejących elementów do nowej tablicy
    }

    for (int i = 0; i < count; i++) {
        cout << "Podaj punkt " << i + 1 << " (x i y): ";
        cin >> newWsk[w + i];  // Dodawanie nowych punktów wczytanych od użytkownika
    }

    delete[] wsk;  // Usuwanie starej tablicy
    wsk = newWsk;  // Przypisanie wskaźnika do nowej tablicy
    w += count;  // Zwiększenie rozmiaru
}

void Krzywa::usun(int count) {
        if (count > w) {
        cout << "Nie można usunąć więcej punktów niż istnieje w krzywej." << endl;
        return;
    }
    Punkt2D* newWsk = new Punkt2D[w-count];

    for(int i = 0; i < w -count; i++)
    {
        newWsk[i] = wsk[i];
    }
    delete[] wsk;
    wsk = newWsk;
    w -= count;
}
