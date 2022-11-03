#include "lista2_CTable.h"

#include <iostream>

using namespace std;

int main()
{
    CTable_z2 tab1("tablica1", 10);
    CTable_z2 tab2("tablica2", 5);

    for (int i = 0; i < tab1.iGetSize(); i++) {
        tab1.vSetValueAt(i, i);
    }

    for (int i = 0; i < tab2.iGetSize(); i++) {
        tab2.vSetValueAt(i, i * i);
    }

    CTable_z2 tab3;
    tab3 = tab1 + tab2;
    std::cout << "Nazwa tablicy: " << tab3.sGetName() << std::endl;
    tab3.vPrint();

    return 0;
}
