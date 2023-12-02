#include <iostream>
#include <queue>
#include "include/treenode.h"
class Solution 
{
public:
    // 层次遍历函数
    void levelOrderTraversal(TreeNode* root)
    {
        if(root == nullptr) return;
        std::queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* curr = q.front();
            q.pop();
            std::cout<< curr->val<< " ";
            if (curr->left ) q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }
    }

    // 前序遍历函数
    void preorderTraversal(TreeNode* root) 
    {
        if (root == nullptr) return;
        std::cout << root->val << " ";  // 输出当前节点的值
        preorderTraversal(root->left);  // 递归遍历左子树
        preorderTraversal(root->right);  // 递归遍历右子树
    }

    // 后序遍历函数
    void postorderTraversal(TreeNode* root) 
    {
        if (root == nullptr) return;
        postorderTraversal(root->left);  // 递归遍历左子树
        postorderTraversal(root->right);  // 递归遍历右子树
        std::cout << root->val << " ";  // 输出当前节点的值
    }


    // 中序遍历函数
    void inorderTraversal(TreeNode* root) 
    {
        if (root == nullptr) return; 
        inorderTraversal(root->left);  // 递归遍历左子树
        std::cout << root->val << " ";  // 输出当前节点的值
        inorderTraversal(root->right);  // 递归遍历右子树
    }

};

int main() 
{
    // 创建二叉树
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
 
    // 层次遍历二叉树
    
    Solution ss;
    std::cout << "层次遍历结果：";
    ss.levelOrderTraversal(root);
    std::cout << std::endl;

    std::cout << "前序遍历结果: ";
    ss.preorderTraversal(root);
    std::cout << std::endl;

    std::cout << "后序遍历结果: ";
    ss.postorderTraversal(root);
    std::cout << std::endl;

    std::cout << "中序遍历结果: ";
    ss.inorderTraversal(root);
    std::cout << std::endl;
    // 释放内存
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;

    return 0;
}