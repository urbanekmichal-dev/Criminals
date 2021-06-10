#ifndef CNR_PESEL_H
#define CNR_PESEL_H

class CNr_pesel //Klasa przechowujaca informacje o nr pesel
{
protected:
	CString nr_pesel; //Klasa przechowujaca informacje ³añcucha nr_pesel
public:
	CNr_pesel();	//Konstruktor bezargumentowy 
	CNr_pesel(CString nr_pesel); //Konstruktor argumentowy
	CNr_pesel(const CNr_pesel & o); //Konstruktor kopiuj¹cy
	~CNr_pesel(); //Destruktor
	friend ostream & operator<<(ostream & os, const CNr_pesel & o); //deklarcja przyjazni operatora wypisania
	friend istream & operator>>(istream & is, CNr_pesel & o); //deklaracja przyjazni operatora wpisania
	bool operator==(const CNr_pesel & o); // operator porównujacy dwa numery pesel
	CString get_nr_pesel(); //operator 
};
ostream & operator<<(ostream & os, const CNr_pesel & o);//operator wypisania
istream & operator>>(istream & is, CNr_pesel & o); //operator wpisania
#endif 
