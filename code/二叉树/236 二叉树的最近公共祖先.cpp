// 二叉树的最近公共祖先
// 关键点: 后序遍历，返回是否包含 p/q，第一个同时包含的节点即为 LCA
// 易错点: 找到后不再更新 ret
// 日期: 2026.02.08

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
    struct result{
        bool pb ;
        bool qb ;
        result(bool p = false,bool q = false):pb(p),qb(q){}
    };
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ret = nullptr;
        auto _lowestCommonAncestor = [&](auto && self,TreeNode* node)->result{
            if(!node)
                return result();
            result left = self(self,node->left);
            result right = self(self,node->right);
            result r;
            if(left.pb||right.pb||node->val == p->val)
                r.pb = true;
            if(left.qb||right.qb||node->val == q->val)
                r.qb = true;
            if(!ret &&r.pb&&r.qb)
                ret = node;
            return r;
        };
        _lowestCommonAncestor(_lowestCommonAncestor,root);
        return ret;
    }
};
