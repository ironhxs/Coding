// 二叉搜索树中的插入操作
// 关键点: 根据 BST 性质找到空位置插入
// 易错点: 空树直接返回新节点
// 日期: 2026.02.08

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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* ret;
        if(!root){
            ret = new TreeNode(val);
             return ret;
        }
        auto _insertIntoBST = [&](auto&& self,TreeNode* node)->void{
            if(node->val > val){
                if(node -> left)
                    self(self,node->left);
                else
                    node->left = new TreeNode(val);
            }
            if(node->val < val){
                if(node->right)
                    self(self,node->right);
                else
                    node->right = new TreeNode(val);
            }
        };
        _insertIntoBST(_insertIntoBST,root);
        return root;
    }
};
