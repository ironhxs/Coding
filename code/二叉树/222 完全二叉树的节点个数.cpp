// 完全二叉树的节点个数
// 关键点: 利用完全二叉树性质，判断是否为满二叉树可直接计算
// 易错点: 左右深度相等说明左子树是满二叉树
// 日期: 2026.02.07

#include <cmath>
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
    int countNodes(TreeNode* root) {
        if(!root)
            return 0;
        auto left = root->left;
        auto right = root->right;
        int leftDepth = 0;
        int rightDepth = 0;
        while(left){
            left = left->left;
            leftDepth++;
        }
        while(right){
            right = right->right;
            rightDepth++;
        }
        if(leftDepth == rightDepth)
            return pow(2,leftDepth+1) - 1;
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};
