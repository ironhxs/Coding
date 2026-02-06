// 二叉树的最小深度
// 关键点: 层序遍历，遇到叶子节点立即返回当前层数
// 易错点: 最小深度是到叶子节点的最短路径，不是到空节点
// 日期: 2026.02.06

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
    int minDepth(TreeNode* root) {
        int layer = 0;
        if(!root)
            return layer;
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()){
            int n = que.size();
            layer++;
            for(int i = 0;i <= n - 1;i++){
                auto node = que.front();
                que.pop();
                if(!node->left && !node->right)
                    return layer;
                if(node->left)
                    que.push(node->left);
                if(node->right)
                    que.push(node->right);
            }
        }
        return layer;
    }
};
