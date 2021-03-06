#include "pch.h" 

using namespace std;

bool sprawdz_plik_wejsciowy(CString nazwa)
{
	fstream file(nazwa.get(), ios::in);
	if (!file)
	{
		cout << "Bład pliku o nazwie" << nazwa;
		return false;
	}
	file.close();
}
bool sprawdz_plik_wyjsciowy(CString nazwa)
{
	fstream file(nazwa.get(), ios::out);
	if (!file)
	{
		cout << "Bład pliku o nazwie" << nazwa;
		return false;
	}
	file.close();
}
bool sprawdz_wejscie_opcja2(CString  param1 , CString param2, CString param3_pesel)
{
	if (sprawdz_plik_wejsciowy(param1) && sprawdz_plik_wejsciowy(param2) &&
		param3_pesel.sprawdz_czy_same_cyfry())
		return true;
	else return false;
}
bool sprawdz_wejscie_opcja1(CString param1, CString param2, CString param3, CString param4_out)
{

	if(sprawdz_plik_wejsciowy(param1)&& sprawdz_plik_wejsciowy(param2) && sprawdz_plik_wejsciowy(param3) && sprawdz_plik_wyjsciowy(param4_out))
	return true;
	else return false;
}


int main(int argc, char * argv[])
{
	if (argc == 9)
	{
		int opcja = 0;
		CString n_plik_przestepcow, n_plik_przestepstw, n_plik_wyjsciowy, n_plik_rysopis, nr_pesel_we;
		for (auto i : { 1,3,5,7 })
		{
			if (!strcmp(argv[i], "-inPer")) n_plik_przestepcow = argv[i + 1];
			if (!strcmp(argv[i], "-inCri")) n_plik_przestepstw = argv[i + 1];
			if (!strcmp(argv[i], "-out")) n_plik_wyjsciowy = argv[i + 1];
			if (!strcmp(argv[i], "-q"))
			{
				n_plik_rysopis = argv[i + 1];
				opcja = 1;
			}
			else if (!strcmp(argv[i], "-id"))
			{
				nr_pesel_we = argv[i + 1];
				opcja = 2;
			}
		}
		if (opcja == 1 && sprawdz_wejscie_opcja1(n_plik_przestepcow, n_plik_przestepstw, n_plik_rysopis, n_plik_wyjsciowy))
		{
			CRysopis r1;
			CPrzestepca_lista_dw l1;
			if (r1.wczytaj_rysopis_z_pliku(n_plik_rysopis))
			{
				l1.wczytaj_liste_przestepcow(n_plik_przestepcow, r1);
				l1.wczytaj_liste_przestepstw(n_plik_przestepstw);
				l1.wypisz_do_pliku_najlepiej_dopasowani(n_plik_wyjsciowy, r1);
				cout << "Wybrano opcje 1" << endl;
			}
			else cout << "Blad odczytu pliku rysopisu!";
		}
		else if (opcja == 2 && sprawdz_wejscie_opcja2(n_plik_przestepcow, n_plik_przestepstw, nr_pesel_we))
		{
			CRysopis r1;
			CPrzestepcy_lista_dw2 l1;
			l1.wczytaj_liste_przestepcow(n_plik_przestepcow, r1);
			l1.wczytaj_liste_przestepstw(n_plik_przestepstw);
			l1.wypisz_do_pliku_rysopis(n_plik_wyjsciowy, nr_pesel_we);
			cout << "Wybrano opcje 2" << endl;
		}
		else cout << "Blad odczuty parametrow!";
	}
}
