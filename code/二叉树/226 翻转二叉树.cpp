// 翻转二叉树
// 关键点: 前序或后序遍历交换左右子节点
// 易错点: 不可用中序遍历，交换后会处理两次原左子树
// 日期: 2026.02.07

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        //不可用中序遍历，因为遍历到父节点左右子树交换导致处理了两次原左子树
        if(!root)
            return nullptr;
        auto _invertTree = [&](auto&& self,TreeNode* node)->void{
            if(node){
                swap(node->left,node->right);
                self(self,node->left);
                self(self,node->right);
            }
        };
        _invertTree(_invertTree,root);
        return root;
    }
};
