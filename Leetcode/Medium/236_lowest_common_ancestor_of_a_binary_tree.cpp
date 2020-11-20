/*******************************************************************
* https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
* Medium
* 
* Conception: 
*  1. 
*
* Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.
* According to the definition of LCA on Wikipedia:
* “The lowest common ancestor is defined between two nodes p and q as the lowest node in T
* that has both p and q as descendants (where we allow a node to be a descendant of itself).”
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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    TreeNode* ans;
    bool helper(TreeNode* curr, TreeNode* p, TreeNode* q){
        if(!curr) return false;
        int left = helper(curr->left, p, q) ? 1: 0;
        int right = helper(curr->right, p, q) ? 1: 0;
        int mid = (curr == p || curr == q) ? 1 : 0;
        
        if(mid + left + right >= 2){
            ans = curr;
        }
        return (mid + left + right > 0);
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        helper(root, p, q);
        return ans;
    }
};