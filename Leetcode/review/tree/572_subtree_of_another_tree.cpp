/*******************************************************************
* https://leetcode.com/problems/subtree-of-another-tree/
* Easy
* 
* Conception: 
*  1. 
*
* Given two non-empty binary trees s and t,
* check whether tree t has exactly the same structure and node values with a subtree of s.
* A subtree of s is a tree consists of a node in s and all of this node's descendants.
* The tree s could also be considered as a subtree of itself.
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
    bool isSubtree(TreeNode* s, TreeNode* t) {
        return traverse(s,t);
    }

    bool equals(TreeNode* x, TreeNode* y){
        if(x==nullptr && y==nullptr)
            return true;
        if(x==nullptr || y==nullptr)
            return false;
        return x->val==y->val && equals(x->left,y->left) && equals(x->right,y->right);
    }
    bool traverse(TreeNode* s, TreeNode* t){
        return  s!= nullptr && ( equals(s,t) || traverse(s->left,t) || traverse(s->right,t));
    }
};
