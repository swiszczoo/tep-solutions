#include "lista3_CTreeStatic.h"

#include <iostream>

// CNode

CTreeStatic::CNode::CNode()
{
    i_val = 0; 
    pc_parent_node = NULL;
}

CTreeStatic::CNode::CNode(CNode* pcParent)
{
    i_val = 0;
    pc_parent_node = pcParent;
}

CTreeStatic::CNode::~CNode()
{
}

void CTreeStatic::CNode::vSetValue(int iNewVal)
{
    i_val = iNewVal;
}

int CTreeStatic::CNode::iGetChildrenNumber() const
{
    return v_children.size();
}

void CTreeStatic::CNode::vAddNewChild()
{
    v_children.push_back(CNode(this));
}

CTreeStatic::CNode* CTreeStatic::CNode::pcGetChild(int iChildOffset)
{
    if (iChildOffset < 0 || iChildOffset >= v_children.size()) {
        return NULL;
    }

    return &v_children[iChildOffset];
}

void CTreeStatic::CNode::vPrint() const
{
    std::cout << i_val << ' ';
}

void CTreeStatic::CNode::vPrintAllBelow()
{
    vPrint();

    for (int i = 0; i < v_children.size(); i++) {
        v_children[i].vPrintAllBelow();
    }
}

void CTreeStatic::CNode::vPrintUp()
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

CTreeStatic::CNode* CTreeStatic::pcGetRoot()
{
    return &c_root;
}

void CTreeStatic::vPrintTree()
{
    c_root.vPrintAllBelow();
}

bool CTreeStatic::bMoveSubtree(CNode* pcParentNode, CNode* pcNewChildNode)
{
    if (!pcParentNode || !pcNewChildNode)
        return false;

    CNode* prevParent = pcNewChildNode->pc_parent_node;

    if (!prevParent)
        return false;

    pcParentNode->v_children.push_back(*pcNewChildNode);

    std::vector<CNode>& children = prevParent->v_children;

    for (int i = 0; i < children.size(); i++) {
        if (&children[i] == pcNewChildNode) {
            children.erase(children.begin() + i);
            i = children.size();
        }
    }

    pcNewChildNode->pc_parent_node = pcParentNode;
    return true;
}
