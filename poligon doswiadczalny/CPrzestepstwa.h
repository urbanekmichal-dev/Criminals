
#ifndef CPRZESTEPSTWA_H
#define CPRZESTEPSTWA_H

class CPrzestepstwa :public CNr_pesel //klasa przechowująca informacje o atrybutach przestępstw
{
private:
	CString data; // klasa łańcucha przechowująca informacje o dacie przestępstwa
	CString rodzaj; // klasa łańcucha przechowująca infomacje o rodzaju przestepstwa
public:
	CPrzestepstwa(); //konstruktor bezargumentowy
	~CPrzestepstwa(); //destruktor
	CPrzestepstwa(CString nr_pesel, CString data, CString rodzaj); //konstruktor wieloargumentowy
	CPrzestepstwa(const CPrzestepstwa & o); //konstruktor kopiujący
	friend ostream & operator<<(ostream & os, const CPrzestepstwa & o); //deklaracja przyjaźni operatora wypisującego do strumienia
	friend istream & operator >>(istream & is, CPrzestepstwa & o); // deklaracja przyjaźni operatora wpisującego ze strumienia
	bool sprawdz_wejscie(); // metoda sprawdzająca poprawność odczytywanych z pliku danych 
};
ostream & operator<<(ostream & os, const CPrzestepstwa & o); // operator wypisania do sturminia
istream & operator >>(istream & is, CPrzestepstwa & o); //operator wpisania ze strumienia

struct CPrzestepstwa_elem //struktura przechowująca obiekt klasy CPrzestepstwa
{
	CPrzestepstwa nowe_przestepstwo; // obiekt klasy CPrzestepstwa
	CPrzestepstwa_elem * next; // wskaźnik na nastepny element 
	CPrzestepstwa_elem(const CPrzestepstwa & o); // konstruktor kopiujący
};
#endif