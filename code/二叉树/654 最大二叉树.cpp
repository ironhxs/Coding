// 最大二叉树
// 关键点: 找最大值作为根，递归构建左右子树
// 易错点: 空数组返回 nullptr，单元素直接返回
// 日期: 2026.02.08

#include <vector>
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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if(nums.empty())
            return nullptr;
        auto m = max_element(nums.begin(),nums.end());
        TreeNode* root = new TreeNode(*m);
        if(nums.size() == 1)
            return root;
        vector<int> left(nums.begin(),m);
        vector<int> right(m + 1,nums.end());
        root->left = constructMaximumBinaryTree(left);
        root->right = constructMaximumBinaryTree(right);
        return root;
    }
};
