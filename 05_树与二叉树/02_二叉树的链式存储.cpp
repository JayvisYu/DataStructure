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

void main()
{
    // 定义一颗空树
    BiTree root = NULL;

    // 插入根节点
    root = (BiTree)malloc(sizeof(BiTNode));
    root->data = {1};
    root->lchild = NULL;
    root->rchild = NULL;

    // 插入新结点
    BiTNode *p = (BiTree)malloc(sizeof(BiTNode));
    p->data = {2};
    p->lchild = NULL;
    p->rchild = NULL;
    root->lchild = p;
}
