
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>

using namespace std;

class String1 {
	int roz;            // rozmiat przydzielonej pamieci dla tablicy znków
	char* wsk;          //wskażnik na tablice
	static int pamiec;  //stayczna zmienna przechowujaca całkowita ilosc przydzielonej pamieci
public:

    //konstruktor domyslny z parametrem r=8
	String1(int r = 8) : roz{ r }, wsk(new char[roz]) { pamiec += (sizeof(char) * (roz + 1)); }
	//konstruktor przyjmujący tablice znaków (ciag znaków)
    String1(const char t[]) :roz{(((int)strlen(t) / 8) + 1) * 8 }, wsk(new char[roz + 1]) {
		strcpy(wsk, t);    // kopiwoanie zawartosci tablicy znaków
		// aktualizacja ilosci przydzielone pamieci
        pamiec += (sizeof(int) * (size_t)(roz));

	}
    // konstruktor kopiujacy
	String1(const String1&);

    // operator przypisania(mmetoda)
	String1& operator=(const String1&);

    //destruktor zwlanianie pamieci
	~String1() { delete[] wsk; pamiec -= (sizeof(char) * (size_t)(roz)); }
	//konwersja na int (rozmiar tablicy)
    operator int() { return roz; }
	//operator float () { return roz; }

    //konwersja na chr8 (ciag znakow)
	operator char* () { return wsk; }

    //operator << do wypisywania obiektu String1
	friend ostream& operator << (ostream&, const String1&);

    //operator indeksowania []
    char& operator [] (int i) { return *(wsk + i); }
};
//inicjalizacja statycznje zmiennej
int String1::pamiec = 0;
// inicjalizacja obiektu s1 ciagiem znakow
String1 s1("Ala i Ola");

int main()
{
	cout << s1 << endl; // wypisywanie obiektu s1
	{
		String1 s2 = s1; // kopiowanie obiekty s1 do s2 (konstruktor kopiujący)
		String1 s3("Ala i Ola i ich pies Franek");

	}
    //zmiana jednego znaku w obiekcie s1
	s1[7] = 't';
	cout << " rozmiar s1 = " << (int)s1 << endl;

	return 0;
}

// definicja konstruktora kopiujacego
String1::String1(const String1& s) :roz{ s.roz }, wsk{ new char[roz + 1] } {
	//kopiownaie zawartosci tablicy znaow
    strcpy(wsk, s.wsk);
    //aktualizacja ilosci przydzielonej pamieci
	pamiec += (sizeof(int) * (roz));
}

//definicja operatora przypisania
String1& String1::operator=(const String1& s) {
    // sparwdznie czy rozmiary sa różne
	if (roz != s.roz) {
        //zwalnianie starej pamieci;
		delete[] wsk;
        //aktualizacja ilosci przydzielanej pamieci
		pamiec -= (sizeof(char) * roz);
		roz = s.roz,
			wsk = new char[roz + 1];
		pamiec += (sizeof(char) * (size_t)(roz + 1));
	}
    //kopiwoanie zawartości tablicy znaków
	strcpy(wsk, s.wsk);
    //zwracanie bieżacego obiektu
	return *this;
}

// defincija opartora << do wypiwyania obiektu String1
ostream& operator << (ostream& out, const  String1& s) {
	//wypisywanie zawartosci tablic znków
    cout << s.wsk;
	return  out;
}
