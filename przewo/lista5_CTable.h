#pragma once
#include <string>
#include <type_traits>

#define DEFAULT_TABLE_NAME "DomyslnaTablica"
#define DEFAULT_TABLE_SIZE 10
#define COPY_SUFFIX "_copy"

template <bool useMoveSemantics>
class CTable_z5 {
public:
    CTable_z5();
    CTable_z5(const std::string& sName, int iTableLen);
    CTable_z5(const CTable_z5& other);
    CTable_z5(CTable_z5&& other);
    ~CTable_z5();

    void vSetName(const std::string& sName);
    int iGetSize() const;
    const std::string& sGetName() const;
    void vSetValueAt(int offset, int newVal);
    int iGetValueAt(int offset) const;
    void vPrint();
    bool bSetNewSize(int iTableLen);
    CTable_z5* pcClone() const;

    CTable_z5 operator+(const CTable_z5& other);
    CTable_z5& operator=(const CTable_z5& other);

private:
    std::string s_name;
    int* p_array;
    int i_size;

    void vCopyDataFrom(const CTable_z5& other);
};
