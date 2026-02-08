// 删除二叉搜索树中的节点
// 关键点: 找到节点后分情况处理（叶子/单子树/双子树）
// 易错点: 双子树时用左子树最大值或右子树最小值替换
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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root)
            return root;
        if(root->val == key){
            if(root->left && !root->right){
                auto temp = root;
                root = root->left;
                delete temp;
            }
            else if(!root->left && root->right){
                auto temp = root;
                root = root->right;
                delete temp;
            }
            else if(root->left && root->right){
                auto pre = root->left;
                auto last = pre->right;
                if(last){
                    while(last->right){
                        pre = last;
                        last = last->right;
                    }
                    root->val = last->val;
                    last = last->left;
                    pre->right = last;
                }
                else{
                    last = pre;
                    root->val = last->val;
                    root->left = last->left;
                    delete last;
                    last = nullptr;
                }
            }
            else{
                delete root;
                root = nullptr;
            }
        }
        else if(root->val < key)
            root->right = deleteNode(root->right,key);
        else 
            root->left = deleteNode(root->left,key);
        return root;        
    }
};
