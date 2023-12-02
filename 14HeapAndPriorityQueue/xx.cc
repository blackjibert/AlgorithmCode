#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

class Solution
{
public:
    // 最大堆的调整函数
    void maxHeapify(std::vector<int> &arr, int n, int i)
    {
        int largest = i;       // 初始化最大值的位置
        int left = 2 * i + 1;  // 左子节点的位置
        int right = 2 * i + 2; // 右子节点的位置

        // 比较左子节点和根节点的值
        if (left < n && arr[left] > arr[largest])
        {
            largest = left;
        }
        // 比较右子节点和根节点的值
        if (right < n && arr[right] > arr[largest])
        {
            largest = right;
        }
        // 如果最大值的位置不是根节点，则交换根节点和最大值位置的元素
        if (largest != i)
        {
            std::swap(arr[i], arr[largest]);

            // 递归调整交换后的子树
            maxHeapify(arr, n, largest);
        }
    }
    // 堆排序
    void heapSort(std::vector<int> &arr)
    {
        int n = arr.size();
        // 构建最大堆
        for (int i = n / 2 - 1; i >= 0; i--)
        {
            maxHeapify(arr, n, i);
        }

        // 从堆中提取元素
        for (int i = n - 1; i > 0; i--)
        {
            std::swap(arr[0], arr[i]); // 将最大值（堆顶）放到数组末尾
            maxHeapify(arr, i, 0);     // 调整剩余堆
        }
    }
};

int main()
{
    Solution ss;

    std::vector<int> arr = {12, 11, 13, 5, 6, 7};

    std::cout << "Original array: ";
    for (int num : arr)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // 堆排序
    ss.heapSort(arr);

    std::cout << "Sorted array: ";
    for (int num : arr)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
