#ifndef CRYSOPIS_H
#define CRYSOPIS_H
class CPrzestepca;

class CRysopis // klasa przechowuj�ca atrybuty rysopisu przestepcy
{
protected:
	CString plec; // obiekt klasy CString przechowuj�cy informacje o p�ci przest�pcy
	CString rok_ur; // obiekt klasy CString przechowuj�cy informacje o roku urodzenia przest�pcy
	CString wzrost;// obiekt klasy CString przechowuj�cy informacje wzro�cie przest�pcy
	CString waga;// obiekt klasy CString przechowuj�cy informacje o wadze przest�pcy
	CString kolor_o;// obiekt klasy CString przechowuj�cy informacje o koloru oczu przest�pcy
	CString kolor_w;// obiekt klasy CString przechowuj�cy informacje o kolorze w�os�w przest�pcy
	CString dlugosc_w;// obiekt klasy CString przechowuj�cy informacje d�ugo�ci w�os�w przest�pcy
	CString narodowosc;// obiekt klasy CString przechowuj�cy informacje o narodowo�ci przest�pcy
	CString posiad_okul;// obiekt klasy CString przechowuj�cy informacje o posiadaniu okular�w przest�pcy
	CString miejsce_znamie;// obiekt klasy CString przechowuj�cy informacje o widocznym znamieniu przest�pcy
public:
	CRysopis(); // konstruktor bezargumentowy
	~CRysopis(); //destruktor
	CRysopis(CString plec, CString rok_ur, CString wzrost, CString waga, CString kolor_o, CString kolor_w,
		CString dlugosc_w, CString narodowosc, 
		CString posiad_okul, CString miejsce_zam);// konstruktor wieloargumentowy
	CRysopis(const CRysopis & o); // konstruktor kopiujacy
	friend istream & operator>>(istream & is, CRysopis & o); // deklaracja przyjazni operatora wpisania ze strumienia
	friend ostream & operator<<(ostream & os, const CRysopis & o); //deklracja przyjazni operatora wypisania ze strumienia
	friend int zliczanie_wag(CRysopis & r, CPrzestepca & p); //deklaracja przyja�nik funkcji zliczanie_wag 
	bool wczytaj_rysopis_z_pliku(CString nazwa_pliku_wej); // metoda wczytuj�ca rysopis przest�pcy z pliku 
	bool sprawdz_wejscie(); // metoda sprawdzaj�ca poprawno�� danych wej�ciowych 
};
istream & operator>>(istream & is, CRysopis & o); //operator wpisania ze strumienia
ostream & operator<<(ostream & os, const CRysopis & o); // operator wypisania do

#endif 
