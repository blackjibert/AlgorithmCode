#include <algorithm>
#include <cstdint>
#include <iostream>
#include <ostream>
#include <queue>
#include <vector>
#include "include/treenode.h"

class Solution
{
public:
    // 递归法1:
    TreeNode *searchBST_recur(TreeNode *root, int val)
    {
        if (!root)
            return nullptr;
        if (root->val == val)
            return root;
        TreeNode *left_node = searchBST_recur(root->left, val);
        TreeNode *right_node = searchBST_recur(root->right, val);
        if (left_node)
            return left_node; // 在左子树中找到了目标节点，直接返回 left_node
        if (right_node)
            return right_node; // 在右子树中找到了目标节点，直接返回 right_node
        return nullptr;        // 都为空，表示在整个二叉搜索树中未找到目标节点，返回 nullptr。
    }
    // 迭代法2:
    TreeNode *searchBST_iter(TreeNode *root, int val)
    {
        while (root)
        {
            if (root->val > val)
                root = root->left;
            else if (root->val < val)
                root = root->right;
            else
                return root;
        }
        return nullptr;
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
    TreeNode *vals = ss.searchBST_iter(root, 3);
    std::cout << vals->val << std::endl;
    // 释放内存
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;

    return 0;
}