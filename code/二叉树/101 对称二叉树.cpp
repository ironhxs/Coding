// 对称二叉树
// 关键点: 层序遍历检查每层回文，或递归比较镜像位置
// 易错点: 空节点需用特殊值标记
// 日期: 2026.02.07

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
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*> que;
        que.push(root);
        vector<int> v;
        while(!que.empty()){
            v = {};
            int n = que.size();
            for(int i = 0;i <= n - 1;i++){
                auto node = que.front();
                que.pop();
                if(node){
                    v.push_back(node->val);
                    que.push(node->left);
                    que.push(node->right);
                }
                //空节点赋假值，注意要用不可能出现的值
                else
                    v.push_back(-1000);
            }
            auto temp = v;
            reverse(v.begin(),v.end());
            if(temp != v)
                return false;
        }
        return true;
    }
};
