/*******************************************************************
* https://leetcode.com/problems/n-ary-tree-level-order-traversal/
* Medium
* 
* Conception: 
*  1. 
*
* Given an n-ary tree, return the level order traversal of its nodes' values.
* Nary-Tree input serialization is represented in their level order traversal,
* each group of children is separated by the null value (See examples).
*
*
* Example:
*
* Key:
*  1. 
*
* References:
*  1.
*
*******************************************************************/
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
        vector<vector<int>> ans;
        queue<Node*> q;
        
        if(root) q.push(root);
        
        while(!q.empty()){
            int n = q.size();
            vector<int> level;
            while(n--){
                Node* tmp = q.front();
                q.pop();
                level.push_back(tmp->val);
                int child_len = tmp->children.size();
                for(int i = 0; i < child_len; i++){
                    q.push(tmp->children[i]);
                }
            }
            ans.push_back(level);
        }
        return ans;
    }
};