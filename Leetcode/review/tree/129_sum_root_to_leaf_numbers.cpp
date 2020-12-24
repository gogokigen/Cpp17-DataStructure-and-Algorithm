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
    int sum = 0;
    void dfs(TreeNode* root, int num){
        if (!root) return;
        
        if(root->left == nullptr && root->right == nullptr){
            sum += num*10 + root->val;
            return;
        }
        num = num * 10 + root->val;
        

        dfs(root->left, num);
        dfs(root->right, num);
    }
public:
    int sumNumbers(TreeNode* root) {
        if (!root) return 0;
        dfs(root, 0);
        
        return sum;
    }
};
