#include "pch.h"

CNr_pesel::CNr_pesel() {}
CNr_pesel::CNr_pesel(CString nr_pesel) 
	:nr_pesel(nr_pesel) {}
CNr_pesel::CNr_pesel(const CNr_pesel & o)
		:nr_pesel(o.nr_pesel) {}
CNr_pesel::~CNr_pesel() {}
ostream & operator<<(ostream & os, const CNr_pesel & o)
	{
		return os << "Nr pesel: " << o.nr_pesel;
	}
istream & operator>>(istream & is, CNr_pesel & o)
	{
		return is >> o.nr_pesel;
	}
bool CNr_pesel::operator==(const CNr_pesel & o)
	{
		return nr_pesel == o.nr_pesel;
	}
CString CNr_pesel::get_nr_pesel()
	{
		return nr_pesel;
	}