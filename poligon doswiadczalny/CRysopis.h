#ifndef CRYSOPIS_H
#define CRYSOPIS_H
class CPrzestepca;

class CRysopis // klasa przechowuj¹ca atrybuty rysopisu przestepcy
{
protected:
	CString plec; // obiekt klasy CString przechowuj¹cy informacje o p³ci przestêpcy
	CString rok_ur; // obiekt klasy CString przechowuj¹cy informacje o roku urodzenia przestêpcy
	CString wzrost;// obiekt klasy CString przechowuj¹cy informacje wzroœcie przestêpcy
	CString waga;// obiekt klasy CString przechowuj¹cy informacje o wadze przestêpcy
	CString kolor_o;// obiekt klasy CString przechowuj¹cy informacje o koloru oczu przestêpcy
	CString kolor_w;// obiekt klasy CString przechowuj¹cy informacje o kolorze w³osów przestêpcy
	CString dlugosc_w;// obiekt klasy CString przechowuj¹cy informacje d³ugoœci w³osów przestêpcy
	CString narodowosc;// obiekt klasy CString przechowuj¹cy informacje o narodowoœci przestêpcy
	CString posiad_okul;// obiekt klasy CString przechowuj¹cy informacje o posiadaniu okularów przestêpcy
	CString miejsce_znamie;// obiekt klasy CString przechowuj¹cy informacje o widocznym znamieniu przestêpcy
public:
	CRysopis(); // konstruktor bezargumentowy
	~CRysopis(); //destruktor
	CRysopis(CString plec, CString rok_ur, CString wzrost, CString waga, CString kolor_o, CString kolor_w,
		CString dlugosc_w, CString narodowosc, 
		CString posiad_okul, CString miejsce_zam);// konstruktor wieloargumentowy
	CRysopis(const CRysopis & o); // konstruktor kopiujacy
	friend istream & operator>>(istream & is, CRysopis & o); // deklaracja przyjazni operatora wpisania ze strumienia
	friend ostream & operator<<(ostream & os, const CRysopis & o); //deklracja przyjazni operatora wypisania ze strumienia
	friend int zliczanie_wag(CRysopis & r, CPrzestepca & p); //deklaracja przyjaŸnik funkcji zliczanie_wag 
	bool wczytaj_rysopis_z_pliku(CString nazwa_pliku_wej); // metoda wczytuj¹ca rysopis przestêpcy z pliku 
	bool sprawdz_wejscie(); // metoda sprawdzaj¹ca poprawnoœæ danych wejœciowych 
};
istream & operator>>(istream & is, CRysopis & o); //operator wpisania ze strumienia
ostream & operator<<(ostream & os, const CRysopis & o); // operator wypisania do

#endif 
