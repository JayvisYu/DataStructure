#include <stdio.h>
#include <stdlib.h>

#define MAXLEN 255 // 预定义最大串场为255

typedef struct
{
    char ch[MAXLEN]; // 每个分量存储一个字符
    int length;      // 串的实际长度
} SString;           // 静态数组实现

int Index(SString S, SString T)
{
    int k = 1;
    int i = k, j = 1;
    while (i <= S.length && i <= T.length)
    {
        if (S.ch[i] == T.ch[j])
        {
            ++i;
            ++j; // 继续比较后继子串
        }
        else
        {
            k++; // 检查下一个子串
            i = k;
            j = 1;
        }
    }
    if (j > T.length)
        return k;
    else
        return 0;
}

// 课本代码实现
int Index2(SString S, SString T)
{
    int i = 1, j = 1;
    while (i <= S.length && i <= T.length)
    {
        if (S.ch[i] == T.ch[j])
        {
            ++i;
            ++j; // 继续比较后继子串
        }
        else
        {
            i = i - j + 2;
            j = 1;
        }
    }
    if (j > T.length)
        return i - T.length;
    else
        return 0;
}
