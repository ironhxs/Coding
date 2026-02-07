// 二叉树的所有路径
// 关键点: 前序遍历 + 路径回溯，到叶子节点时记录路径
// 易错点: 路径字符串拼接格式 "->"
// 日期: 2026.02.07

#include <vector>
#include <string>
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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ret;
        auto _binaryTreePaths = [&](auto && self,TreeNode* node,string path)->void{
            if(!node){
                return;
            }
            if(!node->left&&!node->right){
                path += to_string(node->val);
                ret.push_back(path);
            }
            path+=(to_string(node->val)+"->");
            self(self,node->left,path);
            self(self,node->right,path);            
        };
        _binaryTreePaths(_binaryTreePaths,root,"");
        return ret;
    }
};
