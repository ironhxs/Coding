// 二叉树的中序遍历（统一迭代法）
// 关键点: 栈 + nullptr 标记法，入栈顺序：右-中-nullptr-左
// 易错点: 遇到 nullptr 时取下一个节点处理
// 日期: 2026.02.06

#include <vector>
#include <stack>
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

// 递归写法（注释保留）
// class Solution {
// public:
//     vector<int> inorderTraversal(TreeNode* root) {
//         vector<int> ret;
//         auto _inorderTraversal = [&](auto && self,TreeNode* root)->void{
//             if(root){
//                 self(self,root->left);
//                 ret.push_back(root->val);
//                 self(self,root->right);
//             }
//         };
//         _inorderTraversal(_inorderTraversal,root);
//         return ret; 
//     }
// };

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;
        if(!root)
            return ret;
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()){
            auto node = st.top();
            st.pop();
            if(node){
                if(node->right)
                    st.push(node->right);
                st.push(node);
                st.push(nullptr);
                if(node->left)
                    st.push(node->left);
            }
            else{
                node = st.top();
                st.pop();
                ret.push_back(node->val);
            }
        }
        return ret; 
    }
};
