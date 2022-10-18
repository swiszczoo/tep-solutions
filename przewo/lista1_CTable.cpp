#include "lista1_CTable.h"

#include <iostream>

const char CTable::DEFAULT_TABLE_NAME[] = "DomyslnaTablica";
const int CTable::DEFAULT_TABLE_SIZE = 10;
const char CTable::COPY_SUFFIX[] = "_copy";

using namespace std;

CTable::CTable()
    : s_name(DEFAULT_TABLE_NAME)
    , p_array(new int[DEFAULT_TABLE_SIZE])
    , i_size(DEFAULT_TABLE_SIZE)
{
    cout << "bezp: '" << s_name << "'" << endl;
}

CTable::CTable(const std::string& sName, int iTableLen)
    : s_name(sName)
    , p_array(new int[iTableLen])
    , i_size(DEFAULT_TABLE_SIZE)
{
    cout << "parametr: '" << s_name << "'" << endl;
}

CTable::CTable(const CTable& pcOther)
{
    *this = *pcOther.pcClone();

    s_name += COPY_SUFFIX;

    cout << "kopiuj: '" << s_name << "'" << endl;
}

CTable::~CTable()
{
    cout << "usuwam: '" << s_name << "'" << endl;
    delete[] p_array;
}

void CTable::vSetName(const std::string& newName)
{
    s_name = newName;
}

bool CTable::bSetNewSize(int iTableLen)
{
    if (iTableLen <= 0) {
        return false;
    }

    int* newArr = new int[iTableLen];

    for (int i = 0; i < iTableLen && i < i_size; i++) {
        newArr[i] = p_array[i];
    }

    delete[] p_array;
    p_array = newArr;

    return true;
}

CTable* CTable::pcClone() const
{
    CTable* newInstance = new CTable(s_name, i_size);

    for (int i = 0; i < i_size; i++) {
        newInstance->p_array[i] = p_array[i];
    }

    return newInstance;
}
