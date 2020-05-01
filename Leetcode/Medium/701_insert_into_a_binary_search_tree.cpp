/*******************************************************************
* https://leetcode.com/problems/insert-into-a-binary-search-tree/
* Medium
* 
* Conception: 
*  1. definition of binary search tree
*
* Given the root node of a binary search tree (BST) and a value to be inserted into the tree,
* insert the value into the BST. Return the root node of the BST after the insertion.
* It is guaranteed that the new value does not exist in the original BST.
*
* Note that there may exist multiple valid ways for the insertion,
* as long as the tree remains a BST after insertion. You can return any of them.
*
*
* Key:
*  1. 
*
* References:
*  1. https://leetcode.com/articles/insert-into-a-bst/#
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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == NULL) return new TreeNode(val);

        if (root->val > val){
            root->left = insertIntoBST(root->left, val);
        }else {
            root->right = insertIntoBST(root->right, val);
        }
        return root;
    }
    // Iterator
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* curr = root;
        
        while(curr != NULL){
            if (curr->val > val){
                if(!curr->left){
                    curr->left = new TreeNode(val);
                    return root;
                }else{
                    curr = curr->left;
                }
            }else {
                if(!curr->right){
                    curr->right = new TreeNode(val);
                    return root;
                }else{
                    curr = curr->right;
                }
            }
        }
        return root;
    }
};