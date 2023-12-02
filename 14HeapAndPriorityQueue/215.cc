#include <iostream>
#include <queue>
#include <vector>

class Solution {
  public:
    int findKthLargest(std::vector<int>& nums, int k) {
        //使用最小堆, 堆顶为当前堆中最小的元素
        std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;

        //将前k个元素加入堆
        for (int i = 0; i < k; i++) {
            minHeap.push(nums[i]);
        }

        //遍历剩余的元素, 将大于堆顶的元素加入堆
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > minHeap.top()) {
                minHeap.pop();
                minHeap.push(nums[i]);
            }
        }
        // 堆顶即为第 k 个最大的元素
        return minHeap.top();
    }
};

int main() {
    Solution solution;

    // 示例用法
    std::vector<int> nums = {3, 2, 1, 5, 6, 4};
    int k = 2;

    int result = solution.findKthLargest(nums, k);

    // 输出结果
    std::cout << "The " << k << "th largest element is: " << result
              << std::endl;

    return 0;
}
