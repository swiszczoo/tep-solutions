#include "lista3.h"

#include "lista3_CTreeDynamic.h"
#include "lista3_CTreeStatic.h"

#include <iostream>

using namespace std;

int main()
{
    std::cout << "Drzewo statyczne:" << std::endl;
    v_tree_test<CTreeStatic>();
    std::cout << std::endl << "Drzewo dynamiczne:" << std::endl;
    v_tree_test<CTreeDynamic>();
    std::cout << std::endl << "Drzewo statyczne - przenoszenie:" << std::endl;
    v_move_test<CTreeStatic>();
    std::cout << std::endl << "Drzewo dynamiczne - przenoszenie:" << std::endl;
    v_move_test<CTreeDynamic>();

    return 0;
}
