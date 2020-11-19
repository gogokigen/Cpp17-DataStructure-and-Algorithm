/*******************************************************************
* https://leetcode.com/problems/path-sum/
* Easy
* 
* Conception: 
*  1. 
*
* Given a binary tree and a sum,
* determine if the tree has a root-to-leaf path such that
* adding up all the values along the path equals the given sum.
*
* Note: A leaf is a node with no children.
*
*
* Example:
*
* Key:
*  1. 
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
    bool hasPathSum(TreeNode* root, int sum) {
        if(root == nullptr) return false;
        
        sum -= root->val;
        if(root->right == nullptr && root->left == nullptr){
            if(sum == 0){
                return true;
            }
            return false;
        }
        
        return hasPathSum(root->right, sum) || hasPathSum(root->left, sum);
    }
};