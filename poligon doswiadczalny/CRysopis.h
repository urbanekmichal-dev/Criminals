#ifndef CRYSOPIS_H
#define CRYSOPIS_H
class CPrzestepca;

class CRysopis // klasa przechowująca atrybuty rysopisu przestepcy
{
protected:
	CString plec; // obiekt klasy CString przechowujący informacje o płci przestępcy
	CString rok_ur; // obiekt klasy CString przechowujący informacje o roku urodzenia przestępcy
	CString wzrost;// obiekt klasy CString przechowujący informacje wzroście przestępcy
	CString waga;// obiekt klasy CString przechowujący informacje o wadze przestępcy
	CString kolor_o;// obiekt klasy CString przechowujący informacje o koloru oczu przestępcy
	CString kolor_w;// obiekt klasy CString przechowujący informacje o kolorze włosów przestępcy
	CString dlugosc_w;// obiekt klasy CString przechowujący informacje długości włosów przestępcy
	CString narodowosc;// obiekt klasy CString przechowujący informacje o narodowości przestępcy
	CString posiad_okul;// obiekt klasy CString przechowujący informacje o posiadaniu okularów przestępcy
	CString miejsce_znamie;// obiekt klasy CString przechowujący informacje o widocznym znamieniu przestępcy
public:
	CRysopis(); // konstruktor bezargumentowy
	~CRysopis(); //destruktor
	CRysopis(CString plec, CString rok_ur, CString wzrost, CString waga, CString kolor_o, CString kolor_w,
		CString dlugosc_w, CString narodowosc, 
		CString posiad_okul, CString miejsce_zam);// konstruktor wieloargumentowy
	CRysopis(const CRysopis & o); // konstruktor kopiujacy
	friend istream & operator>>(istream & is, CRysopis & o); // deklaracja przyjazni operatora wpisania ze strumienia
	friend ostream & operator<<(ostream & os, const CRysopis & o); //deklracja przyjazni operatora wypisania ze strumienia
	friend int zliczanie_wag(CRysopis & r, CPrzestepca & p); //deklaracja przyjaźnik funkcji zliczanie_wag 
	bool wczytaj_rysopis_z_pliku(CString nazwa_pliku_wej); // metoda wczytująca rysopis przestępcy z pliku 
	bool sprawdz_wejscie(); // metoda sprawdzająca poprawność danych wejściowych 
};
istream & operator>>(istream & is, CRysopis & o); //operator wpisania ze strumienia
ostream & operator<<(ostream & os, const CRysopis & o); // operator wypisania do

#endif 
