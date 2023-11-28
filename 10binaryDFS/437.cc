#include <algorithm>
#include <cstdint>
#include <iostream>
#include "include/treenode.h"

class Solution
{

private:
    int ans = 0;

public:
    int pathSum(TreeNode *root, int targetSum)
    {
        if (!root)
            return 0;
        dfs(root, targetSum);
        pathSum(root->left, targetSum);
        pathSum(root->right, targetSum);
        return ans;
    }
    void dfs(TreeNode *root, long targetSum)
    {
        targetSum -= root->val;
        if (targetSum == 0)
            ans++;
        if (!root->left && !root->right)
            return;

        if (root->left)
            dfs(root->left, targetSum);
        if (root->right)
            dfs(root->right, targetSum);
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
    int maxDepth = ss.pathSum(root, 4);
    std::cout << maxDepth << std::endl;
    // 释放内存
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;

    return 0;
}