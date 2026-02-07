// 路径总和
// 关键点: 前序遍历累加路径和，到叶子节点时判断
// 易错点: 必须到叶子节点才判断，不能中途返回
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
    bool hasPathSum(TreeNode* root, int targetSum) {
        bool ret = false;
        auto _hasPathSum = [&](auto&& self,TreeNode* node,int _sum){
            if(!node)
                return;
            _sum += node->val;
            if(!node->left&&!node->right){
                if(_sum == targetSum)
                    ret = true;
                return ;
            }
            self(self,node->left,_sum);
            self(self,node->right,_sum);
        };
        _hasPathSum(_hasPathSum,root,0);
        return ret;
    }
};
