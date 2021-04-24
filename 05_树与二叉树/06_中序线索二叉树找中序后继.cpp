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

// 找到以P为根的子树中,第一个被中序遍历的结点
ThreadNode *Firstnode(ThreadNode *p)
{
    // 循环找到最左下结点(不一定是叶结点)
    while (p->ltag == 0)
        p = p->lchild;
    return p;
}

// 在中序线索二叉树中找到结点p的后继结点
ThreadNode *Nextnode(ThreadNode *p)
{
    // 右子树中最左下结点
    if (p->rtag == 0)
        return Firstnode(p->rchild);
    else
        return p->rchild; // rtag=1直接返回后继线索
}

// 对中序线索二叉树进行中序遍历(利用线索实现的非递归算法)
void InOrder(ThreadNode *T)
{
    for (ThreadNode *p = Firstnode(T); p != NULL; p = Nextnode(p))
    {
        visit(p);
    }
}

// 全局变量pre,指向当前访问结点的前驱
ThreadNode *pre = NULL;

void visit(ThreadNode *q)
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
