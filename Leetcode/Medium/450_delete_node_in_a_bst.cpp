/*******************************************************************
* https://leetcode.com/problems/delete-node-in-a-bst/
* Medium
* 
* Conception: 
*  1. definition of binary search tree
*
* Given a root node reference of a BST and a key,
* delete the node with the given key in the BST.
* Return the root node reference (possibly updated) of the BST.
*
* Basically, the deletion can be divided into two stages:
*    Search for a node to remove.
*    If the node is found, delete the node.
*
* Note: Time complexity should be O(height of tree).
*
*
* Key:
*  1. 
*
* References:
*  1. https://leetcode.com/articles/delete-node-in-a-bst/#
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
private:
    //Successor = "after node", i.e. the next node, or the smallest node after the current one.
    int successor(TreeNode* root) {
        root = root->right;
        while(root->left){
            root = root->left;
        }
        return root->val;
    }
    //Predecessor = "before node", i.e. the previous node, or the largest node before the current one.
    int predecessor(TreeNode* root) {
        root = root->left;
        while(root->right){
            root = root->right;
        }
        return root->val;
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL) return NULL;
        if(root->val > key){
            root->left = deleteNode(root->left, key);
        }else if (root->val < key) {
            root->right = deleteNode(root->right, key);
        }else{
            //root is leaf
            if(!root->left && !root->right){
                root = NULL;
            }else if(root->right){
                //find a node from right subtree
                root->val = successor(root);
                root->right = deleteNode(root->right, root->val);
            }else{
                //find a node from left subtree
                root->val = predecessor(root);
                root->left = deleteNode(root->left, root->val);
            }
        }
        return root;
    }
};