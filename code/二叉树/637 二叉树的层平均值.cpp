// 二叉树的层平均值
// 关键点: 层序遍历，累加每层节点值求平均
// 易错点: 注意整型溢出，使用 double
// 日期: 2026.02.06

#include <vector>
#include <queue>
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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ret;
        if(!root)
            return ret;
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()){
            int n = que.size();
            double _sum = 0;
            for(int i = 0;i <= n - 1;i++){
                TreeNode* node = que.front();
                que.pop();
                _sum += node->val;
                if(node->left)
                    que.push(node->left);
                if(node->right)
                    que.push(node->right);
            }
            _sum /= (double)n;
            ret.push_back(_sum);
        }
        return ret;
    }
};
