#pragma once
#include <vector>

class CTreeDynamic
{
public:
    class CNode
    {
        friend class CTreeDynamic;

    public:
        ~CNode();
        void vSetValue(int iNewVal);
        int iGetChildrenNumber() const;
        void vAddNewChild();
        CNode* pcGetChild(int iChildOffset);
        void vPrint() const;
        void vPrintAllBelow();
        void vPrintUp();

    private:
        std::vector<CNode*> v_children;
        CNode* pc_parent_node;
        int i_val;

        CNode();
        CNode(CNode* pcParent);
    };

    CTreeDynamic();
    ~CTreeDynamic();

    CNode* pcGetRoot();
    void vPrintTree();
    bool bMoveSubtree(CNode* pcParentNode, CNode* pcNewChildNode);

private:
    CNode* c_root;
};
