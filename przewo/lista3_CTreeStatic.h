#pragma once
#include <vector>

class CTreeStatic
{
public:
    class CNodeStatic
    {
        friend class CTreeStatic;

    public:
        ~CNodeStatic();
        void vSetValue(int iNewVal);
        int iGetChildrenNumber() const;
        void vAddNewChild();
        CNodeStatic* pcGetChild(int iChildOffset);
        void vPrint() const;
        void vPrintAllBelow();
        void vPrintUp();

    private:
        std::vector<CNodeStatic> v_children;
        CNodeStatic* pc_parent_node;
        int i_val;

        CNodeStatic();
        CNodeStatic(CNodeStatic* pcParent);
    };

    CTreeStatic();
    ~CTreeStatic();

    CNodeStatic* pcGetRoot();
    void vPrintTree();
    bool bMoveSubtree(CNodeStatic* pcParentNode, CNodeStatic* pcNewChildNode);

private:
    CNodeStatic c_root;
};
