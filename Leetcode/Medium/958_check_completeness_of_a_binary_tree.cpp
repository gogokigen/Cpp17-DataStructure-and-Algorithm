/*******************************************************************
* https://leetcode.com/problems/check-completeness-of-a-binary-tree/
* Medium
* 
* Conception: 
*  1. complete
*
* Given a binary tree, determine if it is a complete binary tree.
*
* Example:
*
*
* Refeences:
*  1. https://www.geeksforgeeks.org/check-whether-binary-tree-complete-not-set-2-recursive-solution/
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
    int countNodes(TreeNode* root){
        if(root == nullptr) return 0;
        
        return (1 + countNodes(root->left) + countNodes(root->right));
    }
    bool isComplete(TreeNode* root, int index, int totalNodes){
        if(root == nullptr) return true;
        if(index >= totalNodes) return false;
        return isComplete(root->left, 2*index + 1, totalNodes)
            && isComplete(root->right, 2*index + 2, totalNodes);
    }

public:
    bool isCompleteTree(TreeNode* root) {
        int total = countNodes(root);
        return isComplete(root, 0, total);
    }
};