/*******************************************************************
* https://leetcode.com/problems/maximum-sum-bst-in-binary-tree/
* Hard
* 
* Conception: 
*  1. 
*
* Given a binary tree root, the task is to 
* return the maximum sum of all keys of any sub-tree
* which is also a Binary Search Tree (BST).
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
    pair<vector<int>, bool> recurse (TreeNode * root, int & maxSum){
		//maintain max and min at each node for curr node and nodes below it
		//left_max should be less than root and right_min should be more than root
        if (not root) return make_pair(vector<int>({0, INT_MIN, INT_MAX }), true);
        
        auto left = recurse(root->left, maxSum );
        auto right = recurse(root->right, maxSum);
        
        int left_max = left.first[1];
        int left_min = left.first[2];
        int right_max = right.first[1];
        int right_min = right.first[2];

        int total = left.first[0] + right.first[0] + root->val;
        bool cond = (left_max < root -> val ) and (right_min > root -> val);
        
        bool isBST = left.second and right.second and cond ; 
        if (isBST) maxSum = max(maxSum, total);
        
        int curr_max = max(max (left_max, root -> val) , right_max);
        int curr_min = min(min (left_min, root -> val) , right_min);
        
        //return make_pair(vector<int>({total, curr_max, curr_min}), isBST);
        return {vector<int>({total, curr_max, curr_min}), isBST};
    }
    
public:
    int maxSumBST(TreeNode* root) {
        
        int maxSum = 0;
        recurse(root, maxSum);
        return maxSum ;
    }
};
