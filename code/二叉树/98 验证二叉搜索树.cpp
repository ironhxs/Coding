// 验证二叉搜索树
// 关键点: 中序遍历应当严格递增，用 pre 记录前一个节点
// 易错点: 必须是严格小于，不能有等于
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
    TreeNode* pre = nullptr;
    bool isValidBST(TreeNode* root) {
        //中序遍历应当从小到大
        if(!root)
            return true;
        bool left = isValidBST(root->left);
        if(pre && pre->val >= root->val){
            return false;
        }
        pre = root;
        bool right = isValidBST(root->right);
        return left && right;
    }
};
