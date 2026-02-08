// 二叉搜索树中的搜索
// 关键点: 利用 BST 性质，比较后选择左右子树递归
// 易错点: 空节点返回 nullptr
// 日期: 2026.02.08

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
    TreeNode* searchBST(TreeNode* root, int val) {
        if(!root)
            return nullptr;
        if(root->val == val)
            return root;
        else if(root->val > val)
            return searchBST(root->left, val);
        else   
            return searchBST(root->right, val);
    }
};
