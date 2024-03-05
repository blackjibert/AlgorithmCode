#ifndef TREENODE_H
#define TREENODE_H
#include <iostream>
// 二叉树节点的定义
struct TreeNode 
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr){};
    TreeNode(int value) : val(value), left(nullptr), right(nullptr) {};
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 递归构建二叉树
TreeNode* buildTree() {
    int val;
    std::cout << "Enter node value (or -1 for null): ";
    std::cin >> val;
    if (val == -1) {
        return nullptr; // 返回空指针表示空节点
    }
    TreeNode* root = new TreeNode(val);

    std::cout << "Enter left subtree for node " << val << ": ";
    root->left = buildTree(); // 递归构建左子树
    std::cout << "Enter right subtree for node " << val << ": ";
    root->right = buildTree(); // 递归构建右子树

    return root;
}
#endif // TREENODE_H