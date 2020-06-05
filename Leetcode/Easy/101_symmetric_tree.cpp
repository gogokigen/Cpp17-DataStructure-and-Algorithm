/*******************************************************************
* https://leetcode.com/problems/symmetric-tree/
* Easy
* 
* Conception: 
*  1. 
*
* Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
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
    bool mirror(TreeNode* root1, TreeNode* root2){
        if(root1 == nullptr && root2 == nullptr) return true;
        if(root1 == nullptr || root2 == nullptr) return false;
        
        return ((root1->val == root2->val)
                 && (mirror(root1->right, root2->left))
                 && (mirror(root1->left, root2->right)));


    }
public:
    vector<int> array;
    bool isSymmetric(TreeNode* root) {

        return mirror(root, root);
        
    }
};