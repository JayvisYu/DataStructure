#include <stdio.h>

typedef struct
{                 // 查找表的数据结构
    int *elem;    // 动态数组基址
    int TableLen; // 表的长度
} SSTable;

// 择半查找(升序)
// 仅适用于有序的顺序表
int Binary_Search(SSTable L, int key)
{
    int low = 0, high = L.TableLen - 1, mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (L.elem[mid] == key)
            return mid;
        else if (L.elem[mid] > key)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}
// 关键字对比 * 次数
// 查找成功 ASL=(1*1 + 2*2 + 3*4 + 4*4) / 11 =3 ASL < h
// 查找失败 ASL= (3*4 + 4*8)/12 = 11/3 

// 折半查找树
// 右子树结点树-左子树结点树 = 0或1
// 折半查找的判定树一定是平衡二叉树
// 折半查找的判定树中,只有最下面一层是不满的
// 因此,元素个数为n时树高h=[log2(n+1)]
// 判定结点关键字: 左<中<右,满足二叉树的定义
// 失败结点: n+1个 (等于成功结点的空链域数量)
