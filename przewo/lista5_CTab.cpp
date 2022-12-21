#include "lista5_CTab.h"

#include <algorithm>
#include <iostream>
#include <utility>

CTab::CTab(const CTab& cOther)
{
    v_copy(cOther);
    std::cout << "Copy ";
}//CTab::CTab(const CTab &cOther)

CTab::~CTab()
{
    if (pi_tab != NULL) delete pi_tab;
    std::cout << "Destr ";
}//CTab::~CTab()

CTab::CTab(CTab&& cOther)
{
    pi_tab = cOther.pi_tab;
    i_size = cOther.i_size;
    cOther.pi_tab = NULL;
    std::cout << "MOVE ";
}//CTab::CTab(CTab &&cOther)

bool CTab::bSetSize(int iNewSize)
{
    if (iNewSize <= 0) 
        return false;

    int* temp = new int[iNewSize];
    int limit = std::min(iNewSize, i_size);

    for (int i = 0; i < limit; i++) {
        temp[i] = pi_tab[i];
    }

    delete[] pi_tab;
    pi_tab = temp;
    i_size = iNewSize;

    return true;
}

CTab& CTab::operator=(const CTab& cOther)
{
    if (pi_tab != NULL) delete pi_tab;
    v_copy(cOther);
    std::cout << "op= ";
    return(*this);
}//CTab CTab::operator=(const CTab &cOther)

CTab& CTab::operator=(CTab&& cOther)
{
    std::swap(i_size, cOther.i_size);
    std::swap(pi_tab, cOther.pi_tab);
    std::cout << "op= (MS) ";
    return(*this);
}

void CTab::v_copy(const CTab& cOther)
{
    pi_tab = new int[cOther.i_size];
    i_size = cOther.i_size;
    for (int ii = 0; ii < cOther.i_size; ii++)
        pi_tab[ii] = cOther.pi_tab[ii];
}//void CTab::v_copy(CTab &cOther)

