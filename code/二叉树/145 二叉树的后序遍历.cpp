// 二叉树的后序遍历（统一迭代法）
// 关键点: 栈 + nullptr 标记法，入栈顺序：中-nullptr-右-左
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
//     vector<int> postorderTraversal(TreeNode* root) {
//         vector<int> ret;
//         auto _postorderTraversal = [&](auto&& self,TreeNode* root)->void{
//             if(root){
//                 self(self,root->left);
//                 self(self,root->right);
//                 ret.push_back(root->val);
//             }
//         };
//         _postorderTraversal(_postorderTraversal,root);
//         return ret;
//     }
// };

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ret;
        if(!root)   
            return ret;
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()){
            auto node = st.top();
            st.pop();
            if(node){
                st.push(node);
                st.push(nullptr);
                if(node->right) 
                    st.push(node->right);
                if(node -> left)
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
