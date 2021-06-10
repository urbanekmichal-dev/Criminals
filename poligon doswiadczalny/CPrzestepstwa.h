
#ifndef CPRZESTEPSTWA_H
#define CPRZESTEPSTWA_H

class CPrzestepstwa :public CNr_pesel //klasa przechowuj¹ca informacje o atrybutach przestêpstw
{
private:
	CString data; // klasa ³añcucha przechowuj¹ca informacje o dacie przestêpstwa
	CString rodzaj; // klasa ³añcucha przechowuj¹ca infomacje o rodzaju przestepstwa
public:
	CPrzestepstwa(); //konstruktor bezargumentowy
	~CPrzestepstwa(); //destruktor
	CPrzestepstwa(CString nr_pesel, CString data, CString rodzaj); //konstruktor wieloargumentowy
	CPrzestepstwa(const CPrzestepstwa & o); //konstruktor kopiuj¹cy
	friend ostream & operator<<(ostream & os, const CPrzestepstwa & o); //deklaracja przyjaŸni operatora wypisuj¹cego do strumienia
	friend istream & operator >>(istream & is, CPrzestepstwa & o); // deklaracja przyjaŸni operatora wpisuj¹cego ze strumienia
	bool sprawdz_wejscie(); // metoda sprawdzaj¹ca poprawnoœæ odczytywanych z pliku danych 
};
ostream & operator<<(ostream & os, const CPrzestepstwa & o); // operator wypisania do sturminia
istream & operator >>(istream & is, CPrzestepstwa & o); //operator wpisania ze strumienia

struct CPrzestepstwa_elem //struktura przechowuj¹ca obiekt klasy CPrzestepstwa
{
	CPrzestepstwa nowe_przestepstwo; // obiekt klasy CPrzestepstwa
	CPrzestepstwa_elem * next; // wskaŸnik na nastepny element 
	CPrzestepstwa_elem(const CPrzestepstwa & o); // konstruktor kopiuj¹cy
};
#endif