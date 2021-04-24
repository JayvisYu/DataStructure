#include <stdio.h>
#include <stdlib.h>

struct ElemType
{
    int value;
};

// 二叉树的结点
typedef struct BiTNode
{
    ElemType data;
    struct BiTNode *lchild, *rchild;
    struct BiTNOde *parent;
} BiTNode, *BiTree;

// 先序遍历
void PreOrder(BiTree T)
{
    if (T != NULL)
    {
        visit(T);
        PreOrder(T->lchild);
        PreOrder(T->rchild);
    }
}

// 中序遍历
void InOrder(BiTree T)
{
    if (T != NULL)
    {
        InOrder(T->lchild);
        visit(T);
        InOrder(T->rchild);
    }
}

// 后序遍历
void PostOrder(BiTree T)
{
    if (T != NULL)
    {
        PostOrder(T->lchild);
        PostOrder(T->rchild);
        visit(T);
    }
}

// 求树的深度(应用)
int TreeDepth(BiTree T)
{
    if (T == NULL)
    {
        return 0;
    }
    else
    {
        int l = TreeDepth(T->lchild);
        int r = TreeDepth(T->rchild);
        // 树的深度=Max(左子树深度, 右子树深度) +1
        return l > r ? l + 1 : r + 1;
    }
}
