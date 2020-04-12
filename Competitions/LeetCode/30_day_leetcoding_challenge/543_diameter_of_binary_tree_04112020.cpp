/*******************************************************************
* https://leetcode.com/problems/diameter-of-binary-tree/
* Easy
* 
* Conception: 
*  1. 
*
* Given a binary tree, you need to compute the length of the diameter of the tree.
* The diameter of a binary tree is the length of the longest path between any two nodes in a tree.
* This path may or may not pass through the root. 
*
* Example:
*
*
* Key:
*  1. 
*
* Advanced:
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
private:
    int longest;
public:
    int depth (TreeNode* root){
        if (root==NULL) return 0;
        int L = depth(root->left);
        int R = depth(root->right);
        longest = max(longest, L+R+1);
        return max(L,R)+1;
        
    }
    int diameterOfBinaryTree(TreeNode* root) {
        longest = 1;
        depth(root);
        return longest-1;
    }
};