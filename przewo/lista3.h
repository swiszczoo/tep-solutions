#pragma once
#include <iostream>

template <class TreeImpl>
void v_tree_test()
{
    TreeImpl c_tree;
    typename TreeImpl::CNode* c_root = c_tree.pcGetRoot();

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

template <class TreeImpl>
void v_move_test()
{
    TreeImpl c_tree1;
    TreeImpl c_tree2;

    typename TreeImpl::CNode* c_root1 = c_tree1.pcGetRoot();
    typename TreeImpl::CNode* c_root2 = c_tree2.pcGetRoot();

    c_root1->vAddNewChild();
    c_root1->vAddNewChild();
    c_root1->vAddNewChild();
    c_root1->pcGetChild(0)->vSetValue(1);
    c_root1->pcGetChild(1)->vSetValue(2);
    c_root1->pcGetChild(2)->vSetValue(3);
    c_root1->pcGetChild(2)->vAddNewChild();
    c_root1->pcGetChild(2)->pcGetChild(0)->vSetValue(4);

    c_root2->vAddNewChild();
    c_root2->vAddNewChild();
    c_root2->pcGetChild(0)->vSetValue(54);
    c_root2->pcGetChild(1)->vSetValue(55);
    c_root2->pcGetChild(0)->vAddNewChild();
    c_root2->pcGetChild(0)->vAddNewChild();
    c_root2->pcGetChild(0)->pcGetChild(0)->vSetValue(56);
    c_root2->pcGetChild(0)->pcGetChild(1)->vSetValue(57);
    c_root2->pcGetChild(0)->pcGetChild(0)->vAddNewChild();
    c_root2->pcGetChild(0)->pcGetChild(0)->pcGetChild(0)->vSetValue(58);

    c_tree1.bMoveSubtree(c_root1->pcGetChild(2), c_root2->pcGetChild(0));

    std::cout << "Drzewo 1:" << std::endl;
    c_tree1.vPrintTree();

    std::cout << std::endl << "Drzewo 2:" << std::endl;
    c_tree2.vPrintTree();
}
