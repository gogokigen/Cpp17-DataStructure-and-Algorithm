/*******************************************************************
* https://leetcode.com/problems/validate-binary-search-tree/
* Medium
* 
* Conception: 
*  1. Recursion
*
* Given a binary tree, determine if it is a valid binary search tree (BST).
*
* Assume a BST is defined as follows:
*
*    The left subtree of a node contains only nodes with keys less than the node's key.
*    The right subtree of a node contains only nodes with keys greater than the node's key.
*    Both the left and right subtrees must also be binary search trees.
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
//Recurssive
class Solution {
private:
    bool isValidSubBST(TreeNode* root, long long min, long long max) {
        if(!root) return true;

        if(root->val <= min || root->val >= max) return false;
        if(!isValidSubBST(root->left, min, root->val) || !isValidSubBST(root->right, root->val, max)) return false;
        
        return true;
    }
public:
    bool isValidBST(TreeNode* root) {
        if(!root || (!root->left && !root->right) ) return true;
        
        return isValidSubBST(root, LLONG_MIN, LLONG_MAX);
    }
};

//Inorder in BST: left < root < right
class Solution {
private:
    bool inorderTraverse(TreeNode* root, long& min) {
        if(!root) return true;
        
        if(!inorderTraverse(root->left, min)) return false;
        
        if(root->val <= min){
            return false;
        } else {
            min = root->val;
        }

        if(!inorderTraverse(root->right, min)) return false;
        
        return true;
    }
public:
    bool isValidBST(TreeNode* root) {
        if(!root || (!root->left && !root->right) ) return true;
        long min = LONG_MIN;
        return inorderTraverse(root, min);
    }
};

// Iteration
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        long pre = LONG_MIN;
        stack<TreeNode*> todo;
        while (root || !todo.empty()) {
            while (root) {
                todo.push(root);
                root = root -> left;
            }
            root = todo.top();
            todo.pop();
            if (root -> val <= pre) {
                return false;
            }
            pre = root -> val;
            root = root -> right;
        }
        return true;
    }
};