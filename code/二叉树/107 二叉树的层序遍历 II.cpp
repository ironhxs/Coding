// 二叉树的层序遍历 II（自底向上）
// 关键点: 层序遍历后 reverse 结果
// 易错点: 也可用栈暂存每层结果
// 日期: 2026.02.06

#include <vector>
#include <queue>
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ret;
        if(!root){
            return ret;
        }
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()){
            int n = que.size();
            vector<int> v;
            for(int i = 0;i <= n - 1;i++){
                TreeNode* node = que.front();
                que.pop();
                v.push_back(node->val);
                if(node -> left) 
                    que.push(node->left);
                if(node -> right)
                    que.push(node->right);
            }
            ret.push_back(v);
        }
        reverse(ret.begin(),ret.end());
        return ret;
    }
};
