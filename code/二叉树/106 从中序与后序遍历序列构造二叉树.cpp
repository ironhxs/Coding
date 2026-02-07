// 从中序与后序遍历序列构造二叉树
// 关键点: 后序最后一个为根，在中序中找根分割左右子树
// 易错点: 分割区间要对应，左子树长度要一致
// 日期: 2026.02.07

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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        auto _buildTree = [&](auto &&self,vector<int>& inorder, vector<int>& postorder)->TreeNode*{
            if(postorder.empty())
                return nullptr;
            TreeNode* root = new TreeNode(postorder.back());
            postorder.pop_back();
            if(postorder.empty())
                return root;
            vector<int> left1(inorder.begin(),find(inorder.begin(),inorder.end(),root->val));
            vector<int> left2(postorder.begin(),postorder.begin() + left1.size());
            root->left = self(self,left1,left2);
            vector<int> right1(find(inorder.begin(),inorder.end(),root->val) + 1,inorder.end());
            vector<int> right2(postorder.begin() + left1.size(),postorder.end());
            root->right = self(self,right1,right2);
            return root;
        };
        return _buildTree(_buildTree,inorder,postorder);
    }
};
