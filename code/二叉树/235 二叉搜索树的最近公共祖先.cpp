// 二叉搜索树的最近公共祖先
// 关键点: 利用 BST 性质，p/q 分居两侧时当前节点即为 LCA
// 易错点: 先确保 p < q 简化判断
// 日期: 2026.02.08

#include <algorithm>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* ret = nullptr;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(q->val < p->val )
            swap(q,p);
        if(!root)
            return nullptr;
        if(root->val < p -> val)
            return lowestCommonAncestor(root->right,p,q);
        else if(root->val > q -> val)
            return lowestCommonAncestor(root->left,p,q);
        else
            return root;
    }
};
