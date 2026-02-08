// 二叉搜索树中的众数
// 关键点: 中序遍历统计频次，动态更新最大频次和结果
// 易错点: 频次相等时追加，频次更大时清空重置
// 日期: 2026.02.08

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
    
    vector<int> findMode(TreeNode* root) {
        int max_cnt = 0;
        int cnt = 0;
        TreeNode* pre = nullptr;
        vector<int> ret; 
        auto _findMode = [&](auto&& self,TreeNode* root){
            if(!root)
                return;
            self(self,root->left);
            if(pre && root->val == pre->val)
                cnt++;
            else 
                cnt = 1;
            pre = root;
            if(cnt == max_cnt)
                ret.push_back(root->val);
            else if(cnt > max_cnt){
                max_cnt = cnt;
                ret.clear();
                ret.push_back(root->val);
            }
            self(self,root->right);
        };
        _findMode(_findMode,root);
        return ret;
    }
};
