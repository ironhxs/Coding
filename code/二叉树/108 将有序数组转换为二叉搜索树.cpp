// 将有序数组转换为二叉搜索树
// 关键点: 取中间元素为根，递归构建左右子树，保证平衡
// 易错点: 中间下标取法影响树的形态，但都合法
// 日期: 2026.02.11

#include <vector>
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        if(n < 1)
            return nullptr;
        int mid = n/2 + 1;
        TreeNode* root = new TreeNode(nums[mid - 1]);
        vector<int> left(nums.begin(),nums.begin() + mid - 1);
        root->left = sortedArrayToBST(left);
        vector<int> right(nums.begin() + mid,nums.end());
        root->right = sortedArrayToBST(right);
        return root;
    }
};
