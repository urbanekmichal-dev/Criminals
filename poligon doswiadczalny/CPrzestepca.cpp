#include "pch.h" 

CPrzestepca::CPrzestepca() {}
CPrzestepca::~CPrzestepca() {}
CPrzestepca::CPrzestepca(CString nr_pesel, CString plec, CString rok_ur, CString wzrost, CString waga, CString kolor_o, CString kolor_w, CString dlugosc_w, CString narodowosc, CString posiad_okul, CString miejsce_zam)
		:CRysopis(plec, rok_ur, wzrost, waga, kolor_o, kolor_w, dlugosc_w, narodowosc, posiad_okul, miejsce_zam), CNr_pesel(nr_pesel), punkty(0)
	{
		for (int i = 0; i < 10; i++)
		{
			cechy[i] = false;
		}
	}
CPrzestepca::CPrzestepca(const CPrzestepca & o) : CRysopis(o), CNr_pesel(o), punkty(o.punkty)
	{
		for (int i = 0; i < 10; i++)
		{
			cechy[i] = o.cechy[i];
		}
	}

ostream & operator<<(ostream & os, const CPrzestepca & o)
	{
		os << *dynamic_cast<const CNr_pesel*>(&o) << endl << *dynamic_cast<const CRysopis*>(&o);
		return os;
	}
istream & operator >>(istream & is, CPrzestepca & o)
{
	return is >> *dynamic_cast<CNr_pesel*>(&o) >> *dynamic_cast<CRysopis*>(&o);
}
ostream & CPrzestepca::wypisz_przestepce(ostream & strumien)
	{
		strumien << *dynamic_cast<const CNr_pesel*>(&*this) << endl;
		strumien << "Cechy zgodne: " << endl;
		if (cechy[0]) strumien << "Plec: " << plec << endl;
		if (cechy[1]) strumien << "Rok urodzenia : " << rok_ur << endl;
		if (cechy[2]) strumien << "Wzrost : " << wzrost << endl;
		if (cechy[3]) strumien << "Waga : " << waga << endl;
		if (cechy[4]) strumien << "Kolor oczu : " << kolor_o << endl;
		if (cechy[5]) strumien << "Kolor wlosow : " << kolor_w << endl;
		if (cechy[6]) strumien << "Dlugosc wlosow : " << dlugosc_w << endl;
		if (cechy[7]) strumien << "Narodowosc : " << narodowosc << endl;
		if (cechy[8]) strumien << "Okulary : " << posiad_okul << endl;
		if (cechy[9]) strumien << "Znamie : " << miejsce_znamie << endl;
		strumien << punkty;
		strumien << endl;
		return strumien;
	}
void CPrzestepca::operator+=(int liczba)
{
	punkty = liczba;
}

int zliczanie_wag(CRysopis & r, CPrzestepca & p)
{
	int rok_p = atoi(p.rok_ur.get());
	int wzrost_p = atoi(p.wzrost.get());
	int waga_p = atoi(p.waga.get());

	int rok_r = atoi(r.rok_ur.get());
	int wzrost_r = atoi(r.wzrost.get());
	int waga_r = atoi(r.waga.get());

	int suma = 0;
	if (r.plec == p.plec)
	{
		suma += CPrzestepca::wagi[0];
		p.cechy[0] = true;
	}
	else p.cechy[0] = false;
	if (abs(rok_p-rok_r)<5)
	{
		suma += CPrzestepca::wagi[1];
		p.cechy[1] = true;
	}
	else p.cechy[1] = false;
	if (abs(wzrost_p-wzrost_r)<10)
	{
		suma += CPrzestepca::wagi[2];
		p.cechy[2] = true;
	}
	else p.cechy[2] = false;
	if (abs(waga_p-waga_r)<10)
	{
		suma += CPrzestepca::wagi[3];
		p.cechy[3] = true;
	}
	else p.cechy[3] = false;
	if (r.kolor_o == p.kolor_o)
	{
		suma += CPrzestepca::wagi[4];
		p.cechy[4] = true;
	}
	else p.cechy[4] = false;
	if (r.kolor_w == p.kolor_w)
	{
		suma += CPrzestepca::wagi[5];
		p.cechy[5] = true;
	}
	else p.cechy[5] = false;
	if (r.dlugosc_w == p.dlugosc_w)
	{
		suma += CPrzestepca::wagi[6];
		p.cechy[6] = true;
	}
	else p.cechy[6] = false;
	if (r.narodowosc == p.narodowosc)
	{
		suma += CPrzestepca::wagi[7];
		p.cechy[7] = true;
	}
	else p.cechy[7] = false;
	if (r.posiad_okul == p.posiad_okul)
	{
		suma += CPrzestepca::wagi[8];
		p.cechy[8] = true;
	}
	else p.cechy[8] = false;
	if (r.miejsce_znamie == p.miejsce_znamie)
	{
		suma += CPrzestepca::wagi[9];
		p.cechy[9] = true;
	}
	else p.cechy[9] = false;
	return suma;
}

int CPrzestepca::wagi[10] = { 10,3,2,2,2,2,2,2,2,3 };

CPrzestepca_elem::CPrzestepca_elem(const CPrzestepca & o) 
	:nowy_przestepca(o), next(nullptr), prev(nullptr), head_CPrzestepstwa(nullptr) {}