#include <stdio.h>
#include <stdlib.h>

typedef struct LinkNode
{
    int data;
    struct LinkNode *next;
} LinkNode;

typedef struct
{
    LinkNode *front, *rear;
} LinkQueue;

// 带头结点
void InitQueue(LinkQueue &Q);       // 初始化
bool IsEmpty(LinkQueue Q);          // 判空
bool EnQueue(LinkQueue &Q, int x);  // 入队
bool DeQueue(LinkQueue &Q, int &x); // 出队

void InitQueue(LinkQueue &Q)
{
    Q.front = Q.rear = (LinkNode *)malloc(sizeof(LinkNode));
    Q.front->next = NULL;
}

bool IsEmpty(LinkQueue Q)
{
    if (Q.front == Q.rear)
        return true;
    else
        return false;
}

// 带头结点
bool EnQueue(LinkQueue &Q, int x)
{
    LinkNode *s = (LinkNode *)malloc(sizeof(LinkNode));
    s->data = x;
    s->next = NULL;
    Q.rear->next = s; // 新结点插入到rear之后
    Q.rear = s;       // 修改表位指针
}

// 不带头结点
bool EnQueue(LinkQueue &Q, int x)
{
    LinkNode *s = (LinkNode *)malloc(sizeof(LinkNode));
    s->data = x;
    s->next = NULL;
    if (Q.front == NULL)
    {
        Q.front = s; // 在空队列中插入第一个元素
        Q.rear = s;  // 修改队头队尾指针
    }
    else
    {
        Q.rear->next = s; // 新结点插入到rear之后
        Q.rear = s;       // 修改表位指针
    }
}

// 带头结点
bool DeQueue(LinkQueue &Q, int &x)
{
    if (Q.front == Q.rear)
        return false; // 空队
    LinkNode *p = Q.front->next;
    x = p->data;             // 用变量x返回头元素
    Q.front->next = p->next; // 修改头结点的next指针
    if (Q.rear == p)         // 此次是最后一个结点出队
        Q.rear = Q.front;    // 修改rear指针
    free(p);                 // 释放结点空间
    return true;
}

// 不带头结点
bool DeQueue(LinkQueue &Q, int &x)
{
    if (Q.front == Q.rear)
        return false;      // 空队
    LinkNode *p = Q.front; // p指向此次出队的结点
    x = p->data;           // 用变量x返回头元素
    Q.front = p->next;     // 修改front指针
    if (Q.rear == p)       // 此次是最后一个结点出队
    {
        Q.front = NULL; // front指向NULL
        Q.rear = NULL;  // rear指向NULL
    }
    free(p); // 释放结点空间
    return true;
}

// 队列满的条件 不用关心
