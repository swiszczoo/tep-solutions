#include "lista5.h"

#include <iostream>

using namespace std;

int main()
{
    std::cout << "Sprytny wskaznik:" << std::endl;
    test_smart_ptr();
    std::cout << std::endl;

    std::cout << "Semantyka przenoszenia dla klasy CTab" << std::endl;
    test_CTab();
    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "Semantyka przenoszenia dla klasy CTable" << std::endl;
    test_CTable();
    std::cout << std::endl;
    std::cout << std::endl;
}
