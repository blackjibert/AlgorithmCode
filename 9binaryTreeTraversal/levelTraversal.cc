#include <iostream>
#include <queue>
#include "include/treenode.h"

class Solution 
{
public:
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
    std::cout << "层次遍历结果：";
    Solution ss;
    ss.levelOrderTraversal(root);
    std::cout << std::endl;
 
    // 释放内存
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;

    return 0;
}