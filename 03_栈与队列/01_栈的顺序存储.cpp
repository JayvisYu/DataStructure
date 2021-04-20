#include <stdio.h>
#include <stdlib.h>

#define MaxSize 10

typedef struct
{
    int data[MaxSize];
    int top;
} SqStack;

// 函数声明
void InitStack(SqStack &S);     // 初始化栈
bool StackEmpty(SqStack S);     // 栈空
bool Push(SqStack &S, int x);   // 入栈
bool Pop(SqStack &S, int &x);   // 出站
bool GetTop(SqStack S, int &x); // 读栈顶元素

void InitStack(SqStack &S)
{
    S.top = -1;
}

bool StackEmpty(SqStack S)
{
    if (S.top == -1)
        return true;
    else
        return false;
}

bool Push(SqStack &S, int x)
{
    if (S.top == MaxSize - 1) // 栈满,报错
        return false;
    S.top = S.top + 1; // 指针现加一
    S.data[S.top] = x; // 新元素入栈
    // S.data[++S.top] = x;  // 等价写法
    return true;
}

bool Pop(SqStack &S, int &x)
{
    if (S.top == -1)
        return false;  // 栈空,报错
    x = S.data[S.top]; // 栈顶元素先出栈
    S.top = S.top - 1; // 指针减1
    // x = S.data[S.top--];  // 等价写法
    return true;
}

bool GetTop(SqStack S, int &x)
{
    if (S.top == -1)
        return false;  // 栈空,报错
    x = S.data[S.top]; // x记录栈顶元素
    return true;
}
