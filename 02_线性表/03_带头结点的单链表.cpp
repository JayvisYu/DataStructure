#include <stdio.h>
#include <stdlib.h>

typedef struct LNode
{
    int data;
    LNode *next;
} LNode, *LinkList;

//函数定义
bool InitList(LinkList &L);                  //初始化
bool Empty(LinkList L);                      //判空
bool ListInsert(LinkList &L, int i, int e);  //按位插入
bool InsertNextNode(LNode *p, int e);        //指定节点的后插操作
bool InsertPriorNode(LNode *p, int e);       //指定节点的前插操作————先完成后插，再交换数据以实现前插
bool ListDelete(LinkList &L, int i, int &e); //按指定位序删除节点并返回其值
bool DeleteNode(LNode *p);                   //删除指定节点
LNode *GetElem(LinkList L, int i);           // 按位查找
LNode *LocateElem(LinkList L, int i);        // 按值查找
int Length(LinkList L);                      // 求表长度

//初始化(带有头节点)
bool InitList(LinkList &L)
{
    L = (LNode *)malloc(sizeof(LNode)); //分配一个头节点
    if (L == NULL)
        return false; //头节点分配失败，可能是内存不足
    L->next = NULL;   //头节点之后暂时没有节点，头节点也不存放数据
    return true;
}

//判空
bool Empty(LinkList L)
{
    return (L->next == NULL);
}

//按位插入
bool ListInsert(LinkList &L, int i, int e)
{
    if (i < 1)
        return false; //判断位序i是否合法
    LNode *p;         //指针指向当前扫面到的节点
    int j = 0;        //记录p指向的节点的位序
    p = L;            //L指向头节点，从头开始
    while (p != NULL && j < i - 1)
    {
        //循环扫描
        p = p->next;
        j++;
    }
    if (p == NULL) //i值超过来表长，不合法
        return false;
    LNode *s = (LNode *)malloc(sizeof(LNode));
    s->data = e;
    //下面的顺序不可交换
    s->next = p->next;
    p->next = s;
    return true;
}

//指定节点的后插操作
bool InsertNextNode(LNode *p, int e)
{
    if (p == NULL)
        return false; //判断指定节点是否存在
    LNode *s = (LNode *)malloc(sizeof(LNode));
    if (s == NULL)
        return false; //分配内存失败
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}

//指定节点的前插操作
//先完成后插，再交换数据以实现前插
bool InsertPriorNode(LNode *p, int e)
{
    if (p == NULL)
        return false;
    LNode *s = (LNode *)malloc(sizeof(LNode));
    if (s == NULL)
        return false;
    s->next = p->next;
    p->next = s;
    s->data = p->data;
    p->data = e;
    return true;
}

//按指定位序删除节点并返回其值
bool ListDelete(LinkList &L, int i, int &e)
{
    if (i < 1)
        return false;
    LNode *p;
    int j = 0;
    p = L;
    while (p != NULL && j < i - 1)
    {
        p = p->next;
        j++;
    }
    LNode *q = p->next;
    e = q->data;
    p->next = q->next;
    free(q);
    return true;
}

//删除指定节点
bool DeleteNode(LNode *p)
{
    if (p == NULL)
        return false;
    LNode *q = p->next;
    p->data = p->next->data;
    p->next = q->next;
    free(q);
    return true;
}

// 按位查找, 返回第i个元素(带头结点)
LNode *GetElem(LinkList L, int i)
{
    if (i < 0)
        return NULL;
    LNode *p;
    int j = 0;
    p = L;
    while (p != NULL && j < i)
    {
        p = p->next;
        j++;
    }
    return p;
}

// 按值查找, 找到数据域==e的结点
LNode *LocateElem(LinkList L, int e)
{
    LNode *p = L->next;
    // 从第一个结点开始查找数据域为e的结点
    while (p != NULL && p->data != e)
        p = p->next;
    return p;
}

// 求表的长度
int Length(LinkList L)
{
    int len = 0;
    LNode *p = L;
    while (p->next != NULL)
    {
        p = p->next;
        len++;
    }
    return len;
}

// 头插法建立单链表
LinkList List_HeadInsert(LinkList &L)
{
    LNode *s;
    int x;
    L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;
    scanf("%d", &x);
    while (x != 9999)
    {
        s = (LNode *)malloc(sizeof(LNode));
        s->data = x;
        s->next = L->next;
        L->next = s;
        scanf("%d", &x);
    }
    return L;
}

// 尾插法建立单链表
LinkList List_TailInsert(LinkList &L)
{
    int x;
    L = (LinkList)malloc(sizeof(LNode));
    LNode *s, *r = L;
    scanf("%d", &x);
    while (x != 9999)
    {
        s = (LNode *)malloc(sizeof(LNode));
        s->data = x;
        r->next = s;
        r = s;
        scanf("%d", &x);
    }
    r->next = NULL;
    return L;
}
