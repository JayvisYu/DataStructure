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

// 层序遍历
void LevelOrder(BiTree T)
{
    LinkQueue Q;
    InitQueue(Q); // 初始化辅助队列
    BiTree p;
    EnQueue(Q, T); // 将根结点入队
    while (!IsEmpty(Q))
    {                  // 队列不为空则循环
        DeQueue(Q, p); // 队头结点出队
        visit(p);      // 访问出队结点
        if (p->lchild != NULL)
            EnQueue(Q, p->lchild); // 左孩子入队
        if (p->rchild != NULL)
            EnQueue(Q, p->rchild); // 右孩子入队
    }
}
