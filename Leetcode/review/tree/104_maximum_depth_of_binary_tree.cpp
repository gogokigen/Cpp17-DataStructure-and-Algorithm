/*******************************************************************
* https://leetcode.com/problems/maximum-depth-of-binary-tree/
* Easy
* 
* Conception: 
*  1. Recursion
*
* Given a binary tree, find its maximum depth.
* The maximum depth is the number of nodes
* along the longest path from the root node down to the farthest leaf node.
*
* Note: A leaf is a node with no children.
*
*
* Example:
*
* Key:
*  1. 
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
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        
        int l = maxDepth(root->left);
        int r = maxDepth(root->right);
        
        return max( l , r) + 1;
    }
};
