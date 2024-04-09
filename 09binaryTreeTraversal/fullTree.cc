//递归判断是否是满二叉树
#include <iostream>
#include <queue>
#include "include/treenode.h"
using namespace std;

bool isFull(TreeNode* root) {
    // 如果根节点为空，则是满二叉树
    if (root == nullptr) {
        return true;
    }

    // 如果左右子节点都为空，则是叶子节点，是满二叉树
    if (root->left == nullptr && root->right == nullptr) {
        return true;
    }

    // 如果左右子节点都不为空，则递归判断左右子树是否为满二叉树
    if (root->left != nullptr && root->right != nullptr) {
        return isFull(root->left) && isFull(root->right);
    }
    // 如果左右子节点一个为空一个不为空，则不是满二叉树
    return false;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    // root->right = new TreeNode(3);
    cout << "Is the binary tree full? " << std::boolalpha << isFull(root) << std::endl;
    return 0;
}
