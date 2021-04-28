// 快速排序
void QuickSort(int A[], int low, int high)
{
    if (low < high)
    {                                           // 递归跳出的条件
        int pivotpos = Partition(A, low, high); // 划分
        QuickSort(A, low, pivotpos - 1);        // 划分左子表
        QuickSort(A, pivotpos + 1, high);       // 划分右子表
    }
}

// 用第一个元素将待排序序列分成左右两个部分
int Partition(int A[], int low, int high)
{
    int pivot = A[low];
    while (low < high)
    {
        while (low < high && A[high] >= pivot)
            --high;
        A[low] = A[high];
        while (low < high && A[low] <= pivot)
            ++low;
        A[high] = A[low];
    }
    A[low] = pivot;
    return low;
}

// 算法分析
// 时间复杂度 最好 O(nlog2n) 平均O(nlog2n) 最坏 O(n^2)
