/*******************************************************************
* https://leetcode.com/problems/sum-root-to-leaf-numbers/
* Medium
* 
* Conception: 
*  1. 
*
* Given a binary tree containing digits from 0-9 only,
* each root-to-leaf path could represent a number.
*
* An example is the root-to-leaf path 1->2->3 which represents the number 123.
*
* Find the total sum of all root-to-leaf numbers.
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
private:
    int totalSum = 0;
    void helper(TreeNode* root, int tmpSum){
        if(root == nullptr) return;

        if(root->left == nullptr && root->right == nullptr){
            totalSum += tmpSum*10 + root->val;
            return;
        }
        helper(root->left, tmpSum*10 + root->val);
        helper(root->right, tmpSum*10 + root->val);
    }
public:
    int sumNumbers(TreeNode* root) {
        totalSum = 0;
        helper(root, 0);
        return totalSum;
    }
};