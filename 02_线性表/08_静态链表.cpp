#include <stdlib.h>
#include <stdlib.h>

#define MaxSize 10

//第一种定义方法
struct Node1
{
    int data;
    int next;
};

//第二种定义方法
typedef struct Node2
{
    int data;
    int next;
} SLinkList[MaxSize];
//相比之下，第二种方法可读性更强！，推荐

//函数声明
void TestSLinkList1();
void TestSLinkList2();

void TestSLinkList1()
{
    //第一种方法声明
    struct Node1 a[MaxSize];
}

void TestSLinkList2()
{
    //第二种方法声明
    SLinkList a;
}
