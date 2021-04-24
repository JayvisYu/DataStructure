#include <stdio.h>
#include <stdlib.h>

#define MAXLEN 255 // 预定义最大串场为255

typedef struct
{
    char ch[MAXLEN]; // 每个分量存储一个字符
    int length;      // 串的实际长度
} SString;           // 静态数组实现

// 求模式串T的next数组
void get_next(SString T, int next[])
{
    int i = 1, j = 0;
    next[1] = 0;
    while (i < T.length)
    {
        if (j == 0 || T.ch[i] == T.ch[j])
        {
            ++i;
            ++j;
            // 若pi=pj,则next[j+1]=next[j]+1
            next[i] = j;
        }
        else
        {
            // 否则令j=next[j],循环继续
            j = next[j];
        }
    }
}

// KMP算法
int Index_KMP(SString S, SString T)
{
    int i = 1, j = 1;
    int next[T.length + 1];
    get_next(T, next);
    while (i <= S.length && j <= T.length)
    {
        if (j == 0 || S.ch[i] == T.ch[j])
        {
            ++i;
            ++j;
        }
        else
            j = next[j];
    }
    if (j > T.length)
        return i - T.length;
    else
        return 0;
}

// KMP算法平均时间复杂度: O(n+m)
