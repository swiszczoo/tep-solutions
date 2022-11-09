#include "lista3_CTreeDynamic.h"

#include <iostream>

// CNodeDynamic

CTreeDynamic::CNodeDynamic::CNodeDynamic()
{
    i_val = 0;
    pc_parent_node = NULL;
}

CTreeDynamic::CNodeDynamic::CNodeDynamic(CNodeDynamic* pcParent)
{
    i_val = 0;
    pc_parent_node = pcParent;
}

CTreeDynamic::CNodeDynamic::~CNodeDynamic()
{
    for (int i = 0; i < v_children.size(); i++) {
        delete v_children[i];
    }
}

void CTreeDynamic::CNodeDynamic::vSetValue(int iNewVal)
{
    i_val = iNewVal;
}

int CTreeDynamic::CNodeDynamic::iGetChildrenNumber() const
{
    return v_children.size();
}

void CTreeDynamic::CNodeDynamic::vAddNewChild()
{
    v_children.push_back(new CNodeDynamic(this));
}

CTreeDynamic::CNodeDynamic* CTreeDynamic::CNodeDynamic::pcGetChild(int iChildOffset)
{
    if (iChildOffset < 0 || iChildOffset >= v_children.size()) {
        return NULL;
    }

    return v_children[iChildOffset];
}

void CTreeDynamic::CNodeDynamic::vPrint() const
{
    std::cout << i_val << ' ';
}

void CTreeDynamic::CNodeDynamic::vPrintAllBelow()
{
    vPrint();

    for (int i = 0; i < v_children.size(); i++) {
        v_children[i]->vPrintAllBelow();
    }
}

void CTreeDynamic::CNodeDynamic::vPrintUp()
{
    std::cout << i_val << ' ';

    if (pc_parent_node != NULL) {
        pc_parent_node->vPrintUp();
    }
}

// CTreeDynamic

CTreeDynamic::CTreeDynamic()
{
    c_root = new CNodeDynamic;
}

CTreeDynamic::~CTreeDynamic()
{
    delete c_root;
}

CTreeDynamic::CNodeDynamic* CTreeDynamic::pcGetRoot()
{
    return c_root;
}

void CTreeDynamic::vPrintTree()
{
    c_root->vPrintAllBelow();
}

bool CTreeDynamic::bMoveSubtree(CNodeDynamic* pcParentNode, CNodeDynamic* pcNewChildNode)
{
    CNodeDynamic* prevParent = pcNewChildNode->pc_parent_node;

    if (!prevParent) {
        return false;
    }

    std::vector<CNodeDynamic*>& children = prevParent->v_children;

    for (int i = 0; i < children.size(); i++) {
        if (children[i] == pcNewChildNode) {
            children.erase(children.begin() + i);
            i = children.size();
        }
    }

    pcParentNode->v_children.push_back(pcNewChildNode);
    pcNewChildNode->pc_parent_node = pcParentNode;
    return true;
}
