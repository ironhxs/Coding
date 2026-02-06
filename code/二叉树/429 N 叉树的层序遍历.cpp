// N 叉树的层序遍历
// 关键点: 层序遍历，遍历 children 数组入队
// 易错点: children 可能为空指针
// 日期: 2026.02.06

#include <vector>
#include <queue>
using namespace std;

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ret;
        if(!root)
            return ret;
        queue<Node*> que;
        que.push(root);
        while(!que.empty()){
            int n = que.size();
            vector<int> v;
            for(int i = 0;i <= n - 1;i++){
                Node* node = que.front();
                que.pop();
                v.push_back(node->val);
                for(auto & e:node->children){
                    if(e)
                        que.push(e);
                }
            }
            ret.push_back(v);
        }
        return ret;
    }
};
