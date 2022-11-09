#include "lista3_CTreeStatic.h"

#include <iostream>

// CNodeStatic

CTreeStatic::CNodeStatic::CNodeStatic()
{
    i_val = 0; 
    pc_parent_node = NULL;
}

CTreeStatic::CNodeStatic::CNodeStatic(CNodeStatic* pcParent)
{
    i_val = 0;
    pc_parent_node = pcParent;
}

CTreeStatic::CNodeStatic::~CNodeStatic()
{
}

void CTreeStatic::CNodeStatic::vSetValue(int iNewVal)
{
    i_val = iNewVal;
}

int CTreeStatic::CNodeStatic::iGetChildrenNumber() const
{
    return v_children.size();
}

void CTreeStatic::CNodeStatic::vAddNewChild()
{
    v_children.push_back(CNodeStatic(this));
}

CTreeStatic::CNodeStatic* CTreeStatic::CNodeStatic::pcGetChild(int iChildOffset)
{
    if (iChildOffset < 0 || iChildOffset >= v_children.size()) {
        return NULL;
    }

    return &v_children[iChildOffset];
}

void CTreeStatic::CNodeStatic::vPrint() const
{
    std::cout << i_val << ' ';
}

void CTreeStatic::CNodeStatic::vPrintAllBelow()
{
    vPrint();

    for (int i = 0; i < v_children.size(); i++) {
        v_children[i].vPrintAllBelow();
    }
}

void CTreeStatic::CNodeStatic::vPrintUp()
{
    std::cout << i_val << ' ';

    if (pc_parent_node != NULL) {
        pc_parent_node->vPrintUp();
    }
}

// CTreeStatic

CTreeStatic::CTreeStatic()
{
}

CTreeStatic::~CTreeStatic()
{
}

CTreeStatic::CNodeStatic* CTreeStatic::pcGetRoot()
{
    return &c_root;
}

void CTreeStatic::vPrintTree()
{
    c_root.vPrintAllBelow();
}

bool CTreeStatic::bMoveSubtree(CNodeStatic* pcParentNode, CNodeStatic* pcNewChildNode)
{
    CNodeStatic* prevParent = pcNewChildNode->pc_parent_node;

    if (!prevParent) {
        return false;
    }

    std::vector<CNodeStatic>& children = prevParent->v_children;

    for (int i = 0; i < children.size(); i++) {
        if (&children[i] == pcNewChildNode) {
            children.erase(children.begin() + i);
            i = children.size();
        }
    }

    pcParentNode->v_children.push_back(pcNewChildNode);
    pcNewChildNode->pc_parent_node = pcParentNode;

    // TODO: finish this
    return true;
}
