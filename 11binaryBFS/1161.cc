#include <algorithm>
#include <cstdint>
#include <iostream>
#include <queue>
#include <vector>
#include "include/treenode.h"

class Solution
{

    int maxLevelSum(TreeNode *root)
    {
        if (!root)
        {
            return 0;
        }
        int ans = INT16_MIN;
        int minLevel = 1;       // 存储结果的层号，默认为第一层
        int maxSum = INT16_MIN; // 存储层内元素之和的最大值

        std::queue<TreeNode *> que;
        que.push(root);
        int level = 0; // 当前层号

        while (!que.empty())
        {
            level++;
            int size = que.size();
            int sum = 0;
            // 计算当前层的元素之和
            for (int i = 0; i < size; i++)
            {
                TreeNode *current = que.front();
                que.pop();
                sum += current->val;
                if (current->left)
                    que.push(current->left);
                if (current->right)
                    que.push(current->right);
            }
            if (sum > maxSum)
            {
                maxSum = sum;
                minLevel = level;
            }
        }
        return minLevel;
    }
};

int main()
{
    // 创建二叉树
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution ss;
    std::vector<int> vals = ss.righsideView(root);
    for (int val : vals)
        std::cout << val << " "; // 1 3 5
    // 释放内存
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;

    return 0;
}