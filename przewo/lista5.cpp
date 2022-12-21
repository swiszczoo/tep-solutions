#include "lista5.h"
#include "lista5_CMySmartPointer.h"
#include "lista5_CTab.h"
#include "lista5_CTable.h"

#include <iostream>

void test_smart_ptr()
{
    CMySmartPointer<int> smartPtr(new int[50]);
    (*smartPtr) = 50;
    CMySmartPointer<int> secondPtr = smartPtr;

    smartPtr = nullptr;
    std::cout << "Wskaznik zawiera liczbe " << (*secondPtr) << std::endl;
}

void test_CTab()
{
    CTab tab1;
    tab1.bSetSize(100);
    CTab tab2;
    
    tab2 = std::move(tab1);
    std::cout << "Rozmiar tablicy to " << tab2.iGetSize() << std::endl;
}

template <bool useMoveSemantics>
void test_CTable_impl()
{
    CTable_z5<useMoveSemantics> tab1("t1", 10);
    CTable_z5<useMoveSemantics> tab2("t2", 15);

    for (int i = 0; i < 10; i++) {
        tab1.vSetValueAt(i, i);
    }

    for (int i = 0; i < 15; i++) {
        tab2.vSetValueAt(i, 10 + i);
    }

    CTable_z5<useMoveSemantics> tab3 = tab1 + tab2;

    for (int i = 0; i < 25; i++) {
        std::cout << tab3.iGetValueAt(i) << ' ';
    }
    std::cout << std::endl;
}

void test_CTable()
{
    std::cout << "Bez semantyki przenoszenia:" << std::endl;
    test_CTable_impl<false>();
    std::cout << "Z semantyka przenoszenia:" << std::endl;
    test_CTable_impl<true>();
}
