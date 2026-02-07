// 平衡二叉树
// 关键点: 后序遍历求高度，同时判断左右子树高度差
// 易错点: 需要在递归中传递不平衡标志
// 日期: 2026.02.07

#include <cmath>
#include <algorithm>
using namespace std;

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
    bool isBalanced(TreeNode* root) {
        if(!root)
            return true;
        bool ret = true;
        auto _isBalanced = [&](auto && self,TreeNode* node) -> int{
            if(!node)
                return 0;
            int leftDepth = self(self,node -> left);
            int rightDepth = self(self,node -> right);
            if(abs(leftDepth - rightDepth) > 1)
                ret = false;
            return 1 + max(leftDepth,rightDepth);
        };
        _isBalanced(_isBalanced,root);
        return ret;
    }
};
