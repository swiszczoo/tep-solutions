#include "lista3.h"

#include <iostream>

using namespace std;

int main()
{
    std::cout << "Drzewo statyczne:" << std::endl;
    v_tree_test();
    std::cout << std::endl << "Drzewo dynamiczne:" << std::endl;
    v_dynamic_tree_test();
    std::cout << std::endl << "Drzewo dynamiczne - przenoszenie:" << std::endl;
    v_dynamic_move_test();
}
