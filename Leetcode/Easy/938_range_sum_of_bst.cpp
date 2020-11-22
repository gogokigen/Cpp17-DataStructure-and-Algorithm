/*******************************************************************
* https://leetcode.com/problems/range-sum-of-bst/
* Easy
* 
* Conception: 
*  1. 
*
* Given the root node of a binary search tree,
* return the sum of values of all nodes with a value in the range [low, high].
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
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(not root)    return 0;
        int sum = 0;
        if(root->val < low)
            sum = rangeSumBST(root->right, low, high);
        if(root->val > high)
            sum = rangeSumBST(root->left, low, high);
        if(root->val >= low and root->val <= high){
            //cout << root->val << endl;
            sum = rangeSumBST(root->left, low, high) + \
                    rangeSumBST(root->right, low, high) + root->val;
        }
        return sum;
    }
};