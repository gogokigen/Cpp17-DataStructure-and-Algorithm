/*******************************************************************
* https://leetcode.com/problems/binary-tree-level-order-traversal-ii/
* Easy
* 
* Conception: 
*  1. 
*
* Given a binary tree, return the bottom-up level order traversal of its nodes' values.
* (ie, from left to right, level by level from leaf to root).
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
    int maxDepth(TreeNode* root){
        if(root==NULL) return -1;
        return max(1 + maxDepth(root->left), 1+ maxDepth(root->right));
    }
    void dfs(TreeNode* root, vector<vector<int>> &ans, int level){
        if(root==NULL){
            return ;
        }
        ans[level].push_back(root->val);
        dfs(root->left, ans, level + 1);
        dfs(root->right, ans, level + 1);
    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL)
            return ans;
        int depth = maxDepth(root);   //maxDepth function will find number of levels present in the binary tree
        ans.resize(1 + depth);
        dfs(root, ans, 0);
        reverse(ans.begin(),ans.end()); //Reversing the array to make it bottom up traversal
        return ans;
    }
};