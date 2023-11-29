#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#include "include/treenode.h"

class Solution
{
public:
    std::vector<int> righsideView(TreeNode *root)
    {
        std::vector<int> result;
        if (!root)
            return result;
        std::queue<TreeNode *> que;
        que.push(root);
        while (!que.empty())
        {
            int size = que.size();
            // 遍历当前层的所有节点, 选择最右侧的节点
            for (int i = 0; i < size; i++)
            {
                TreeNode *current = que.front();
                que.pop();
                if (i == size - 1)
                    result.push_back(current->val);
                if (current->left)
                    que.push(current->left);
                if (current->right)
                    que.push(current->right);
            }
        }
        return result;
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