#include "lista1.h"
#include <iostream>

void v_alloc_table_fill_34(int iSize)
{
    static const int TABLE_CONTENT = 34;
        
    if (iSize <= 0) {
        std::cerr << "Nieprawidlowy rozmiar tablicy" << std::endl;
        return;
    }

    int* arr = new int[iSize];

    for (int i = 0; i < iSize; i++) {
        arr[i] = TABLE_CONTENT;
    }

    for (int i = 0; i < iSize; i++) {
        std::cout << "arr[" << i << "] = " << arr[i] << std::endl;
    }

    delete[] arr;
}

bool b_alloc_table_2_dim(int*** piTable, int iSizeX, int iSizeY)
{
    if (iSizeX <= 0 || iSizeY <= 0 || !piTable) {
        return false;
    }

    int** arr = new int* [iSizeX];

    for (int i = 0; i < iSizeX; i++) {
        arr[i] = new int[iSizeY];
    }

    *piTable = arr;
    return true;
}

bool b_dealloc_table_2_dim(int*** piTable, int iSizeX, int iSizeY)
{
    if (!piTable || iSizeX <= 0 || iSizeY <= 0) {
        return false;
    }

    for (int i = 0; i < iSizeX; i++) {
        delete[] (*piTable)[i];
    }

    delete[] (*piTable);
    *piTable = NULL;

    return true;
}
