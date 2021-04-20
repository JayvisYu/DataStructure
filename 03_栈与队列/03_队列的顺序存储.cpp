#include <stdio.h>
#include <stdlib.h>

#define MaxSize 10

typedef struct
{
    int data[MaxSize];
    int front, rear; // 队头和队尾指针
} SqQueue;

// 函数声明
void InitQueue(SqQueue &Q);       // 初始化队列
bool QueueEmpty(SqQueue Q);       // 判空
bool DestoryQueue(SqQueue &Q);    // 销毁队列
bool EnQueue(SqQueue &Q, int x);  // 入队
bool DeQueue(SqQueue &Q, int &x); // 出队
bool GetHead(SqQueue Q, int &x);  // 读队头元素

void InitQueue(SqQueue &Q)
{
    Q.rear = Q.front = 0; // 初始时,队头队尾指向0
}

bool QueueEmpty(SqQueue Q)
{
    if (Q.rear == Q.front)
        return true;
    else
        return false;
}

bool EnQueue(SqQueue &Q, int x)
{
    if ((Q.rear + 1) % MaxSize == Q.front)
        return false; // 队满,报错
    Q.data[Q.rear] = x;
    Q.rear = (Q.rear + 1) % MaxSize;
    return true;
}

bool DeQueue(SqQueue &Q, int &x)
{
    if (Q.rear == Q.front)
        return false; // 队空,报错
    x = Q.data[Q.front];
    Q.front = (Q.front + 1) % MaxSize;
    return true;
}

bool GetHead(SqQueue Q, int &x)
{
    if (Q.rear == Q.front)
        return false;
    x = Q.data[Q.front];
    return true;
}

// 如果不能浪费一个存储位置,有如下两种方案
// 方案1
// typedef struct
// {
//     int data[MaxSize];
//     int front, rear; // 队头和队尾指针
//     int size;
// } SqQueue;

// 判断队满 if(Q.rear == Q.front && size==MaxSize)
// 判断队空 if(Q.rear == Q.front && size==0)

// 方案2
typedef struct
{
    int data[MaxSize];
    int front, rear; // 队头和队尾指针
    int tag;         // 一次插入操作tag+1,一次删除操作tag-1
} SqQueue;

// 判断队满 if(Q.rear == Q.front && tag==1)
// 判断队空 if(Q.rear == Q.front && tag==0)

// 其他情况 rear指向队尾元素/rear指向队尾元素后一个位置 确定判空判满的方法
