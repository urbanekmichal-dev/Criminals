#include "pch.h" //zawsze na gore!!

void CPrzestepcy_lista_dw2::dodaj_przestepce(const CPrzestepca & nowy_przestepca,  CRysopis & rysopis)
	{
		CPrzestepca_elem * p = new CPrzestepca_elem(nowy_przestepca);
		p->next = head;
		p->prev = nullptr;
		if (head != nullptr) head->prev = p;
		head = p;
	}
