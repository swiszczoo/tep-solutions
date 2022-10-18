#pragma once
#include <string>

class CTable {
public:
    CTable();
    CTable(const std::string& sName, int iTableLen);
    CTable(CTable& other);
    ~CTable();

    void vSetName(const std::string& sName);
    bool bSetNewSize(int iTableLen);
    CTable* pcClone() const;

private:
    static const char DEFAULT_TABLE_NAME[];
    static const int DEFAULT_TABLE_SIZE;
    static const char COPY_SUFFIX[];

    std::string s_name;
    int* p_array;
    int i_size;
};
