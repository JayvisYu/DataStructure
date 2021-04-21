#include <stdio.h>
#include <stdlib.h>

typedef struct StringNode
{
    char ch; // 每个结点存1个字符
    struct StingNode *next;
} StringNode, *String;

typedef struct StringNode
{
    char ch[4]; // 每个结点存多个字符
    struct StringNode *next;
} StringNode, *String;
