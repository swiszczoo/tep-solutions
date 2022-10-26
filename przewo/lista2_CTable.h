#pragma once
#include <string>

class CTable_z2 {
public:
    CTable_z2();
    CTable_z2(const std::string& sName, int iTableLen);
    CTable_z2(const CTable_z2& other);
    ~CTable_z2();

    void vSetName(const std::string& sName);
    int iGetSize() const;
    const std::string& sGetName() const;
    void vSetValueAt(int offset, int newVal);
    void vPrint();
    bool bSetNewSize(int iTableLen);
    CTable_z2* pcClone() const;

    CTable_z2 operator+(const CTable_z2& other);

private:
    static const char DEFAULT_TABLE_NAME[];
    static const int DEFAULT_TABLE_SIZE;
    static const char COPY_SUFFIX[];

    std::string s_name;
    int* p_array;
    int i_size;
};
