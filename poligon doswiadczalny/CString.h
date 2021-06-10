
#ifndef CSTRING_H
#define CSTRING_H

using namespace std;

class CString // klasa przechowuj�ca �ancuch znak�w 
{
protected:
	char * data; //wska�nik na pierwszy element tablicy dynamicznej �a�cuchu znak�w
	unsigned int size; // atrybut przechowuj�cy d�ugo�� �a�cucha znak�w

public:
	CString(); //konstruktor bezargumentowy
	CString(const char * str); //konstruktor argumentowy
	CString(const CString &str); //konstruktor kopiuj�cy
	~CString(); //destruktor
	bool compare(const CString & str) const; // metoda por�wnuj�ca dwa �a�cuchy znak�w
	unsigned int getLength() const; //metoda zwracaj�ca d�ugo�� �a�ucha znak�w
	void setLength(unsigned int size); //metoda ustawiaj�ca atrybut d�ugo�ci �a�cucha znak�w
	void add(const CString & text); //metoda dodaj�ca �a�cuch znak�w, do ju� istniej�cego �a�cucha znak�w
	CString & operator=(const CString & str); //operator przypisania do �a�cucha znak�w
	friend ostream & operator<<(ostream &s, const CString & str);// deklaracja przyja�ni operatora wypisania do strumienia
	friend istream & operator>>(istream & IS, CString & S); // deklaracja przyja�ni operatora wpisania ze strumienia
	bool  operator!=(CString & o); // operator por�wnania( r�ny od ), por�wnuj�cy dwa ���cuchy znakowe
	bool operator==(const char * o); // operator por�wnania (jest r�wny ), por�wnuj�cy �a�uch znakowy oraz tablic� znak�w
	char * get(); // metoda zwracaj�ca wska�nik na dynamiczn� tablic� znak�w klasy CString
	bool sprawdz_czy_same_cyfry(); // metoda sprawdzaj�ca czy zawarto�� tablicy atrybutu data, jest cyfr�
	bool sprawdz_czy_data(); //metoda sprawdzaj�ca czy zawarto�� tablicy atrybutu ma format daty

};
ostream & operator<<(ostream &s, const CString & str); // operator wypisania do strumienia
istream & operator>>(istream & IS, CString & S); //operator wpisania ze strumienia
bool operator==(const CString & str1, const CString & str2); // operator por�wnuj�cy dwa �a�uchy znak�w
CString operator+(const CString & str1, const CString & str2); // operator dodaj�cy do jedengo �a�cucha znak�w drugi �a�cuch znak�w

#endif // !FUNKCJE_H
