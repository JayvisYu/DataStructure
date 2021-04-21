#include <stdio.h>
#include <stdlib.h>

// 不带头结点的版本
typedef struct LinkNode1
{
    int data;
    struct LinkNode1 *next;
} * LiStack1;

// 初始化
void InitStack1(LiStack1 &L)
{
    L = NULL;
}

// 判空
bool IsEmpty1(LiStack1 L)
{
    return (L == NULL);
}

//进栈
LiStack1 Push1(LiStack1 &L, int x)
{
    LinkNode1 *s = (LiStack1)malloc(sizeof(LinkNode1));
    s->data = x;
    s->next = L;
    L = s;
    return L;
}

//出栈
bool Pop1(LiStack1 &L)
{
    if (L == NULL)
    {
        return false;
    }
    L = L->next;
    return true;
}

//读栈
void GetTop1(LiStack1 L)
{
    while (L)
    {
        printf("%d", L->data);
        L = L->next;
    }
}

// 带头结点的版本
typedef struct LinkNode2
{
    int data;
    struct LinkNode2 *next;
} * LiStack2;

// 初始化
bool InitStack(LiStack2 &L)
{
    L = (LiStack2)malloc(sizeof(LinkNode2));
    if (L == NULL)
    {
        return false;
    }
    L->next = NULL;
    return true;
}

//进栈
LiStack2 Push2(LiStack2 &L, int x)
{
    LinkNode2 *s = (LiStack2)malloc(sizeof(LinkNode2));
    s->data = x;
    s->next = L->next;
    L->next = s;
    return L;
}

//出栈
bool Pop2(LiStack2 &L)
{
    if (L->next == NULL)
    {
        return false;
    }
    LinkNode2 *q = L->next;
    L->next = q->next;
    return true;
}

//读栈
void GetTop2(LiStack2 L)
{
    while (L->next)
    {
        L = L->next;
        printf("%d", L->data);
    }
}
