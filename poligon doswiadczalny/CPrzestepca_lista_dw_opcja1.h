#ifndef CPRZESTEPCA_LISTA_DW_OPCJA1_H
#define CPRZESTEPCA_LISTA_DW_OPCJA1_H

class CPrzestepca_lista_dw //Klasa przechowuj�ca informacje atrybutach listy dwukierunkowej przestepc�w
{
protected:
	CPrzestepca_elem * head, *tail; // wska�nki na g�ow� oraz ogon listy przestepc�w
public:
	CPrzestepca_lista_dw(); //konstruktor bezargumentowy
	~CPrzestepca_lista_dw(); //destruktor
	virtual void dodaj_przestepce(const CPrzestepca & nowy_przestepca,CRysopis & rysopis); //metoda dodaj�ca przest�pce do listy
	void dodaj_przestepstwo(const CPrzestepstwa & nowe_przestepstwo);//metoda dodaj�ca przestp�pstwo do listy 
	void wypisz_strumien_najlepiej_dopasowani(ostream & strumien, const CRysopis & o); //metoda wypisuj�ca do strumienia najlepiej dopasowanych przest�pc�w
	void wypisz_strumien_rysopis(ostream & strumien, CString & szukany); //metoda wypisuj�ca do strumienia rysopis przest�pcy znaleziony na podstawie nr pesel
	void wypisz_do_pliku_najlepiej_dopasowani(CString nazwa_pliku_wyj, const CRysopis & rys);//metoda wypisuj�ca do pliku najlepiej dopasowanych przestp�pc�w na podstawie rysopisu
	void wypisz_do_pliku_rysopis(CString nazwa_pliku_wyj, CString nr_pesel_szuk);//metoda wypisuj�ca do pliku rysopis przest�pcy znaleziony na podstawie numeru pesel
	void wczytaj_liste_przestepcow(CString nazwa_pliku_wej, CRysopis & rys); //metoda wczytuj�ca z pliku list� przest�pc�w 
	void wczytaj_liste_przestepstw(CString nazwa_pliku_wej); //metoda wczytuj�ca z pliku list� przest�pstw
};


#endif