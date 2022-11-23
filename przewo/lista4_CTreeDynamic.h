#pragma once
#include <iostream>
#include <vector>

template <typename T>
class CTreeDynamic
{
public:
    class CNode
    {
        friend class CTreeDynamic;

    public:
        ~CNode()
        {
            for (int i = 0; i < v_children.size(); i++) {
                delete v_children[i];
            }
        }

        void vSetValue(const T& tNewVal)
        {
            t_val = tNewVal;
        }

        int iGetChildrenNumber() const
        {
            return v_children.size();
        }

        void vAddNewChild()
        {
            v_children.push_back(new CNode(this));
        }

        CNode* pcGetChild(int iChildOffset)
        {
            if (iChildOffset < 0 || iChildOffset >= v_children.size()) {
                return NULL;
            }

            return v_children[iChildOffset];
        }

        void vPrint() const
        {
            std::cout << t_val << ' ';
        }

        void vPrintAllBelow()
        {
            vPrint();

            for (int i = 0; i < v_children.size(); i++) {
                v_children[i]->vPrintAllBelow();
            }
        }

        void vPrintUp()
        {
            std::cout << t_val << ' ';

            if (pc_parent_node != NULL) {
                pc_parent_node->vPrintUp();
            }
        }

    private:
        std::vector<CNode*> v_children;
        CNode* pc_parent_node;
        T t_val;

        CNode()
        {
            t_val = T();
            pc_parent_node = NULL;
        }

        CNode(CNode* pcParent)
        {
            t_val = T();
            pc_parent_node = pcParent;
        }
    };

    CTreeDynamic()
    {
        c_root = new CNode;
    }

    ~CTreeDynamic()
    {
        delete c_root;
    }

    CNode* pcGetRoot() const
    {
        return c_root;
    }

    void vPrintTree()
    {
        c_root->vPrintAllBelow();
    }

    bool bMoveSubtree(CNode* pcParentNode, CNode* pcNewChildNode)
    {
        CNode* prevParent = pcNewChildNode->pc_parent_node;

        if (!prevParent) {
            return false;
        }

        std::vector<CNode*>& children = prevParent->v_children;

        for (int i = 0; i < children.size(); i++) {
            if (children[i] == pcNewChildNode) {
                children.erase(children.begin() + i);
                i = children.size();
            }
        }
    }

private:
    CNode* c_root;
};
