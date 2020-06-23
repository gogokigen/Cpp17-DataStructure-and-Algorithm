/*******************************************************************
* https://leetcode.com/problems/count-complete-tree-nodes/
* Medium
* 
* Conception: 
*  1. Binary tree
*  2. Recursive
*
* Given a complete binary tree, count the number of nodes.
*
* Example:
*
*
* Key:
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
public:
    
    // Solution 1:
    void countSubNodes(TreeNode* root, int *ret) {
        if (root==NULL) return;
        *ret = *ret+1;

        countSubNodes(root->left, ret);
        countSubNodes(root->right, ret);
    }
        
    int countNodes(TreeNode* root) {
        if (root==NULL) return 0;
        int ret = 0;
        countSubNodes(root, &ret);
        return ret;
    }
    
    
    // Solution 2:
    int countNodes(TreeNode* root) {
        if (root==NULL) return 0;

        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};