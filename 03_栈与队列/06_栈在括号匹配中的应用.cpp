// 算法实现
#include <stdio.h>
#include <stdlib.h>

#define MaxSize 10 // 定义栈中元素的最大元素

typedef struct
{
    char data[MaxSize]; // 静态数组存放栈中元素
    int top;            // 栈顶指针
} SqStack;

// 初始化栈
void InitStack(SqStack &S);
// 判断栈是否为空
bool StackEmpty(SqStack S);
// 新元素入栈
bool Push(SqStack &S, char x);
// 栈顶元素出栈,用x返回
bool Pop(SqStack &S, char &x);

bool bracketCheck(char str[], int length)
{
    SqStack S;
    InitStack(S);
    for (int i = 0; i < length; i++)
    {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{')
        {
            Push(S, str[i]); // 扫描到左括号, 入栈
        }
        else
        {
            if (StackEmpty(S))
                return false;
            char topElem;
            Pop(S, topElem); // 栈顶元素出栈
            if (str[i] == ')' && topElem != '(')
                return false;
            if (str[i] == ']' && topElem != '[')
                return false;
            if (str[i] == '}' && topElem != '{')
                return false;
        }
    }
    return StackEmpty(S);
}
