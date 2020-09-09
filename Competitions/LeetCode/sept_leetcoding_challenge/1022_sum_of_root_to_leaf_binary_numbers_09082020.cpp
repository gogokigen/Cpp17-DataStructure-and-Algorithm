/*******************************************************************
* https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/
* Easy
* 
* Conception: 
*  1. 
*
* Given a binary tree, each node has value 0 or 1.
* Each root-to-leaf path represents a binary number starting with the most significant bit.
* For example, if the path is 0 -> 1 -> 1 -> 0 -> 1,
* then this could represent 01101 in binary, which is 13.
*
* For all leaves in the tree,
* consider the numbers represented by the path from the root to that leaf.
*
* Return the sum of these numbers.
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
    int sumRootToLeafHelper(TreeNode* rt, int cur_val) {
        if(! rt) return 0;
        
        cur_val = (cur_val << 1) | rt->val;
        
        if(!rt->left && !rt->right)
			return cur_val;
			
        return sumRootToLeafHelper(rt->left, cur_val) + sumRootToLeafHelper(rt->right, cur_val);
    }
    
    int sumRootToLeaf(TreeNode* rt) {
        return sumRootToLeafHelper(rt, 0);
    }
};