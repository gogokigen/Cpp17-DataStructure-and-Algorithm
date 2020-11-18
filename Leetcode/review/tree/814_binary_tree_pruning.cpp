/*******************************************************************
* https://leetcode.com/problems/binary-tree-pruning/
* Medium
* 
* Conception: 
*  1. 
*
* We are given the head node root of a binary tree,
* where additionally every node's value is either a 0 or a 1.
* Return the same tree where every subtree (of the given tree) not containing a 1 has been removed.
* (Recall that the subtree of a node X is X, plus every node that is a descendant of X.)
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
    TreeNode* pruneTree(TreeNode* root) {
        return helper(root) ? root:NULL;
    }
    
    bool helper(TreeNode* root){
        if(!root) return false;
        bool l = helper(root->left);
        bool r = helper(root->right);
        
        if(!l) root->left = NULL;
        if(!r) root->right = NULL;
        return root->val == 1 || l || r;
    }
};