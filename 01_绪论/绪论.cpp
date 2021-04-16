// 数据的定义: 数据是信息的载体, 是描述客观事物属性的数、字符以及所有能够输入到计算机中并被计算机程序识别和处理的集合
// 数据元素是数据的基本单位, 由若干个数据项组成;
// 数据元素之间的关系叫做结构
// 数据对象是指具有相同性质的数据元素的集合
// 数据类型是值的集合和定义在此集合上一组操作的总称,包括原子类型、结构类型、抽象数据类型
// 数据结构是相互之间存在一种或多种特定关系的数据元素的集合
// 数据结构包括逻辑结构、存储(物理)结构、数据的运算
// 算法的设计取决于所选定的逻辑结构,算法的实现依赖于所采用的存储结构;

// 逻辑结构: 数据元素之间的逻辑关系, 从逻辑关系上描述数据, 叫做数据的逻辑结构, 与存储结构无关, 独立于计算机
// 可分为线性结构(一对一): 栈、队列、串、数组、广义表 非线性结构: 集合、树(一对多)、图(多对多)

// 存储结构:数据结构在计算机中的表示,包括元素的表示和关系的表示
// 顺序存储: 逻辑上相邻的元素在物理位置上也相邻的存储方式, 元素之间的关系由存储单元的邻接关系体现
// 优点: 1.可以实现随机存储 2.元素占用最少的存储空间
// 缺点: 1.只能使用相邻的一整块存储单元,依赖于物理结构相邻 2.容易产生外部碎片(还没有分配出去,但是由于大小
// 而无法分配给申请内存空间的新进程的内存空闲块)
// 链式存储:与顺序存储不同,链式存储不要求逻辑上相邻的元素在物理位置上也相邻,借助元素存储地址的指针表示元素之间的逻辑关系
// 优点:1.不会出现碎片现象 2.充分利用存储单元
// 缺点:1.除了存储元素外,还需要额外存储指针,会占用额外的存储空间 2.链式存储只能实现顺序存取,不能实现随机存取
// 索引存储:存放数据元素和元素关系的存储方式,在存储元素信息的同时,还需要建立附加的索引表,索引表每一项称为索引项,一般形式是<关键字,地址>
// 优点: 1.检索快
// 缺点: 1.增加了索引表,占用较多的存储空间(典型的空间换时间策略) 2.增加、删除数据时,需要对应修改索引表,花费更多时间
// 散列存储:根据元素的关键字直接通过散列函数计算出元素的存储地址
// 优点: 1.检索快,添加、删除元素结点操作快
// 缺点: 1.非常依赖于散列函数 2.会出现散列冲突(依赖散列函数,不好就容易出现散列冲突) 3.出现散列冲突时,解决冲突会增加时间和空间上的开销
// 数据的运算包括运算的定义、运算的实现

// 算法:是对特定问题求解步骤的一种描述 (有穷性/确定性/可行性/输入/输出)
// 算法设计要求:正确性/可读性/健壮性/效率与低存储量需求
// 算法效率的度量: 时间复杂度T(n)=O(f(n))空间复杂度S(n)=O(f(n))

#include <stdio.h>

/**实现模块**/

//下面四种函数的时间复杂度值得分析一二

//逐步递增型爱你
void LoveYou0(int n)
{
    int i = 1;
    while (i <= n)
    {
        printf("I love you %d \n", i);
        i++;
    }
    printf("I love you more than %d\n", n);
}

//嵌套循环型爱你
void loveYou1(int n)
{
    int i = 1;
    while (i <= n)
    {
        i++;
        printf("I love you %d\n", i);
        for (int j = 1; j < n; j++)
        {
            printf("I love you too\n");
        }
    }
    printf("I love you more than %d\n", n);
}

//指数递增型爱你
void loveYou2(int n)
{
    int i = 1;
    while (i <= n)
    {
        printf("I love you %d\n", i);
        i = i * 2;
    }
    printf("I love you more than %d\n ", n);
}

//搜索数字型爱你
void loveYou3(int flag[], int n)
{
    printf("I Am kim\n");
    for (int i = 0; i < n; i++)
    {
        //我觉这里应该是数组长度
        if (flag[i] == n)
        {
            printf("I love you %d\n", n);
            break; //找到之后就跳出循环
        }
    }
}

//递归型爱你
void loveYou4(int n)
{
    int a, b, c;
    if (n > 1)
    {
        loveYou4(n - 1);
    }
    printf("I love you %d\n", n);
} //递归调用会带来多余的内存开销

/**实现模块**/

/**测试模块**/

//测试函数
void testModule()
{
    LoveYou0(30);
    loveYou1(30);
    loveYou2(30);

    int array[5] = {2, 10, 100, 1000, 10000};
    //声明一个数组并初始化
    loveYou3(array, 10);
    loveYou4(4);
}

/**测试模块**/

int main()
{
    testModule();
    return 0;
}
