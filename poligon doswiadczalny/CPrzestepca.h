#ifndef CPRZESTEPCA_H
#define CPRZESTEPCA_H

class CPrzestepca : public CRysopis, public CNr_pesel //Kklasa przechowuj�ca informacje o atrybutach przestepcy
{
private:
	static int wagi[10]; // statyczna tablica liczb ca�kowitych, przechowuj�ca wagi odpowiadaj�ce odpowiednim cechom rysopisu
	int punkty; // zmienna przechowuj�ca sum� punkt�w otrzymanych za zgodno�� cech z rysopisem 
	bool cechy[10]; // tablica zmiennych boolowskich, zawieraj�ca informacje o zgodno�ci cech 
public:
	CPrzestepca(); // konstruktor bezargumentowy
	~CPrzestepca(); //destruktor
	CPrzestepca(CString nr_pesel, CString plec, CString rok_ur, CString wzrost, CString waga, CString kolor_o,
		CString kolor_w, CString dlugosc_w, 
		CString narodowosc, CString posiad_okul, CString miejsce_zam); //konstruktor wieloargumentowy
	CPrzestepca(const CPrzestepca & o);//Konstruktor kopiujacy
	friend ostream & operator<<(ostream & os, const CPrzestepca & o); // deklaracja przyjazni operatora wypisania
	friend istream & operator >>(istream & is, CPrzestepca & o); //deklaracja przyjazni operatora wpisania
	ostream & wypisz_przestepce(ostream & strumien); //metoda wypisujaca do strumienia zgodne z rysopisem atrybuty przestepcy
	void operator+=(int liczba);//operator przypisania warto�ci liczba do atrybutu punkty
	friend int zliczanie_wag(CRysopis & r, CPrzestepca& p); // deklaracja przyjazni funkcji zliczanie wag
};
int zliczanie_wag(CRysopis & r, CPrzestepca& p); // funkcja obliczaj�ca sum� punkt�w, otrzymywanych za zgodno�� cechy przest�pcy z cech� rysopisu

ostream & operator<<(ostream & os, const CPrzestepca & o); // operator wypisania do strumienia
istream & operator >>(istream & is, CPrzestepca & o); // operator wpisania do strumienia

struct CPrzestepca_elem // struktura przechowuj�ca obiekt klasy CPrzestepca
{
	CPrzestepca nowy_przestepca; // obiekt klasy CPrzestepca, przechowuj�cy informacje o atrybutach przestepcy
	CPrzestepca_elem * next; //wska�nik na element nast�pny 
	CPrzestepca_elem * prev; //wska�nik na element poprzedni
	CPrzestepstwa_elem * head_CPrzestepstwa; // wska�nik na pocz�tek listy przest�pstw pope�nionych przez danego przest�pce
	CPrzestepca_elem(const CPrzestepca & o); // konstruktor kopiuj�cy 
};

#endif