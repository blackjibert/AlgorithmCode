#include <algorithm>
#include <iostream>
#include <queue>
#include "include/treenode.h"

class Solution
{
public:
    // 递归方法
    int maxDepthRecursion(TreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        return std::max(maxDepthRecursion(root->left), maxDepthRecursion(root->right)) + 1;
    }
    // 非递归实现, 每一层进行遍历
    int maxDepth(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        int num = 0;
        std::queue<TreeNode *> que;
        que.push(root);
        while (!que.empty())
        {
            int n = que.size();
            for (int i = 0; i < n; i++)
            {
                TreeNode *curr = que.front();
                if (curr->left)
                    que.push(curr->left);
                if (curr->right)
                    que.push(curr->right);
                que.pop();
            }
            num++;
        }
        return num;
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
    int maxDepth = ss.maxDepthRecursion(root);
    std::cout << maxDepth << std::endl;
    // 释放内存
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;

    return 0;
}