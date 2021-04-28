#include <stdio.h>

typedef struct
{                 // 查找表的数据结构(顺序表)
    int *elem;    // 动态数组基址
    int TableLen; // 表的长度
} SSTable;

// 顺序查找
int Search_Seq(SSTable ST, int key)
{
    int i;
    for (i = 0; i < ST.TableLen && ST.elem[i] != key; ++i)
        // 查找成功,则返回元素下标;查找失败,则返回-1
        return i == ST.TableLen ? -1 : i;
}

// 顺序查找(课本版本)
int Search_Seq(SSTable ST, int key)
{
    ST.elem[0] = key; // 哨兵
    int i;
    for (i = ST.TableLen; ST.elem[i] != key; --i) // 从后往前找
        // 查找成功,则返回元素下标;查找失败,则返回0
        return i;
}

// 执行效率
// 查找成功 ASL (n + 1) / 2
// 查找失败 ASL n + 1

// 顺序查找的优化 (排序/被查概率不相等)
