/*******************************************************************
* https://leetcode.com/problems/binary-tree-maximum-path-sum/
* Hard
* 
* Conception: 
*  1. 
*
* Given a non-empty binary tree, find the maximum path sum.
*
* For this problem, a path is defined as
* any sequence of nodes from some starting node to any node in the tree along the parent-child connections.
* The path must contain at least one node and does not need to go through the root.
*
*
* Reference:
*  1. https://www.youtube.com/watch?v=9ZNky1wqNUw
*
* Key:
*  1. sum = l + r + root->val, but return max(l , r) + root->val
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
    int helper(TreeNode* root, int& ans){
        if(root == nullptr) return 0;

        int l = max(helper(root->left, ans), 0 );
        int r = max(helper(root->right, ans), 0 );

        ans = max(ans, l + r + root->val); // check whether should I pick up root->val
                             // if ans = ans -> NO, ans = sum -> YES
        return max(l + root->val , r + root->val); // bottom up
    }
public:
    int maxPathSum(TreeNode* root) {
        if(root == nullptr) return 0;
        int ans = INT_MIN;
        helper(root, ans);
        return ans;
    }
};
