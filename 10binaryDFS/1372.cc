#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#include "include/treenode.h"

class Solution 
{
    private: 
        int maxZigZag = 0;
    public:
        int longestZigZag(TreeNode* root)
        {
            dfs(root, true);
            return maxZigZag;
        }
        int dfs(TreeNode* root, bool isleft)
        {
            if(root == nullptr) return 0;
            int r = dfs(root->right, false);
            int l = dfs(root->left, true);
            int big = l>r ?l:r;
            if(big>maxZigZag) maxZigZag=big;
            if(isleft) return r+1;
            else return l+1;
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
    
    Solution ss;
    int maxZigZag = ss.longestZigZag(root);
    std::cout<<maxZigZag<<std::endl;
    // 释放内存
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;

    return 0;
}