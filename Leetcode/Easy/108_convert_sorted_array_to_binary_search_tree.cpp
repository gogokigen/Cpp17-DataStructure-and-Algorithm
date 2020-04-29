/*******************************************************************
* https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
* Easy
* 
* Conception: 
*  1. 
*
* Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
*
* For this problem, a height-balanced binary tree is defined as
* a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
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
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    TreeNode* buildTree(vector<int>&nums ,int l, int r){
        if(l > r) return nullptr;
        
        int m = l + (r - l) / 2;
        auto root = new TreeNode(nums[m]);
        root->left = buildTree(nums, l, m -1);
        root->right = buildTree(nums, m + 1, r);
        return root;
    }

public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size() == 0) return nullptr;

        return buildTree(nums, 0, nums.size() - 1);
    }
};