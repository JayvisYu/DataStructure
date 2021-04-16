#include <stdio.h>
#include <stdlib.h>

#define InitSize 10
typedef struct
{
    int *data;   //指示动态分配数组的指针
    int MaxSize; //顺序表的最大容量
    int length;  //顺序表当前的长度
} SqList;

//函数声明
bool InitList(SqList &L);                  //初始化
bool Empty(SqList L);                      //判空
bool Full(SqList L);                       //判满
void IncreaseSize(SqList &L, int len);     //动态扩展空间
bool ListInsert(SqList &L, int i, int e);  //插入
int GetElem(SqList L, int i);              //按位查找
int LocateElem(SqList L, int e);           //按值查找
bool ListDelete(SqList &L, int i, int &e); //删除
void DestroySqList(SqList &L);             //销毁

//初始化
bool InitList(SqList &L)
{
    //用 malloc 函数申请一片连续的存储空间
    L.data = (int *)malloc(InitSize * sizeof(int));
    if (L.data == NULL)
        //要细心呀，这里不小心写成了赋值语句，但是没有报错，找了半天错误！
        return false;
    //(int *) 是指针的强制类型转换
    L.length = 0;
    L.MaxSize = InitSize;
    return true;
}

//判空
bool Empty(SqList L)
{
    return (L.length == 0);
}

//判满
bool Full(SqList L)
{
    return (L.length >= L.MaxSize);
}

//扩展空间
void IncreaseSize(SqList &L, int len)
{
    printf("开始扩展表存储空间。。。\n");
    int *p = L.data;
    L.data = (int *)malloc((InitSize + len) * sizeof(int));
    printf("开始复制转移数据。。。\n");
    for (int i = 0; i < L.length; i++)
    {
        L.data[i] = p[i];
    }
    printf("之前内存空间的长度是：%d\n", L.MaxSize);
    L.MaxSize = L.MaxSize + len;
    free(p);
    //malloc 函数用于申请内存空间；free 函数用于释放内存空间；
    printf("现在的内存空间长度是%d\n", L.MaxSize);
}

//插入
bool ListInsert(SqList &L, int i, int e)
{
    //判断插入的位置是否合法，
    if (i < 1 || i > L.length + 1)
        return false;
    if (Full(L))
        return false;

    //后面的元素后移
    for (int j = L.length; j >= i; j--)
    {
        L.data[j] = L.data[j - 1];
    }
    L.data[i - 1] = e;
    L.length++;
    return true;
}

//按位查找
int GetElem(SqList L, int i)
{
    //判断是否越界
    if (i < 1 || i > L.length)
        return -1;
    return L.data[i - 1]; // O(1)
}

//按值查找
int LocateElem(SqList L, int e)
{
    //循环出查找
    for (int i = 0; i < L.length; i++)
    {
        if (L.data[i] == e)
            return i + 1; //返回位序 O(n)
    }
    return -1;
}

//删除
bool ListDelete(SqList &L, int i, int &e)
{
    //判断i的位置是否合法
    if (i < 1 || i > L.length)
    {
        return false;
    }
    //取出将要被删除的数
    e = L.data[i - 1];
    //将其后的数据前移
    for (int j = i; j <= L.length; j++)
    {
        L.data[j - 1] = L.data[j];
    }
    //线性表长度减一
    L.length--;
    return true;
}

//销毁
//由于动态分配方式使用malloc申请的内存空间，故需要使用free函数手动释放空间！
void DestroySqList(SqList &L)
{
    free(L.data);
    L.data = NULL;
    L.length = 0;
}
