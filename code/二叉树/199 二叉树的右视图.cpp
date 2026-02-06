// 二叉树的右视图
// 关键点: 层序遍历，每层只取最后一个节点
// 易错点: DFS 无法准确判断最右节点
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
    //不用深度优先的原因是无法准确判断最右边这个，而且题目明显的层次性
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ret;
        if(!root)
            return ret;
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()){
            int n = que.size();
            for(int i = 0;i <= n - 1;i++){
                TreeNode* node = que.front();
                que.pop();
                if(i == n - 1)
                    ret.push_back(node->val);
                if(node->left)
                    que.push(node->left);
                if(node->right)
                    que.push(node->right);
            }
        }
        return ret;
    }
};
