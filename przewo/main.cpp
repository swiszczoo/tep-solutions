#include "lista1.h"
#include "lista1_CTable.h"

#include <iostream>

using namespace std;

void v_mod_tab(CTable* pcTab, int iNewSize)
{
    pcTab->bSetNewSize(iNewSize);
}

void v_mod_tab(CTable cTab, int iNewSize)
{
    cTab.bSetNewSize(iNewSize);
}

int main()
{
    cout << "Zadanie 1:" << endl;
    cout << "Podaj rozmiar tablicy: ";

    int size;
    cin >> size;

    v_alloc_table_fill_34(size);

    cout << "Zadanie 2 i 3:" << endl;
    int** tab = NULL;
    int sizeX, sizeY;

    cout << "Podaj rozmiar X: ";
    cin >> sizeX;
    cout << "Podaj rozmiar Y: ";
    cin >> sizeY;

    cout << (b_alloc_table_2_dim(&tab, sizeX, sizeY) ? "Alokacja OK" : "Alokacja nie OK") << endl;
    cout << (b_dealloc_table_2_dim(&tab, sizeX, sizeY) ? "Dealokacja OK" : "Dealokacja nie OK") << endl;

    cout << "Zadanie 4:" << endl;

    {
        CTable tab;
    }
    {
        CTable tab("przyklad", 50);
        tab.bSetNewSize(40);
        CTable* tab2 = tab.pcClone();
        tab2->vSetName("cloned");
        CTable tab3(tab);

        delete tab2;
    }

    cout << "Test przekazywania przez kopie:" << endl;
    {
        CTable test;
        v_mod_tab(test, 50);
    }

    cout << "Test wskaznika:" << endl;
    {
        CTable test;
        v_mod_tab(&test, 50);
    }

    return 0;
}
