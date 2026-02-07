// 左叶子之和
// 关键点: 前序遍历，标记当前节点是否为左子节点
// 易错点: 左叶子 = 是左子节点 + 是叶子节点
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
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root)
            return 0;
        int ret = 0;
        auto _sumOfLeftLeaves = [&](auto&& self,TreeNode* node,bool isLeft){
            if(!node){
                return;
            }
            //为了标识不被其他影响，应当先序遍历
            if(isLeft&&!node->left&&!node->right)
                ret += node->val;
            self(self,node->left,true);
            self(self,node->right,false);
        };
        _sumOfLeftLeaves(_sumOfLeftLeaves,root,false);
        return ret;
    }
};
