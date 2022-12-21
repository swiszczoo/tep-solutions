#include "lista5_CTable.h"

#include <algorithm>
#include <iostream>
#include <utility>

using namespace std;

template <bool useMoveSemantics>
CTable_z5<useMoveSemantics>::CTable_z5()
{
    s_name = DEFAULT_TABLE_NAME;
    p_array = new int[DEFAULT_TABLE_SIZE];
    i_size = DEFAULT_TABLE_SIZE;

    std::cout << "konstr domyslny" << std::endl;
}

template <bool useMoveSemantics>
CTable_z5<useMoveSemantics>::CTable_z5(const std::string& sName, int iTableLen)
{
    s_name = sName;
    p_array = new int[iTableLen];
    i_size = iTableLen;

    std::cout << "konstr parametryczny" << std::endl;
}

template <bool useMoveSemantics>
CTable_z5<useMoveSemantics>::CTable_z5(const CTable_z5& pcOther)
{
    vCopyDataFrom(pcOther);
    std::cout << "konstr kopiujacy" << std::endl;
}

template <>
CTable_z5<false>::CTable_z5(CTable_z5&& pcOther)
{
    vCopyDataFrom(pcOther);
    std::cout << "konstr kopiujacy (uruchomiony zostal przenoszacy)" << std::endl;
}

template <>
CTable_z5<true>::CTable_z5(CTable_z5&& pcOther)
{
    i_size = pcOther.i_size;
    s_name = std::move(pcOther.s_name);
    p_array = pcOther.p_array;

    pcOther.i_size = 0;
    pcOther.p_array = NULL;

    std::cout << "konstr przenoszacy" << std::endl;
}

template <bool useMoveSemantics>
CTable_z5<useMoveSemantics>::~CTable_z5()
{
    if (p_array != NULL) {
        delete[] p_array;
    }

    std::cout << "destruktor" << std::endl;
}

template <bool useMoveSemantics>
void CTable_z5<useMoveSemantics>::vSetName(const std::string& newName)
{
    s_name = newName;
}

template <bool useMoveSemantics>
const std::string& CTable_z5<useMoveSemantics>::sGetName() const
{
    return s_name;
}

template <bool useMoveSemantics>
int CTable_z5<useMoveSemantics>::iGetSize() const
{
    return i_size;
}

template <bool useMoveSemantics>
void CTable_z5<useMoveSemantics>::vSetValueAt(int offset, int value)
{
    if (offset < i_size && offset >= 0) {
        p_array[offset] = value;
    }
}

template <bool useMoveSemantics>
int CTable_z5<useMoveSemantics>::iGetValueAt(int offset) const
{
    if (offset < i_size && offset >= 0) {
        return p_array[offset];
    }

    return 0;
}

template <bool useMoveSemantics>
void CTable_z5<useMoveSemantics>::vPrint()
{
    for (int i = 0; i < i_size; i++) {
        cout << p_array[i] << endl;
    }
}

template <bool useMoveSemantics>
bool CTable_z5<useMoveSemantics>::bSetNewSize(int iTableLen)
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

template <bool useMoveSemantics>
CTable_z5<useMoveSemantics>* CTable_z5<useMoveSemantics>::pcClone() const
{
    return new CTable_z5(*this);
}

template <>
CTable_z5<false> CTable_z5<false>::operator+(const CTable_z5& other)
{
    CTable_z5 result(s_name + '+' + other.s_name, i_size + other.i_size);

    if (other.i_size < -1234) {
        // niemozliwy warunek, ale wylaczy optymalizacje copy elision
        return CTable_z5();
    }

    for (int i = 0; i < i_size; i++) {
        result.p_array[i] = p_array[i];
    }
    for (int j = 0; j < other.i_size; j++) {
        result.p_array[i_size + j] = other.p_array[j];
    }

    return result;
}

template <>
CTable_z5<true> CTable_z5<true>::operator+(const CTable_z5& other)
{
    CTable_z5 result(s_name + '+' + other.s_name, i_size + other.i_size);

    for (int i = 0; i < i_size; i++) {
        result.p_array[i] = p_array[i];
    }
    for (int j = 0; j < other.i_size; j++) {
        result.p_array[i_size + j] = other.p_array[j];
    }

    return std::move(result);
}

template <bool useMoveSemantics>
CTable_z5<useMoveSemantics>& CTable_z5<useMoveSemantics>::operator=(const CTable_z5& other)
{
    delete[] p_array;

    vCopyDataFrom(other);
    return *this;
}

template <bool useMoveSemantics>
void CTable_z5<useMoveSemantics>::vCopyDataFrom(const CTable_z5& other)
{
    s_name = other.s_name;
    p_array = new int[other.i_size];
    i_size = other.i_size;

    for (int i = 0; i < other.i_size; i++) {
        p_array[i] = other.p_array[i];
    }
}

template class CTable_z5 <false>;
template class CTable_z5 <true>;
