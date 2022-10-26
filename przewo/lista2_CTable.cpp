#include "lista2_CTable.h"

#include <iostream>

const char CTable_z2::DEFAULT_TABLE_NAME[] = "DomyslnaTablica";
const int CTable_z2::DEFAULT_TABLE_SIZE = 10;
const char CTable_z2::COPY_SUFFIX[] = "_copy";

using namespace std;

CTable_z2::CTable_z2()
{
    s_name = DEFAULT_TABLE_NAME;
    p_array = new int[DEFAULT_TABLE_SIZE];
    i_size = DEFAULT_TABLE_SIZE;

    cout << "bezp: '" << s_name << "'" << endl;
}

CTable_z2::CTable_z2(const std::string& sName, int iTableLen)
{
    s_name = sName;
    p_array = new int[iTableLen];
    i_size = iTableLen;

    cout << "parametr: '" << s_name << "'" << endl;
}

CTable_z2::CTable_z2(const CTable_z2& pcOther)
{
    s_name = pcOther.s_name + "_copy";
    p_array = new int[pcOther.i_size];
    i_size = pcOther.i_size;

    for (int i = 0; i < pcOther.i_size; i++) {
        p_array[i] = pcOther.p_array[i];
    }

    cout << "kopiuj: '" << s_name << "'" << endl;
}

CTable_z2::~CTable_z2()
{
    cout << "usuwam: '" << s_name << "'" << endl;
    delete[] p_array;
}

void CTable_z2::vSetName(const std::string& newName)
{
    s_name = newName;
}

const std::string& CTable_z2::sGetName() const
{
    return s_name;
}

int CTable_z2::iGetSize() const
{
    return i_size;
}

void CTable_z2::vSetValueAt(int offset, int value)
{
    if (offset < i_size) {
        p_array[offset] = value;
    }
}

void CTable_z2::vPrint()
{
    for (int i = 0; i < i_size; i++) {
        cout << p_array[i] << endl;
    }
}

bool CTable_z2::bSetNewSize(int iTableLen)
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
    i_size = iTableLen;

    return true;
}

CTable_z2* CTable_z2::pcClone() const
{
    return new CTable_z2(*this);
}

CTable_z2 CTable_z2::operator+(const CTable_z2& other)
{
    CTable_z2 result(s_name + '+' + other.s_name, i_size + other.i_size);

    for (int i = 0; i < i_size; i++) {
        result.p_array[i] = p_array[i];
    }
    for (int j = 0; j < other.i_size; j++) {
        result.p_array[i_size + j] = other.p_array[j];
    }

    return result;
}
