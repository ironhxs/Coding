// 修剪二叉搜索树
// 关键点: 当前节点值小于 low 则结果在右子树，大于 high 则结果在左子树
// 易错点: 不能直接丢弃整棵子树，修剪后的子树中可能有合法节点
// 日期: 2026.02.11

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
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if(!root)
            return root;
        if(root->val < low){
            root->right = trimBST(root->right,low,high);
            root = root->right;
        }
        else if(root->val > high){
            root->left = trimBST(root->left,low,high);
            root = root->left;
        }
        else{
            root->left = trimBST(root->left,low,high);
            root->right = trimBST(root->right,low,high);
        }
        return root;
    }
};
