/*******************************************************************
* https://leetcode.com/problems/binary-tree-tilt/
* Easy
* 
* Conception: 
*  1. 
*
* Given the root of a binary tree,
* return the sum of every tree node's tilt.
*
* The tilt of a tree node is the absolute difference 
* between the sum of all left subtree node values and all right subtree node values.
* If a node does not have a left child,
* then the sum of the left subtree node values is treated as 0.
* The rule is similar if there the node does not have a right child.
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
    int tilt;
    int dfs(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int leftsum = dfs(root -> left);
        int rightsum = dfs(root -> right);
        tilt += abs(leftsum - rightsum);
        return leftsum + rightsum + root -> val;
    }
    int findTilt(TreeNode* root) {
        dfs(root);
        return tilt;
    }
};