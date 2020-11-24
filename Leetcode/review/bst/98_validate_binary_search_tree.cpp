/*******************************************************************
* https://leetcode.com/problems/validate-binary-search-tree/
* Medium
* 
* Conception: 
*  1. Recursion
*
* Given a binary tree, determine if it is a valid binary search tree (BST).
*
* Assume a BST is defined as follows:
*
*    The left subtree of a node contains only nodes with keys less than the node's key.
*    The right subtree of a node contains only nodes with keys greater than the node's key.
*    Both the left and right subtrees must also be binary search trees.
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
//Inorder in BST: left < root < right
class Solution {

    bool helper(TreeNode* root, long& min){
        if(!root) return true;

        if(!helper(root->left , min))
            return false;
        
        if(root->val <= min){
            return false;
        } else {
            min = root->val;
        }
        if(!helper(root->right , min))
            return false;
        
        return true;
    }
public:
    bool isValidBST(TreeNode* root) {
        
        if(!root) return true;

        long min = LONG_MIN;
        return helper(root, min);
    }
};

// Iteration
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        long pre = LONG_MIN;
        stack<TreeNode*> cache;
        while (root || !cache.empty()) {
            while (root) {
                cache.push(root);
                root = root -> left;
            }
            root = cache.top();
            cache.pop();
            if (root -> val <= pre) {
                return false;
            }
            pre = root -> val;
            root = root -> right;
        }
        return true;
    }
};