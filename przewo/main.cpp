#include "lista4.h"

#include "lista3_CTreeDynamic.h"
#include "lista3_CTreeStatic.h"

#include <iostream>

using namespace std;

int main()
{
    std::cout << "Drzewo intow:" << std::endl;
    v_tree_test_int();
    std::cout << "Drzewo stringow:" << std::endl;
    v_tree_test_string();
}
