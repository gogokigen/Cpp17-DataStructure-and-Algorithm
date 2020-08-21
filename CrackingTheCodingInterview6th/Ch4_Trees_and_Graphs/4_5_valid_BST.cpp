/*******************************************************************
* 
* Practice: Valid BST
* 
* References: 
*  1. https://leetcode.com/problems/validate-binary-search-tree/
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
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    bool inorderTraverse(TreeNode* root, long& min) {
        if(!root) return true;
        
        if(!inorderTraverse(root->left, min)) return false;
        
        if(root->val <= min){
            return false;
        } else {
            min = root->val;
        }

        if(!inorderTraverse(root->right, min)) return false;
        
        return true;
    }
public:
    bool isValidBST(TreeNode* root) {
        if(!root || (!root->left && !root->right) ) return true;
        long min = LONG_MIN;
        return inorderTraverse(root, min);
    }
};