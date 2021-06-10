#ifndef CPRZESTEPCA_H
#define CPRZESTEPCA_H

class CPrzestepca : public CRysopis, public CNr_pesel //Kklasa przechowuj¹ca informacje o atrybutach przestepcy
{
private:
	static int wagi[10]; // statyczna tablica liczb ca³kowitych, przechowuj¹ca wagi odpowiadaj¹ce odpowiednim cechom rysopisu
	int punkty; // zmienna przechowuj¹ca sumê punktów otrzymanych za zgodnoœæ cech z rysopisem 
	bool cechy[10]; // tablica zmiennych boolowskich, zawieraj¹ca informacje o zgodnoœci cech 
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
	void operator+=(int liczba);//operator przypisania wartoœci liczba do atrybutu punkty
	friend int zliczanie_wag(CRysopis & r, CPrzestepca& p); // deklaracja przyjazni funkcji zliczanie wag
};
int zliczanie_wag(CRysopis & r, CPrzestepca& p); // funkcja obliczaj¹ca sumê punktów, otrzymywanych za zgodnoœæ cechy przestêpcy z cech¹ rysopisu

ostream & operator<<(ostream & os, const CPrzestepca & o); // operator wypisania do strumienia
istream & operator >>(istream & is, CPrzestepca & o); // operator wpisania do strumienia

struct CPrzestepca_elem // struktura przechowuj¹ca obiekt klasy CPrzestepca
{
	CPrzestepca nowy_przestepca; // obiekt klasy CPrzestepca, przechowuj¹cy informacje o atrybutach przestepcy
	CPrzestepca_elem * next; //wskaŸnik na element nastêpny 
	CPrzestepca_elem * prev; //wskaŸnik na element poprzedni
	CPrzestepstwa_elem * head_CPrzestepstwa; // wskaŸnik na pocz¹tek listy przestêpstw pope³nionych przez danego przestêpce
	CPrzestepca_elem(const CPrzestepca & o); // konstruktor kopiuj¹cy 
};

#endif