/*******************************************************************
* https://leetcode.com/problems/binary-tree-level-order-traversal/
* Medium
* 
* Conception: 
*  1. Recursion
*
* Given a binary tree, return the level order traversal of its nodes' values.
* (ie, from left to right, level by level).
*
*
* Example:
*    3
*   / \
*  9  20
*    /  \
*   15   7
*
*[
*  [3],
*  [9,20],
*  [15,7]
*]
*
*
* Key:
*  1. BFS
*
* Reference:
*  1. 
*
*******************************************************************/
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
 //Recursive
class Solution {
private:
    vector<vector<int>> levels;
    void levelRecursive(TreeNode* root, int level){
        if(levels.size() <= level ){
            levels.push_back(vector<int>());
        }
        levels[level].push_back(root->val);
        
        if(root->left){
            levelRecursive(root->left, level + 1);
        }
        if(root->right){
            levelRecursive(root->right, level + 1);
        }
        
    }
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == NULL) return levels;
        levelRecursive(root, 0);
        return levels;
    }
};

// BFS
// queue: [ 3, 9, 12, 15, 17]
//          ^front
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> levels;
        queue<TreeNode*> q;

        if(root) q.push(root);
        while(!q.empty()){
            vector<int> level;
            int n = q.size();
            while(n--){
                TreeNode* tmp = q.front();
                q.pop();
                level.push_back(tmp->val);
                if(tmp->left) q.push(tmp->left);
                if(tmp->right) q.push(tmp->right);
            }
            levels.push_back(level);
        }
        return levels;
    }
};