#pragma once
#include <vector>

class CTreeDynamic
{
public:
    class CNodeDynamic
    {
        friend class CTreeDynamic;

    public:
        ~CNodeDynamic();
        void vSetValue(int iNewVal);
        int iGetChildrenNumber() const;
        void vAddNewChild();
        CNodeDynamic* pcGetChild(int iChildOffset);
        void vPrint() const;
        void vPrintAllBelow();
        void vPrintUp();

    private:
        std::vector<CNodeDynamic*> v_children;
        CNodeDynamic* pc_parent_node;
        int i_val;

        CNodeDynamic();
        CNodeDynamic(CNodeDynamic* pcParent);
    };

    CTreeDynamic();
    ~CTreeDynamic();

    CNodeDynamic* pcGetRoot();
    void vPrintTree();
    bool bMoveSubtree(CNodeDynamic* pcParentNode, CNodeDynamic* pcNewChildNode);

private:
    CNodeDynamic* c_root;
};
