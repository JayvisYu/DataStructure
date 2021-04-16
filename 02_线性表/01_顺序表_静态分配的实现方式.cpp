// 顺序表的静态存储
#include <stdio.h>

#define MaxSize 10

typedef struct
{
    int data[MaxSize];
    int length;
} SqList;

//函数声明
void InitList(SqList &L);                        //初始化
bool Empty(SqList L);                            //判空
bool ListInsert(SqList &L, int i, int e);        //插入
bool ListDelete(SqList &L, int i, int &e);       //删除
int GetElem(SqList L, int i);                    //按位查找
int LocateElem(SqList L, int e);                 //按值查找
bool getChangeElem(SqList &L, int i, int em);    //按位修改
bool LocateChangeElem(SqList &L, int e, int em); //按值修改

//初始化
void InitList(SqList &L)
{
    for (int i = 0; i < MaxSize; i++)
    {
        L.data[i] = 0; //将所有元素的初始值默认设置为0
        //这一步其实可以省略，但是省略之后，有可能受到内存中"脏数据"的影响
    }
    L.length = 0;
}

//判空
bool Empty(SqList L)
{
    return (L.length == 0);
}

//插入
bool ListInsert(SqList &L, int i, int e)
{
    //判断插入的位置是否合法，
    if (i < 1 || i > L.length + 1)
        return false;
    //判断表是否存满了
    if (L.length >= MaxSize)
        return false;

    //后面的元素后移
    for (int j = L.length; j >= i; j--)
    {
        L.data[j] = L.data[j - 1]; // 最坏O(n) 最好O(1) 平均O(n/2)->O(n)
    }
    L.data[i - 1] = e;
    L.length++;
    return true;
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
    for (int j = i; j < L.length; j++)
    {
        L.data[j - 1] = L.data[j]; // 最坏O(n) 最好O(1) 平均O(n/2)->O(n)
    }
    //线性表长度减一
    L.length--;
    return true;
}

//查找
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

//按位查找
int GetElem(SqList L, int i)
{
    //判断是否越界
    if (i < 1 || i > L.length)
        return -1;
    return L.data[i - 1]; // O(1)
}

//改
//先按值查找后改值
bool LocateChangeElem(SqList &L, int e, int em)
{
    //按值查找得到位序
    int bitOrder = LocateElem(L, e);
    //改值
    if (bitOrder != -1)
    {
        L.data[bitOrder - 1] = em;
        return true;
    }
    else
    {
        return false;
    }
}

//先按位序查找后改值
bool getChangeElem(SqList &L, int i, int em)
{
    //注意由于是改值涉及修改原数据，所以需要用引用传递的方式
    //给的位序,首先判断i是否合法
    if (i < 1 || i > L.length)
        return false;

    //由于是用数组实现的方式，可以直接利用i查找
    L.data[i - 1] = em;
    return true;
}

//销毁
//由于静态分配方式是通过声明数组的方式实现的，故不需要手动销毁SqList表，在使用完成之后，系统会自动删除数据并回收数据空间
