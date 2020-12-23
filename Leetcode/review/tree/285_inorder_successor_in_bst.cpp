/*******************************************************************
* https://leetcode.com/problems/inorder-successor-in-bst/
* Medium
* 
* Conception: 
*  1. 
*
* Given a binary search tree and a node in it,
* find the in-order successor of that node in the BST.
*
* The successor of a node p is the node with the smallest key greater
* than p.val.
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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if(!root || !p) return nullptr;
        
        TreeNode* ans;
        while(root){
            if(p->val < root->val){
                ans = root;
                root = root->left;
            }else{
                root = root->right;
            }
        }
        return ans;
    }
};
