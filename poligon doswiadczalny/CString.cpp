#include "pch.h" //zawsze na gore!!

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
	}
}
bool CString::compare(const CString & str) const
{
	return strcmp(data, str.data) == 0;
}
char * CString::get()
{
	return data;
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
ostream & operator<<(std::ostream &s, const  CString & str)
{
	return s << str.data;
}
istream & operator>>(istream & is, CString & S)
{
	char* c = new char[1000];
	is >> c;
	S = CString(c);
	delete[] c;
	return is;
}
bool  CString::operator!=(CString & o)
{
	if (strcmp(data, o.data) != 0) return true; else return false;
}
bool  CString::operator==(const char * o)
{
	if (strcmp(data, o) == 0) return true; else return false;
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
bool CString::sprawdz_czy_same_cyfry()
{
	for (int i = 0; i < size; i++)
	{
		if (!isdigit(data[i]))return false;
	}
	return true;
}
bool CString::sprawdz_czy_data()
{
	for (int i = 0; i < size; i++)
	{
		if (!isdigit(data[i]) && !(data[i] == '.')) return false;
	}
	return true;
}