#include "lista3_CTreeDynamic.h"

#include <iostream>

// CNode

CTreeDynamic::CNode::CNode()
{
    i_val = 0;
    pc_parent_node = NULL;
}

CTreeDynamic::CNode::CNode(CNode* pcParent)
{
    i_val = 0;
    pc_parent_node = pcParent;
}

CTreeDynamic::CNode::~CNode()
{
    for (int i = 0; i < v_children.size(); i++) {
        delete v_children[i];
    }
}

void CTreeDynamic::CNode::vSetValue(int iNewVal)
{
    i_val = iNewVal;
}

int CTreeDynamic::CNode::iGetChildrenNumber() const
{
    return v_children.size();
}

void CTreeDynamic::CNode::vAddNewChild()
{
    v_children.push_back(new CNode(this));
}

CTreeDynamic::CNode* CTreeDynamic::CNode::pcGetChild(int iChildOffset)
{
    if (iChildOffset < 0 || iChildOffset >= v_children.size()) {
        return NULL;
    }

    return v_children[iChildOffset];
}

void CTreeDynamic::CNode::vPrint() const
{
    std::cout << i_val << ' ';
}

void CTreeDynamic::CNode::vPrintAllBelow()
{
    vPrint();

    for (int i = 0; i < v_children.size(); i++) {
        v_children[i]->vPrintAllBelow();
    }
}

void CTreeDynamic::CNode::vPrintUp()
{
    std::cout << i_val << ' ';

    if (pc_parent_node != NULL) {
        pc_parent_node->vPrintUp();
    }
}

// CTreeDynamic

CTreeDynamic::CTreeDynamic()
{
    c_root = new CNode;
}

CTreeDynamic::~CTreeDynamic()
{
    delete c_root;
}

CTreeDynamic::CNode* CTreeDynamic::pcGetRoot()
{
    return c_root;
}

void CTreeDynamic::vPrintTree()
{
    c_root->vPrintAllBelow();
}

bool CTreeDynamic::bMoveSubtree(CNode* pcParentNode, CNode* pcNewChildNode)
{
    if (!pcParentNode || !pcNewChildNode)
        return false;

    CNode* prevParent = pcNewChildNode->pc_parent_node;

    if (!prevParent)
        return false;

    std::vector<CNode*>& children = prevParent->v_children;

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
