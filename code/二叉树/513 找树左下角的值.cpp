// 找树左下角的值
// 关键点: 层序遍历，记录每层第一个节点值
// 易错点: 最后一层的第一个节点即为左下角
// 日期: 2026.02.07

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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> que;
        que.push(root);
        int ret = 0;
        while(!que.empty()){
            int n = que.size();
            for(int i = 0;i <= n - 1;i++){
                    auto node = que.front();
                    que.pop();
                    if(i==0)
                        ret = node->val;
                    if(node->left)
                        que.push(node->left);
                    if(node->right)
                        que.push(node->right);
                    }
            }
        return ret;
    }
};
