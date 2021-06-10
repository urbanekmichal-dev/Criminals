#ifndef CPRZESTEPCA_LISTA_DW_OPCJA1_H
#define CPRZESTEPCA_LISTA_DW_OPCJA1_H

class CPrzestepca_lista_dw //Klasa przechowuj¹ca informacje atrybutach listy dwukierunkowej przestepców
{
protected:
	CPrzestepca_elem * head, *tail; // wskaŸnki na g³owê oraz ogon listy przestepców
public:
	CPrzestepca_lista_dw(); //konstruktor bezargumentowy
	~CPrzestepca_lista_dw(); //destruktor
	virtual void dodaj_przestepce(const CPrzestepca & nowy_przestepca,CRysopis & rysopis); //metoda dodaj¹ca przestêpce do listy
	void dodaj_przestepstwo(const CPrzestepstwa & nowe_przestepstwo);//metoda dodaj¹ca przestpêpstwo do listy 
	void wypisz_strumien_najlepiej_dopasowani(ostream & strumien, const CRysopis & o); //metoda wypisuj¹ca do strumienia najlepiej dopasowanych przestêpców
	void wypisz_strumien_rysopis(ostream & strumien, CString & szukany); //metoda wypisuj¹ca do strumienia rysopis przestêpcy znaleziony na podstawie nr pesel
	void wypisz_do_pliku_najlepiej_dopasowani(CString nazwa_pliku_wyj, const CRysopis & rys);//metoda wypisuj¹ca do pliku najlepiej dopasowanych przestpêpców na podstawie rysopisu
	void wypisz_do_pliku_rysopis(CString nazwa_pliku_wyj, CString nr_pesel_szuk);//metoda wypisuj¹ca do pliku rysopis przestêpcy znaleziony na podstawie numeru pesel
	void wczytaj_liste_przestepcow(CString nazwa_pliku_wej, CRysopis & rys); //metoda wczytuj¹ca z pliku listê przestêpców 
	void wczytaj_liste_przestepstw(CString nazwa_pliku_wej); //metoda wczytuj¹ca z pliku listê przestêpstw
};


#endif