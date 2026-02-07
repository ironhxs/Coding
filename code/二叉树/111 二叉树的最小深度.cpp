// 二叉树的最小深度
// 关键点: BFS 遇到叶子节点立即返回；DFS 递归求最小
// 易错点: 最小深度是到叶子节点的最短路径，不是到空节点
// 日期: 2026.02.07

#include <queue>
#include <climits>
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

// BFS 写法（注释保留）
// class Solution {
// public:
//     int minDepth(TreeNode* root) {
//         int layer = 0;
//         if(!root)
//             return layer;
//         queue<TreeNode*> que;
//         que.push(root);
//         while(!que.empty()){
//             int n = que.size();
//             layer++;
//             for(int i = 0;i <= n - 1;i++){
//                 auto node = que.front();
//                 que.pop();
//                 if(!node->left && !node->right)
//                     return layer;
//                 if(node->left)
//                     que.push(node->left);
//                 if(node->right)
//                     que.push(node->right);
//             }
//         }
//         return layer;
//     }
// };

// DFS 递归写法
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(!root)
            return 0;
        int ret = INT_MAX;
        auto _minDepth = [&](auto&& self,TreeNode* node,int layer)->void{
            if(node){
                if(!node->left&&!node->right)
                    ret = min(layer,ret);
                self(self,node->left,layer+1);
                self(self,node->right,layer+1);
            }
        };
        int layer = 1;
        _minDepth(_minDepth,root,1);
        return ret;
    }
};
