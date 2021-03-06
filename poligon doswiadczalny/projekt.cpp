
#include "pch.h"
#include <iostream>
#include <CString>
#include <fstream>

using namespace std;


class CString
{

protected:
	char * data;
	unsigned int size;

public:
	CString();
	CString(const char * str);
	CString(const CString &str);
	~CString();


	bool compare(const CString & str) const;
	unsigned int getLength() const;
	void setLength(unsigned int size);
	void add(const CString & text);
	CString & operator=(const CString & str);
	friend ostream & operator<<(ostream &s, const CString & str);
	friend istream & operator>>(istream & IS, CString & S);
	bool  operator!=(CString & o)
	{
		if (strcmp(data, o.data) != 0) return true; else return false;
	}
	char * get()
	{
		return data;
	}
		
	

};
bool operator==(const CString & str1, const CString & str2);
CString operator+(const CString & str1, const CString & str2);

CString::CString() :size(strlen(""))
{
	data = new char[size + 1];
	strcpy_s(data, size + 1, "");
}
CString::CString(const char * str) : size(strlen(str))
{
	data = new char[size + 1];
	strcpy_s(data, size + 1, str);
}
CString::CString(const CString &str) {
	size = str.size;
	data = new char[str.size + 1];
	strcpy_s(data, size + 1, str.data);
}
CString::~CString()
{
	if (data)
	{
		delete[] data;
		data = nullptr;
		size = 0;
		//std::cout << "Zwolnij CString";
	}
}
std::ostream & operator<<(std::ostream &s, const  CString & str)
{
	return s << str.data;
}
bool CString::compare(const CString & str) const
{
	return strcmp(data, str.data) == 0;
}
unsigned int CString::getLength() const {
	return strlen(this->data);
}
void CString::setLength(unsigned int size)
{
	unsigned int old_length = strlen(data);
	char* old_data = this->data;
	this->size = size;
	this->data = new char[size + 1];
	for (int i = 0; i < size; i++) {
		if (i < old_length) {
			this->data[i] = old_data[i];
		}
		else {
			this->data[i] = '\0';
		}
	}
	delete[] old_data;
	this->data[size] = '\0';
}
void CString::add(const CString & text) {
	unsigned int new_size = this->size + text.size;
	setLength(new_size);

	size_t length = this->getLength();
	for (size_t i = length; i < new_size; i++) {
		this->data[i] = text.data[i - length];
	}
}
CString & CString::operator=(const CString & str)
{
	if (this == &str) return *this;
	{
		if (data) delete[] data;
		data = new char[strlen(str.data) + 1];
		strcpy_s(data, strlen(str.data) + 1, str.data);
		size = str.size;
	}
}
istream & operator>>(istream & is, CString & S)
{
	//char* input = new char[300];

	////IS.getline(input, 300);
	//IS.getline(input, 300,'/');
	//
	//int i = 0;
	//int j = 0;
	//while (input[i] !='\0')
	//{
	//	i++;
	//}
	//while (input[j] != '\0')
	//{
	//	
	//	if (input[j] == '\n') input[j] = ' ';
	//	j++;
	char* c = new char[1000];
	is >> c;
	S = CString(c);
	delete[] c;

	return is;

	//S.size = i + 1;
	//delete[]S.data;
	//S.data = new char[(i + 1)];
	//for (int j = 0; j < (i); j++)
	//{
	//	S.data[j] = input[j];
	//}
	//S.data[i] = '\0';
	//delete[]input;
	//return IS;
}


bool operator==(const CString & str1, const CString & str2)
{
	return str1.compare(str2);
}
CString operator+(const CString & str1, const CString & str2)
{
	CString str = CString(str1);
	str.add(str2);
	return str;
}


class CNr_pesel;
class CRysopis;
struct CPrzestepstwa_elem;
class CPrzestepstwa;
struct CPrzestepca_elem;
class CPrzestepca;
class CPrzestepca_lista_dw;

class CNr_pesel
{
protected:
	CString nr_pesel;
public:
	CNr_pesel() {}
	CNr_pesel(CString nr_pesel):
		nr_pesel(nr_pesel) {}
	CNr_pesel(const CNr_pesel & o)
		:nr_pesel(o.nr_pesel) {}
	~CNr_pesel(){}
	friend ostream & operator<<(ostream & os, const CNr_pesel & o)
	{
		return os << "Nr pesel: " << o.nr_pesel;
	}
	friend istream & operator>>(istream & is, CNr_pesel & o)
	{
		return is >> o.nr_pesel;
	}
	bool operator==(const CNr_pesel & o)
	{
		return nr_pesel == o.nr_pesel;
	}
	CString get_nr_pesel()
	{
		return nr_pesel;////////////////////////////////////////////////////////////
	}
};

class CRysopis 
{
protected:
	CString plec;
	CString rok_ur;
	CString wzrost;
	CString waga;
	CString kolor_o;
	CString kolor_w;
	CString dlugosc_w;
	CString narodowosc;
	CString posiad_okul;
	CString miejsce_znamie;
public:
	CRysopis() {}
	CRysopis(CString plec,CString rok_ur,CString wzrost,CString waga,CString kolor_o,CString kolor_w,CString dlugosc_w,CString narodowosc,CString posiad_okul,CString miejsce_zam)
		:plec(plec),rok_ur(rok_ur),wzrost(wzrost),waga(waga),kolor_o(kolor_o),kolor_w(kolor_w),dlugosc_w(dlugosc_w),narodowosc(narodowosc),posiad_okul(posiad_okul),miejsce_znamie(miejsce_zam)
	{}
	CRysopis(const CRysopis & o) 
		:plec(o.plec), rok_ur(o.rok_ur), wzrost(o.wzrost), waga(o.waga), kolor_o(o.kolor_o), kolor_w(o.kolor_w), dlugosc_w(o.dlugosc_w),
		narodowosc(o.narodowosc), posiad_okul(o.posiad_okul), miejsce_znamie(o.miejsce_znamie) {}
	friend istream & operator>>(istream & is, CRysopis & o)
	{
		return is >> o.plec >> o.rok_ur >> o.wzrost >> o.waga >> o.kolor_o >> o.kolor_w >> o.dlugosc_w >> o.narodowosc >> o.posiad_okul >> o.miejsce_znamie;
	}
	friend ostream & operator<<(ostream & os, const CRysopis & o)
	{
		return os << "Plec: " << o.plec <<endl<< "Roku urodzenia: " << o.rok_ur << endl << "Wzrost: " << o.wzrost << endl << "Waga: " << o.waga << endl << "Kolor oczu: " << o.kolor_o << endl << "Kolor wlosow: " << 
			o.kolor_w << endl <<"Dlugosc wlosow: "<< o.dlugosc_w << endl <<"Narodowosc: "<< o.narodowosc << endl <<"Posiadanie okularow: "<< o.posiad_okul << endl <<"Miejsce znamienia: "<< o.miejsce_znamie << endl;
	}	
	friend int zliczanie_wag(const CRysopis & r,CPrzestepca& p);
	void wczytaj_rysopis_z_pliku(CString nazwa_pliku_wej)
	{
		fstream file(nazwa_pliku_wej.get(), ios::in);
		CString wczytane[3];
		if (file)
		{
			
			file >> *this;
		}
		file.close();
	}

};


class CPrzestepstwa :public CNr_pesel
{
private:
	CString data;
	CString rodzaj;
public:
	CPrzestepstwa() {}
	CPrzestepstwa(CString nr_pesel, CString data, CString rodzaj)
		:CNr_pesel(nr_pesel), data(data), rodzaj(rodzaj) {}
	CPrzestepstwa(const CPrzestepstwa & o)
		:CNr_pesel(o), data(o.data), rodzaj(o.rodzaj) {}
	friend ostream & operator<<(ostream & os, const CPrzestepstwa & o)
	{
		return os << *dynamic_cast<const CNr_pesel*>(&o) << " Data przstepstwa: " << o.data << " Rodzaj przestepstwa :" << o.rodzaj << endl;
	}
	friend istream & operator >>(istream & is, CPrzestepstwa & o)
	{
		return is >> *dynamic_cast<CNr_pesel*>(&o) >> o.data >> o.rodzaj;
	}

};

struct CPrzestepstwa_elem
{
	CPrzestepstwa nowe_przestepstwo;
	CPrzestepstwa_elem * next;
	CPrzestepstwa_elem(const CPrzestepstwa & o) : nowe_przestepstwo(o), next(nullptr) {}
};

class CPrzestepca: public CRysopis,public CNr_pesel
{
private:
	static int wagi[10];
		int punkty;
		bool cechy[10];
public:
	CPrzestepca() {}
	CPrzestepca(CString nr_pesel,CString plec, CString rok_ur, CString wzrost, CString waga, CString kolor_o, CString kolor_w, CString dlugosc_w, CString narodowosc, CString posiad_okul, CString miejsce_zam)
		:CRysopis(plec,rok_ur,wzrost,waga,kolor_o,kolor_w,dlugosc_w,narodowosc, posiad_okul, miejsce_zam),CNr_pesel(nr_pesel),punkty(0)
	{
		for (int i = 0; i < 10; i++)
		{
			cechy[i] = false;
		}
	}
	CPrzestepca(const CPrzestepca & o): CRysopis(o),CNr_pesel(o),punkty(o.punkty)
	{
		for (int i = 0; i < 10; i++)
		{
			cechy[i] = o.cechy[i];
		}
	}
	friend ostream & operator<<(ostream & os, const CPrzestepca & o)
	{
	os << *dynamic_cast<const CNr_pesel*>(&o) <<endl<< *dynamic_cast<const CRysopis*>(&o);
		return os;
	}
	friend istream & operator >>(istream & is, CPrzestepca & o)
	{
		return is >> *dynamic_cast<CNr_pesel*>(&o) >> *dynamic_cast<CRysopis*>(&o);
	}
	ostream & wypisz_przestepce(ostream & strumien)
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
	void operator+=(int liczba)
	{
		punkty = liczba;
	}
	friend int zliczanie_wag(const CRysopis & r, CPrzestepca& p);
	bool sprawdz_czy_to_liczba()
	{
		
	}


};

int CPrzestepca::wagi[10] = { 1,2,3,4,5,6,7,8,9,10};

int zliczanie_wag(const CRysopis & r, CPrzestepca & p)
{
	int suma = 0;
	if (r.plec == p.plec)
	{
		suma += CPrzestepca::wagi[0];
		p.cechy[0] = true;
	}
	else p.cechy[0] = false;
	if (r.rok_ur == p.rok_ur)
	{
		suma += CPrzestepca::wagi[1];
		p.cechy[1] = true;
	}
	else p.cechy[1] = false;
	if (r.wzrost == p.wzrost)
	{
		suma += CPrzestepca::wagi[2];
		p.cechy[2] = true;
	}
	else p.cechy[2] = false;
	if (r.waga == p.waga)
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

struct CPrzestepca_elem
{
	CPrzestepca nowy_przestepca;
	CPrzestepca_elem * next;
	CPrzestepca_elem * prev;
	CPrzestepstwa_elem * head_CPrzestepstwa;
	CPrzestepca_elem(const CPrzestepca & o):nowy_przestepca(o),next(nullptr),prev(nullptr),head_CPrzestepstwa(nullptr){}
};

class CPrzestepca_lista_dw
{
private:
	CPrzestepca_elem * head, *tail;
public:
	CPrzestepca_lista_dw()
		:head(nullptr),tail(nullptr) {}
	void dodaj_przestepce(const CPrzestepca & nowy_przestepca, const CRysopis & rysopis)
	{
		int kopia_wagi = 0;
		CPrzestepca_elem * p = new CPrzestepca_elem(nowy_przestepca);
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
	void dodaj_przestepstwo(const CPrzestepstwa & nowe_przestepstwo)
	{
		CPrzestepstwa_elem * nowy = new CPrzestepstwa_elem(nowe_przestepstwo);
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
	void wypisz_strumien_najlepiej_dopasowani(ostream & strumien, const CRysopis & o)
	{
		CPrzestepca_elem * kopia = head;
		int i = 0;
		while (kopia && i < 5)
		{
			strumien << "Miejce nr: " << i+1<< endl;
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
	void wypisz_strumien_rysopis(ostream & strumien, CString & szukany)
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
	void wypisz_do_pliku_najlepiej_dopasowani(CString nazwa_pliku_wyj,const CRysopis & rys)
	{
		fstream file(nazwa_pliku_wyj.get(), ios::out);
		if (file)
		{
			this->wypisz_strumien_najlepiej_dopasowani(file,rys);
			//this->wypisz_elefekty(file, rys);
		}
		file.close();
	}
	void wypisz_do_pliku_rysopis(CString nazwa_pliku_wyj,CString nr_pesel_szuk)
	{
		fstream file(nazwa_pliku_wyj.get(), ios::out);
		if (file)
		{
			this->wypisz_strumien_rysopis(file, nr_pesel_szuk);
			//this->wypisz_elefekty(file, rys);
		}
		file.close();
	}
	void wczytaj_liste_przestepcow(CString nazwa_pliku_wej,const  CRysopis & rys)
	{
		fstream file(nazwa_pliku_wej.get(), ios::in);
		if (file)
		{
			CPrzestepca p;
			while (file >> p) this->dodaj_przestepce(p, rys);
		}
		file.close();
	}
	void wczytaj_liste_przestepstw(CString nazwa_pliku_wej)
	{
		fstream file(nazwa_pliku_wej.get(), ios::in);
		if (file)
		{
			CPrzestepstwa p;
			while (file >> p) this->dodaj_przestepstwo(p);
		}
		file.close();
	}
};

int sprawdz_wejscie_opcja2(char * param1 ,char * param2)
{
	int suma = 1;
	fstream file(param1, ios::in);
	if (!file) suma = 0;
	file.close();
	fstream file1(param2, ios::in);
	if (!file1) suma = 0;
	file.close();
	return suma;
}

int sprawdz_wejscie_opcja1(char * param1, char * param2,char * param3)
{
	int suma = 1;
	fstream file(param1, ios::in);
	if (!file) suma = 0;
	file.close();
	fstream file1(param2, ios::in);
	if (!file1) suma = 0;
	file.close();
	fstream file2(param3, ios::in);
	if (!file1) suma = 0;
	file.close();
	return suma;
}


int main(int argc, char * argv[])
{
	if (argc == 9 && !strcmp(argv[1], "-inPer") && !strcmp(argv[3], "-inCri") && !strcmp(argv[7], "-out"))
	{
		if (!strcmp(argv[5], "-q") && sprawdz_wejscie_opcja1(argv[2], argv[4],argv[6]))
		{
			CRysopis r1;
			CPrzestepca_lista_dw l1;
			r1.wczytaj_rysopis_z_pliku(argv[6]);
			l1.wczytaj_liste_przestepcow(argv[2], r1);
			l1.wczytaj_liste_przestepstw(argv[4]);
			l1.wypisz_do_pliku_najlepiej_dopasowani(argv[8], r1);
			cout << "Wybrano opcje 1";
		}
		else if (!strcmp(argv[5], "-id")&& sprawdz_wejscie_opcja2(argv[2],argv[4]))
		{
			CRysopis r1;
			CPrzestepca_lista_dw l1;
			l1.wczytaj_liste_przestepcow(argv[2], r1);
			l1.wczytaj_liste_przestepstw(argv[4]);
			l1.wypisz_do_pliku_rysopis(argv[8], argv[6]);
			cout << "Wybrano opcje 2";
		}	
	}else 
	cout << "Blad odczuty parametrow!";
}

	
/*


	//CPrzestepca_lista_dw nowa_lista;
	//CPrzestepstwa p1("98060203413", "12.03.2019", "Pobicie");
	//CPrzestepca pp1("98060203413", "mezyczyzna", "19y98", "1y80", "80", "niebieskie", "brunet", "srednia", "Polska", "Nie", "Brzuch");
//	CRysopis r1("mezczyzna", "1998", "180", "80", "niebieskie", "brunet", "srednia", "Polska", "Nie", "Brzuch");

	//nowa_lista.wczytaj_liste_przestepcow("przestepcy.txt",)
	//nowa_lista.dodaj_przestepce(pp1, r1);

	//nowa_lista.wypisz_do_pliku(cout, r1);
	//nowa_lista.wypisz_do_pliku_rysopis("wygen_rysop", "98060203413");
	//	cout<<zliczanie_wag(r1, pp1);
	//	cout << p1;
	//	cout << pp1;
	//	cout << r1;
	//}
	//OPCJA1:
	CRysopis r1; CPrzestepca_lista_dw l1;
	r1.wczytaj_rysopis_z_pliku("rysopis.txt");
	cout << r1 << endl;
	l1.wczytaj_liste_przestepcow("przestepcy.txt", r1);
	//l1.dodaj_przestepce(pp1, r1);
	//l1.wypisz_strumien_najlepiej_dopasowani(cout, r1);
	//l1.wypisz_strumien_najlepiej_dopasowani(cout, r1);


	l1.wczytaj_liste_przestepstw("przestepstwa.txt");
	l1.wypisz_do_pliku_najlepiej_dopasowani("najlepiej-dopasowani.txt", r1);
	//l1.wypisz_do_pliku_rysopis("ryyysopis.txt", "54060375839");
	return 0;*/
