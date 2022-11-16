#pragma once
#include <vector>

class CTreeStatic
{
public:
    class CNode
    {
        friend class CTreeStatic;

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
        std::vector<CNode> v_children;
        CNode* pc_parent_node;
        int i_val;

        CNode();
        CNode(CNode* pcParent);
    };

    CTreeStatic();
    ~CTreeStatic();

    CNode* pcGetRoot();
    void vPrintTree();
    bool bMoveSubtree(CNode* pcParentNode, CNode* pcNewChildNode);

private:
    CNode c_root;
};
