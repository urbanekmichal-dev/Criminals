
#ifndef CPRZESTEPSTWA_H
#define CPRZESTEPSTWA_H

class CPrzestepstwa :public CNr_pesel //klasa przechowuj�ca informacje o atrybutach przest�pstw
{
private:
	CString data; // klasa �a�cucha przechowuj�ca informacje o dacie przest�pstwa
	CString rodzaj; // klasa �a�cucha przechowuj�ca infomacje o rodzaju przestepstwa
public:
	CPrzestepstwa(); //konstruktor bezargumentowy
	~CPrzestepstwa(); //destruktor
	CPrzestepstwa(CString nr_pesel, CString data, CString rodzaj); //konstruktor wieloargumentowy
	CPrzestepstwa(const CPrzestepstwa & o); //konstruktor kopiuj�cy
	friend ostream & operator<<(ostream & os, const CPrzestepstwa & o); //deklaracja przyja�ni operatora wypisuj�cego do strumienia
	friend istream & operator >>(istream & is, CPrzestepstwa & o); // deklaracja przyja�ni operatora wpisuj�cego ze strumienia
	bool sprawdz_wejscie(); // metoda sprawdzaj�ca poprawno�� odczytywanych z pliku danych 
};
ostream & operator<<(ostream & os, const CPrzestepstwa & o); // operator wypisania do sturminia
istream & operator >>(istream & is, CPrzestepstwa & o); //operator wpisania ze strumienia

struct CPrzestepstwa_elem //struktura przechowuj�ca obiekt klasy CPrzestepstwa
{
	CPrzestepstwa nowe_przestepstwo; // obiekt klasy CPrzestepstwa
	CPrzestepstwa_elem * next; // wska�nik na nastepny element 
	CPrzestepstwa_elem(const CPrzestepstwa & o); // konstruktor kopiuj�cy
};
#endif