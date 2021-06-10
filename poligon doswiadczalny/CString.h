
#ifndef CSTRING_H
#define CSTRING_H

using namespace std;

class CString // klasa przechowuj¹ca ³ancuch znaków 
{
protected:
	char * data; //wskaŸnik na pierwszy element tablicy dynamicznej ³añcuchu znaków
	unsigned int size; // atrybut przechowuj¹cy d³ugoœæ ³añcucha znaków

public:
	CString(); //konstruktor bezargumentowy
	CString(const char * str); //konstruktor argumentowy
	CString(const CString &str); //konstruktor kopiuj¹cy
	~CString(); //destruktor
	bool compare(const CString & str) const; // metoda porównuj¹ca dwa ³añcuchy znaków
	unsigned int getLength() const; //metoda zwracaj¹ca d³ugoœæ ³añucha znaków
	void setLength(unsigned int size); //metoda ustawiaj¹ca atrybut d³ugoœci ³añcucha znaków
	void add(const CString & text); //metoda dodaj¹ca ³añcuch znaków, do ju¿ istniej¹cego ³añcucha znaków
	CString & operator=(const CString & str); //operator przypisania do ³añcucha znaków
	friend ostream & operator<<(ostream &s, const CString & str);// deklaracja przyjaŸni operatora wypisania do strumienia
	friend istream & operator>>(istream & IS, CString & S); // deklaracja przyjaŸni operatora wpisania ze strumienia
	bool  operator!=(CString & o); // operator porównania( ró¿ny od ), porównuj¹cy dwa ³¹ñcuchy znakowe
	bool operator==(const char * o); // operator porównania (jest równy ), porównuj¹cy ³añuch znakowy oraz tablicê znaków
	char * get(); // metoda zwracaj¹ca wskaŸnik na dynamiczn¹ tablicê znaków klasy CString
	bool sprawdz_czy_same_cyfry(); // metoda sprawdzaj¹ca czy zawartoœæ tablicy atrybutu data, jest cyfr¹
	bool sprawdz_czy_data(); //metoda sprawdzaj¹ca czy zawartoœæ tablicy atrybutu ma format daty

};
ostream & operator<<(ostream &s, const CString & str); // operator wypisania do strumienia
istream & operator>>(istream & IS, CString & S); //operator wpisania ze strumienia
bool operator==(const CString & str1, const CString & str2); // operator porównuj¹cy dwa ³añuchy znaków
CString operator+(const CString & str1, const CString & str2); // operator dodaj¹cy do jedengo ³añcucha znaków drugi ³añcuch znaków

#endif // !FUNKCJE_H
