// 交换
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

// 冒泡排序
void BubbleSort(int A[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        bool flag = false; // 表示本趟冒泡是否发生交换的标志
        for (int j = n - 1; j > i; j--)
            if (A[j - 1] > A[j])
            {
                swap(A[j - 1], A[j]); // 交换
                flag = true;
            }
        if (flag == false)
            return; // 本趟遍历后没有发生交换,说明表已经有序
    }
}

// 算法性能
// 最好O(n) 最坏O(n^2) 平均O(n^2)
