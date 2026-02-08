// 二叉搜索树的最小绝对差
// 关键点: 中序遍历有序，相邻节点差值最小
// 易错点: pre 为空时返回 INT_MAX
// 日期: 2026.02.08

#include <climits>
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
    TreeNode* pre = nullptr;
    int getMinimumDifference(TreeNode* root) {
        if(!root)
            return INT_MAX;
        int left = getMinimumDifference(root -> left);
        int temp = pre?abs(root->val - pre->val):INT_MAX;
        pre = root;
        int right = getMinimumDifference(root -> right);
        return min({left,right,temp});
    }
};
