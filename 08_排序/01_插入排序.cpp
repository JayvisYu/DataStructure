// 直接插入排序
void InsertSort(int A[], int n)
{
    int i, j, temp;
    for (i = 1; i < n; i++) // 将各元素插入已排好序的序列中
    {
        if (A[i] < A[i - 1]) // 若A[i]关键字小于前驱
        {
            temp = A[i];                                // 用temp暂存A[i]
            for (j = i - 1; j >= 0 && A[j] > temp; --j) // 检查所有前面已排好序的元素
                A[j + 1] = A[j];                        // 所有大于temp的元素都向后挪位
            A[j + 1] = temp;                            // 复制到插入位置
        }
    }
}

// 直接插入排序(带哨兵)
void InsertSort(int A[], int n)
{
    int i, j;
    for (i = 2; i <= n; i++)
    {
        if (A[i] < A[i + 1])
        {
            A[0] = A[j];
            for (j = i - 1; A[0] < A[j]; --j)
                A[j + 1] = A[j]; // 向后挪位
            A[j + 1] = A[0];     // 复制到插入位置
        }
    }
}

// 空间复杂度O(1)
// 时间复杂度 最好O(n) 最坏O(n^2)

// 折半插入排序
void InsertSort(int A[], int n)
{
    int i, j, low, high, mid;
    for (i = 2; i <= n; i++)
    {
        A[0] = A[i]; // 将A[i]暂存到A[0]
        low = 1;
        high = i - 1; // 设置折半查找范围
        while (low <= high)
        {
            mid = (low + high) / 2; // 取中间点
            if (A[mid] > A[0])
                high = mid - 1; // 查找左半子表
            else
                low = mid + 1; // 查找右半子表
        }
        for (j = i - 1; j >= high + 1; --j)
            A[j + 1] = A[j]; // 统一后移元素,空出插入位置
        A[high + 1] = A[0];  // 插入操作
    }
}
