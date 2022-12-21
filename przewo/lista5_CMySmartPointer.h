#pragma once

template <typename T>
class CMySmartPointer
{
    class CRefCounter
    {
    public:
        CRefCounter() { i_count = 0; }
        int iAdd() { return(++i_count); }
        int iDec() { return(--i_count); };
        int iGet() { return(i_count); }
    private:
        int i_count;
    };//class CRefCounter

public:
    CMySmartPointer(T* pcPointer)
    {
        pc_pointer = pcPointer;
        pc_counter = new CRefCounter();
        pc_counter->iAdd();
    }//CMySmartPointer(CSellData *pcPointer)

    CMySmartPointer(const CMySmartPointer& pcOther)
    {
        pc_pointer = pcOther.pc_pointer;
        pc_counter = pcOther.pc_counter;
        pc_counter->iAdd();
    }//CMySmartPointer(const CMySmartPointer &pcOther)

    CMySmartPointer& operator=(const CMySmartPointer& other)
    {
        if (this == &other) {
            return *this;
        }

        free();

        pc_pointer = other.pc_pointer;
        pc_counter = other.pc_counter;
        pc_counter->iAdd();

        return *this;
    }

    ~CMySmartPointer()
    {
        free();
    }//~CMySmartPointer()

    T& operator*() { return(*pc_pointer); }
    T* operator->() { return(pc_pointer); }

private:
    CRefCounter* pc_counter;
    T* pc_pointer;

    void free() {
        if (pc_counter->iDec() == 0)
        {
            delete pc_pointer;
            delete pc_counter;
        }//if (pc_counter->iDec())
    }

};//class CMySmartPointer
