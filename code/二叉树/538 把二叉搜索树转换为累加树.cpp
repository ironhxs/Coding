// 把二叉搜索树转换为累加树
// 关键点: 反中序遍历（右-中-左），累加和赋值给当前节点
// 易错点: 先遍历右子树再处理当前节点
// 日期: 2026.02.11

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
    TreeNode* convertBST(TreeNode* root) {
        if(!root)
            return root;
        int asum = 0;
        auto _convertBST = [&](auto &&self,TreeNode* node)->void{
            if(!node)
                return;
            self(self,node->right);
            node->val += asum;
            asum  = node->val; 
            self(self,node->left);
        };
        _convertBST(_convertBST,root);
        return root;
    }
};
