#include <stdio.h>
#include <stdlib.h>

struct ElemType
{
    int value;
};

// 二叉树的结点
typedef struct ThreadNode
{
    ElemType data;
    struct ThreadNode *lchild, *rchild;
    int ltag, rtag; // 左右线索标志
} ThreadNode, *ThreadTree;

// 全局变量pre,指向当前访问结点的前驱
ThreadNode *pre = NULL;

// 中序线索化二叉树T
void InThread(ThreadTree T)
{
    if (T != NULL)
    {
        InThread(T->lchild); // 中序遍历左子树
        visit1(T);           // 访问根结点
        InThread(T->rchild); // 中序遍历右子数
    }
}

void visit1(ThreadNode *q)
{
    if (q->lchild == NULL) // 左子树为空,建立前驱线索
    {
        q->lchild = pre;
        q->ltag = 1;
    }
    if (pre != NULL && pre->rchild == NULL)
    {
        pre->rchild = q; // 建立前驱结点的后继线索
        pre->rtag = 1;
    }
    pre = q;
}

// 先序线索化二叉树
void PreThread(ThreadTree T)
{
    if (T != NULL)
    {
        visit2(T);
        PreThread(T->lchild);
        PreThread(T->rchild);
    }
}

void visit2(ThreadNode *q)
{
    if (q->lchild == NULL) // 左子树为空, 建立前驱线索
    {
        q->lchild = pre;
        q->ltag = 1;
    }
    if (pre != NULL && pre->rchild == NULL)
    {
        pre->rchild = q; // 建立前驱结点的后继线索
        pre->rtag = 1;
    }
    pre = q;
}

// 后序线索化二叉树
void PostThread(ThreadTree T)
{
    if (T != NULL)
    {
        PostThread(T->lchild);
        PostThread(T->rchild);
        visit3(T);
    }
}

void visit3(ThreadNode *q)
{
    if (q->lchild == NULL) // 左子树为空, 建立前驱线索
    {
        q->lchild = pre;
        q->ltag = 1;
    }
    if (pre != NULL && pre->rchild == NULL)
    {
        pre->rchild = q; // 建立前驱结点的后继线索
        pre->rtag = 1;
    }
    pre = q;
}
