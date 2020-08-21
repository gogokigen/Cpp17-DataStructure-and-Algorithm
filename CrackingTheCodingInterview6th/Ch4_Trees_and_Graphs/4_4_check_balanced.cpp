/*******************************************************************
* 
* Practice: Check Balanced
* 
* References: 
*  1. https://leetcode.com/problems/balanced-binary-tree/
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
    int maxDeep(TreeNode* root){
        if(root == NULL) return -1;
        
        int L = maxDeep(root->left) + 1;
        int R = maxDeep(root->right) + 1;
        return max(L, R);
    }
public:
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;
        
        int deepL = maxDeep(root->left);
        int deepR = maxDeep(root->right);
        
        return abs(deepL - deepR) < 2 && isBalanced(root->left) && isBalanced(root->right) ;
    }
};