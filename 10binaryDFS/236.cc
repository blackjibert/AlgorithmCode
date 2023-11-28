#include <algorithm>
#include <unordered_map>
#include <iostream>
#include <queue>
#include <vector>
#include "include/treenode.h"

class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == q || root == p || !root)
            return root;
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);
        if (!left && !right)
            return nullptr;
        else if (!left)
            return right;
        else if (!right)
            return left;
        return root;
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
    TreeNode *commRoot = ss.lowestCommonAncestor(root, root->left, root->right);
    std::cout << commRoot->val << std::endl;
    // 释放内存
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;

    return 0;
}