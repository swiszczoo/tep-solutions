#include "lista4.h"
#include "lista4_CTreeDynamic.h"

#include <string>

void v_tree_test_int()
{
    CTreeDynamic<int> c_tree;
    CTreeDynamic<int>::CNode* c_root = c_tree.pcGetRoot();

    c_root->vAddNewChild();
    c_root->vAddNewChild();

    c_root->pcGetChild(0)->vSetValue(1);
    c_root->pcGetChild(1)->vSetValue(2);

    c_root->pcGetChild(0)->vAddNewChild();
    c_root->pcGetChild(0)->vAddNewChild();

    c_root->pcGetChild(0)->pcGetChild(0)->vSetValue(11);
    c_root->pcGetChild(0)->pcGetChild(1)->vSetValue(12);

    c_root->pcGetChild(1)->vAddNewChild();
    c_root->pcGetChild(1)->vAddNewChild();

    c_root->pcGetChild(1)->pcGetChild(0)->vSetValue(21);
    c_root->pcGetChild(1)->pcGetChild(1)->vSetValue(22);

    c_root->vPrintAllBelow();

    std::cout << std::endl;

    c_tree.vPrintTree();

    std::cout << std::endl;

    c_root->pcGetChild(0)->pcGetChild(1)->vPrintUp();
}

void v_tree_test_string()
{
    CTreeDynamic<std::string> c_tree;
    CTreeDynamic<std::string>::CNode* c_root = c_tree.pcGetRoot();

    c_root->vAddNewChild();
    c_root->vAddNewChild();

    c_root->pcGetChild(0)->vSetValue("n1");
    c_root->pcGetChild(1)->vSetValue("n2");

    c_root->pcGetChild(0)->vAddNewChild();
    c_root->pcGetChild(0)->vAddNewChild();

    c_root->pcGetChild(0)->pcGetChild(0)->vSetValue("n11");
    c_root->pcGetChild(0)->pcGetChild(1)->vSetValue("n12");

    c_root->pcGetChild(1)->vAddNewChild();
    c_root->pcGetChild(1)->vAddNewChild();

    c_root->pcGetChild(1)->pcGetChild(0)->vSetValue("n21");
    c_root->pcGetChild(1)->pcGetChild(1)->vSetValue("n22");

    c_root->vPrintAllBelow();

    std::cout << std::endl;

    c_tree.vPrintTree();

    std::cout << std::endl;

    c_root->pcGetChild(0)->pcGetChild(1)->vPrintUp();
}
