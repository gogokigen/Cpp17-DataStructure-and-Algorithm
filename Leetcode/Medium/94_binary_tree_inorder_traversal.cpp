/*******************************************************************
* https://leetcode.com/problems/binary-tree-inorder-traversal/
* Medium
* 
* Conception: 
*  1. 
*
* Given a binary tree, return the inorder traversal of its nodes' values.
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        inorder(root, ans);
        return ans;
    }
    void inorder(TreeNode* root, vector<int>& ans){
        if(root == nullptr) return;
        inorder(root->left, ans);
        ans.push_back(root->val);
        inorder(root->right, ans);
    }
};
