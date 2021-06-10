#include "pch.h" //zawsze na gore!!

CRysopis::CRysopis() {}
CRysopis::~CRysopis() {}
CRysopis::CRysopis(CString plec, CString rok_ur, CString wzrost, CString waga, CString kolor_o, CString kolor_w, CString dlugosc_w, CString narodowosc, CString posiad_okul, CString miejsce_zam)
		:plec(plec), rok_ur(rok_ur), wzrost(wzrost), waga(waga), kolor_o(kolor_o), kolor_w(kolor_w), dlugosc_w(dlugosc_w), narodowosc(narodowosc), posiad_okul(posiad_okul), miejsce_znamie(miejsce_zam){}
CRysopis::CRysopis(const CRysopis & o)
		:plec(o.plec), rok_ur(o.rok_ur), wzrost(o.wzrost), waga(o.waga), kolor_o(o.kolor_o), kolor_w(o.kolor_w), dlugosc_w(o.dlugosc_w),
		narodowosc(o.narodowosc), posiad_okul(o.posiad_okul), miejsce_znamie(o.miejsce_znamie) {}
istream & operator>>(istream & is, CRysopis & o)
{
	return is >> o.plec >> o.rok_ur >> o.wzrost >> o.waga >> o.kolor_o >> o.kolor_w >> o.dlugosc_w >> o.narodowosc >> o.posiad_okul >> o.miejsce_znamie;
}
bool CRysopis::sprawdz_wejscie()
{
	int suma = 0;
	if (plec == "Kobieta" || plec == "Mezczyzna") suma += 1;
	else cout << "Problem z wartoscia plci" << endl;

	if (rok_ur.sprawdz_czy_same_cyfry())
	{
		int a = atoi(rok_ur.get());
		if (a > 1900 && a < 2019) suma += 1;
		else cout << "Problem z wartoscia roku urodzenia" << endl;
	}
	else cout << "Problem z wartoscia roku urodzenia" << endl;

	if (wzrost.sprawdz_czy_same_cyfry())
	{
		int a = atoi(wzrost.get());
		if (a > 100 && a < 250) suma += 1;
		else cout << "Problem z wartoscia wzrostu" << endl;
	}
	else cout << "Problem z wartoscia wzrostu" << endl;

	if (waga.sprawdz_czy_same_cyfry())
	{
		int a = atoi(waga.get());
		if (a > 30 && a < 200) suma += 1;
		else cout << "Problem z wartoscia wagi" << endl;
	}
	else cout << "Problem z wartoscia wagi" << endl;

	if (kolor_o == "Brazowe" || kolor_o == "Niebieskie" || kolor_o == "Czarne" || kolor_o == "Zielone" || kolor_o == "Szare")
	{
		suma += 1;
	}
	else cout << "Problem z wartoscia kolor oczu" << endl;

	if (kolor_w == "Blond" || kolor_w == "Rude" || kolor_w == "Brazowe" || kolor_w == "Czarne" || kolor_w == "Siwe")
		suma += 1;
	else cout << "Problem z wartoscia kolor wlosow" << endl;

	if (dlugosc_w == "Krotkie" || dlugosc_w == "Srednie" || dlugosc_w == "Dlugie")
		suma += 1;
	else cout << "Problem z wartoscia dlugosc wlosow" << endl;

	if (narodowosc == "Polska" || narodowosc == "Niemcy" || narodowosc == "Anglia" || narodowosc == "Rosja" ||
		narodowosc == "Chiny" || narodowosc == "Japonia" || narodowosc == "Francja" ||
		narodowosc == "Hiszpania" || narodowosc == "Wlochy")  suma += 1;
	else cout << "Problem z wartoscia narodowosci" << endl;

	if (posiad_okul == "Tak" || posiad_okul == "Nie") suma += 1;
	else cout << "Problem z wartoscia posiadania okularow" << endl;

	if (miejsce_znamie == "Brak" || miejsce_znamie == "Twarz" || miejsce_znamie == "Szyja" || miejsce_znamie == "Brzuch" || miejsce_znamie == "Reka" || miejsce_znamie == "Noga")
		suma += 1;
	else cout << "Problem z wartosicia znamienia" << endl;

	if (suma == 10) return true;
	else return false;
}
ostream & operator<<(ostream & os, const CRysopis & o)
{
return os << "Plec: " << o.plec << endl << "Roku urodzenia: " << o.rok_ur << endl << "Wzrost: " << o.wzrost << endl << "Waga: " << o.waga << endl << "Kolor oczu: " << o.kolor_o << endl << "Kolor wlosow: " <<
		o.kolor_w << endl << "Dlugosc wlosow: " << o.dlugosc_w << endl << "Narodowosc: " << o.narodowosc << endl << "Posiadanie okularow: " << o.posiad_okul << endl << "Miejsce znamienia: " << o.miejsce_znamie << endl;
}
bool CRysopis::wczytaj_rysopis_z_pliku(CString nazwa_pliku_wej)
{
	fstream file(nazwa_pliku_wej.get(), ios::in);
	CString wczytane[3];
	if (file)
	{
		file >> *this;
	}
	file.close();
	if (this->sprawdz_wejscie()) return true;
	else return false;


}

