#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#include "include/treenode.h"

class Solution 
{
public:
   //递归收集叶值序列
   void collectLeaves(TreeNode* root, std::vector<int>& leaves)
   {
       if(!root) return;
       if(!root->left && !root->right)
       {
           leaves.push_back(root->val);
           return;
       }
        collectLeaves(root->left, leaves);
        collectLeaves(root->right, leaves);
   }

   bool leafSimilar(TreeNode* root1, TreeNode* root2)
   {
       std::vector<int> leaves1, leaves2;
       collectLeaves(root1, leaves1);
       collectLeaves(root2, leaves2);
       return leaves1 == leaves2;
   }
};

int main() 
{
     // 创建两棵二叉树
    TreeNode* root1 = new TreeNode(3);
    root1->left = new TreeNode(5);
    root1->right = new TreeNode(1);
    root1->left->left = new TreeNode(6);
    root1->left->right = new TreeNode(2);
    root1->right->left = new TreeNode(9);
    root1->right->right = new TreeNode(8);
    root1->left->right->left = new TreeNode(7);
    root1->left->right->right = new TreeNode(4);

    TreeNode* root2 = new TreeNode(3);
    root2->left = new TreeNode(5);
    root2->right = new TreeNode(1);
    root2->left->left = new TreeNode(6);
    root2->left->right = new TreeNode(7);
    root2->right->left = new TreeNode(4);
    root2->right->right = new TreeNode(2);
    root2->right->right->left = new TreeNode(9);
    root2->right->right->right = new TreeNode(8);
 
    Solution ss;
    bool maxDepth = ss.leafSimilar(root1, root2);
    std::cout<<maxDepth<<std::endl;
    
    // 释放内存
    
    return 0;
}