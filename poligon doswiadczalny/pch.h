#ifndef PCH_H
#define PCH_H

/*Plik nagłówkowy przechowujący polecenia dołączenia wszystkich 
nagłówków potrzebnych do poprawnej pracy programu */

#include "vld.h"
#include <fstream>
#include <iostream>
#include "CString.h"
#include "CNr_pesel.h"
#include "CPrzestepstwa.h"
#include "CRysopis.h"
#include "CPrzestepca.h"
#include "CPrzestepca_lista_dw_opcja1.h"
#include "CPrzestepca_lista_dw_opcja2.h"

bool sprawdz_plik_wejsciowy(CString nazwa);// funkcja testująca pliki wejściowe

bool sprawdz_plik_wyjsciowy(CString nazwa);//funkcja testująca pliki wyjściowe

bool sprawdz_wejscie_opcja2(CString  param1, CString param2, CString param3_pesel);
// funkcja sprawdzająca istnienie oraz poprawność nazw plików, dla pracy programu w trybie wypisu pliku rysopisu

bool sprawdz_wejscie_opcja1(CString param1, CString param2, CString param3, CString param4_out);
// funkcja sprawdzająca istnienie oraz poprawność nazw plików, dla pracy programu w trybie wypisu pliku najlepiej dopasowanych przestepców


#endif 