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
    TreeNode* deleteNode(TreeNode* root, int key)
    {
        //第1种情况:没找到删除的节点, 遍历到空节点直接返回
        if(!root) return root;
        if(root->val == key) 
        {
            // 第2种情况: 左右节点都为空(叶子节点), 直接删除节点, 返回NULL为根节点
            if(!root->left && !root->right)
            {
                delete root;
                return nullptr;
            }
            // 第3种情况: 其左节点为空,  右节点不为空, 删除节点, 右节点补位, 返回右节点为根节点
            else if(!root->left && root->right)
            {
                TreeNode* retNode = root->right;
                delete root;
                return retNode;
            }
            // 第4种情况: 其右节点为空, 左节点不为空, 删除节点, 左节点补位, 返回左节点为根节点
            else if(!root->right && root->left)
            {
                TreeNode* retNode = root->left;
                delete root;
                return retNode;
            }
            // 第5种情况：左右节点都不为空, 则将删除节点的左节点放到删除节点的右节点的最左面节点的左节点的位置
            // 并返回删除节点, 右节点为新的根节点。
            else 
            {
                TreeNode* cur = root->right;
                while (cur->left) 
                {
                    cur=cur->left;
                }
                cur->left = root->left;
                TreeNode* tmp = root;
                root=root->right;
                delete tmp;
                return root;
            }
        }
        if(root->val > key) root->left = deleteNode(root->left, key);
        if(root->val < key) root->right = deleteNode(root->right, key);
        return root;
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
    TreeNode* vals = ss.searchBST_iter(root, 3);
    std::cout<<vals->val<<std::endl;
    // 释放内存
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;

    return 0;
}