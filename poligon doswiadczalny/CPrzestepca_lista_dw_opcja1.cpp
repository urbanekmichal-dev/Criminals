#include "pch.h" //zawsze na gore!!

CPrzestepca_lista_dw::CPrzestepca_lista_dw()
		:head(nullptr), tail(nullptr) {}
CPrzestepca_lista_dw::~CPrzestepca_lista_dw()
	{
		while (head)
		{
			CPrzestepca_elem * qep = head;
			while (qep->head_CPrzestepstwa)
			{
				CPrzestepstwa_elem * qep1 = qep->head_CPrzestepstwa;
				qep->head_CPrzestepstwa = qep->head_CPrzestepstwa->next;
				delete qep1;
			}
			head = head->next;
			delete qep;
		}
	}
void CPrzestepca_lista_dw::dodaj_przestepce(const CPrzestepca & nowy_przestepca, CRysopis & rysopis)
	{
		int kopia_wagi = 0;
		CPrzestepca_elem * p = new CPrzestepca_elem(nowy_przestepca);
		if (p->nowy_przestepca.sprawdz_wejscie())
		{
			kopia_wagi = zliczanie_wag(rysopis, p->nowy_przestepca);
			p->nowy_przestepca += kopia_wagi;
			if (!head)head = p;
			else if (zliczanie_wag(rysopis, head->nowy_przestepca) <= kopia_wagi)
			{
				p->next = head;
				p->next->prev = p;
				head = p;
			}
			else
			{
				CPrzestepca_elem * kopia = head;
				while (kopia->next != nullptr && zliczanie_wag(rysopis, kopia->next->nowy_przestepca) > kopia_wagi)
					kopia = kopia->next;
				p->next = kopia->next;
				if (kopia->next != nullptr)
					p->next->prev = p;
				kopia->next = p;
				p->prev = kopia;
			}
		}
		else delete p;
	}
void CPrzestepca_lista_dw::dodaj_przestepstwo(const CPrzestepstwa & nowe_przestepstwo)
	{
		CPrzestepstwa_elem * nowy = new CPrzestepstwa_elem(nowe_przestepstwo);
		if (nowy->nowe_przestepstwo.sprawdz_wejscie())
		{
			CPrzestepca_elem * kopia = head;
			while (kopia && !(kopia->nowy_przestepca.get_nr_pesel() == nowy->nowe_przestepstwo.get_nr_pesel()))
			{
				kopia = kopia->next;
			}
			if (kopia)
			{
				nowy->next = kopia->head_CPrzestepstwa;
				kopia->head_CPrzestepstwa = nowy;
			}
			else delete nowy;
		}
		else delete nowy;
	}
void CPrzestepca_lista_dw::wypisz_strumien_najlepiej_dopasowani(ostream & strumien, const CRysopis & o)
	{
		CPrzestepca_elem * kopia = head;
		int i = 0;
		while (kopia && i < 5)
		{
			strumien << "Miejce nr: " << i + 1 << endl;
			kopia->nowy_przestepca.wypisz_przestepce(strumien);
			CPrzestepstwa_elem * kopia2 = kopia->head_CPrzestepstwa;
			if (kopia2) strumien << "Lista popelnionych przestepstw: " << endl;
			while (kopia2)
			{
				strumien << kopia2->nowe_przestepstwo;
				kopia2 = kopia2->next;
			}
			strumien << endl;
			kopia = kopia->next;
			i++;
		}
	}
void CPrzestepca_lista_dw::wypisz_strumien_rysopis(ostream & strumien, CString & szukany)
	{
		CPrzestepca_elem * kopia = head;
		while (kopia && kopia->nowy_przestepca.get_nr_pesel() != szukany) kopia = kopia->next;
		if (kopia)
		{
			strumien << kopia->nowy_przestepca;
			CPrzestepstwa_elem * kopia2 = kopia->head_CPrzestepstwa;
			while (kopia2)
			{
				strumien << kopia2->nowe_przestepstwo;
				kopia2 = kopia2->next;
			}
			strumien << endl;
			kopia = kopia->next;
		}
	}
void CPrzestepca_lista_dw::wypisz_do_pliku_najlepiej_dopasowani(CString nazwa_pliku_wyj, const CRysopis & rys)
	{
		fstream file(nazwa_pliku_wyj.get(), ios::out);
		if (file)
		{
			this->wypisz_strumien_najlepiej_dopasowani(file, rys);
			//this->wypisz_elefekty(file, rys);
		}
		file.close();
	}
void CPrzestepca_lista_dw::wypisz_do_pliku_rysopis(CString nazwa_pliku_wyj, CString nr_pesel_szuk)
	{
		fstream file(nazwa_pliku_wyj.get(), ios::out);
		if (file)
		{
			this->wypisz_strumien_rysopis(file, nr_pesel_szuk);
			//this->wypisz_elefekty(file, rys);
		}
		file.close();
	}
void CPrzestepca_lista_dw::wczytaj_liste_przestepcow(CString nazwa_pliku_wej, CRysopis & rys)
	{
		fstream file(nazwa_pliku_wej.get(), ios::in);
		if (file)
		{
			CPrzestepca p;
			while (file >> p) this->dodaj_przestepce(p, rys);
		}
		file.close();
	}
void CPrzestepca_lista_dw::wczytaj_liste_przestepstw(CString nazwa_pliku_wej)
	{
		fstream file(nazwa_pliku_wej.get(), ios::in);
		if (file)
		{
			CPrzestepstwa p;
			while (file >> p) this->dodaj_przestepstwo(p);
		}
		file.close();
	}
