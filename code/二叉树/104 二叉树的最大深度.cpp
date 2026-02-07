// 二叉树的最大深度
// 关键点: 递归，深度 = 1 + max(左子树深度, 右子树深度)
// 易错点: 空节点返回 0
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
    int maxDepth(TreeNode* root) {
        if(!root)
            return 0;
        return 1 + max(maxDepth(root->left),maxDepth(root->right));
    }
};
