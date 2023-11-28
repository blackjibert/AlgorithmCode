#include <algorithm>
#include <cstdint>
#include <iostream>
#include <queue>
#include <vector>
#include "include/treenode.h"

class Solution
{
public:
    // 计算好节点的数目
    int goodNodes(TreeNode *root, int maxVal)
    {
        if (!root)
        {
            return 0;
        }
        int count = 0;
        // 如果当前节点的值大于等于路径上的最大值，就将其算作好节点
        if (root->val >= maxVal)
        {
            count++;
            maxVal = root->val;
        }

        // 递归遍历左右子树
        count += goodNodes(root->left, maxVal);
        count += goodNodes(root->right, maxVal);

        return count;
    }

    // 返回二叉树中好节点的数目
    int goodNodes(TreeNode *root)
    {
        return goodNodes(root, INT32_MIN);
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
    int maxDepth = ss.goodNodes(root);
    std::cout << maxDepth << std::endl;
    // 释放内存
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;

    return 0;
}