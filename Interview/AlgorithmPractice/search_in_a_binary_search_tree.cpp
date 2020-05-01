/*******************************************************************
* https://leetcode.com/problems/search-in-a-binary-search-tree/
* Easy
* 
* Conception: 
*  1. definition of binary search tree
*
* Given the root node of a binary search tree (BST) and a value.
* You need to find the node in the BST that the node's value equals the given value.
* Return the subtree rooted with that node. If such node doesn't exist, you should return NULL.
*
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
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // Recursive
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root == NULL) return NULL;
        if(root->val == val){
            return root;
        } else {
            if (root->val > val){
                return searchBST(root->left, val);
            }else {
                return searchBST(root->right, val);
            }
        }
        return NULL;
    }
    // Iterator
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root == NULL) return NULL;

        while(root != NULL && val != root->val){
            if (root->val > val){
                root = root->left;
            }else {
                root = root->right;
            }
        }
        return root;
    }
};