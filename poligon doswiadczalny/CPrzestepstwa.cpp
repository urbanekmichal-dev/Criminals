#include "pch.h" //zawsze na gore!!


CPrzestepstwa::CPrzestepstwa() {}
CPrzestepstwa::~CPrzestepstwa() {}
CPrzestepstwa::CPrzestepstwa(CString nr_pesel, CString data, CString rodzaj)
		:CNr_pesel(nr_pesel), data(data), rodzaj(rodzaj) {}
CPrzestepstwa::CPrzestepstwa(const CPrzestepstwa & o)
		:CNr_pesel(o), data(o.data), rodzaj(o.rodzaj) {}
ostream & operator<<(ostream & os, const CPrzestepstwa & o)
{
	return os /*<< *dynamic_cast<const CNr_pesel*>(&o) */ << "Data przstepstwa: " << o.data << " Rodzaj przestepstwa :" << o.rodzaj << endl;
}
istream & operator >>(istream & is, CPrzestepstwa & o)
{
	return is >> *dynamic_cast<CNr_pesel*>(&o) >> o.data >> o.rodzaj;
}
bool isLeap(int year)
{
	return (((year % 4 == 0) &&
		(year % 100 != 0)) ||
		(year % 400 == 0));
}
bool sprawdz_date(int d, int m, int y)
{
	if (y > 2019 ||
		y < 1900)
		return false;
	if (m < 1 || m > 12)
		return false;
	if (d < 1 || d > 31)
		return false;

	if (m == 2)
	{
		if (isLeap(y))
			return (d <= 29);
		else
			return (d <= 28);
	}
	if (m == 4 || m == 6 ||
		m == 9 || m == 11)
		return (d <= 30);
}

bool CPrzestepstwa::sprawdz_wejscie()
{
	if (data.sprawdz_czy_data())
	{
		int suma = 0;
		int d, m, y;
		int str_lenght = data.getLength();
		int * arr = new int[str_lenght];
		for (int i = 0; i < str_lenght; i++) arr[i] = 0;
		int j = 0, i, sum = 0;
		for (i = 0; i < data.getLength(); i++) {
			if (data.get()[i] == '.') {
				j++;
			}
			else {
				arr[j] = arr[j] * 10 + (data.get()[i] - 48);
			}
		}
		d = arr[0];
		m = arr[1];
		y = arr[2];
		delete[]arr;

		if (sprawdz_date(d, m, y)) return true;
		else return false;
	}
	else return false;
}

CPrzestepstwa_elem::CPrzestepstwa_elem(const CPrzestepstwa & o) : nowe_przestepstwo(o), next(nullptr) {}
