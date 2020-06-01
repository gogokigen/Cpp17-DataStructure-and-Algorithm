/*******************************************************************
* https://leetcode.com/problems/invert-binary-tree/
* Easy
* 
* Conception: 
*  1. 
*
* Invert a binary tree.
*
*
* Key:
*
*
* Explanation:
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
    TreeNode* invertTree(TreeNode* root) {

        if(root == nullptr) return nullptr;

        TreeNode* right = invertTree(root->right);
        TreeNode* left = invertTree(root->left);


        root->left = right;
        root->right = left;

        return root;
    }
};