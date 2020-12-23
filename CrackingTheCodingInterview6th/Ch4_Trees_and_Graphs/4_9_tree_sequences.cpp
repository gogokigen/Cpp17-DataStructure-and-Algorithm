/*******************************************************************
* https://leetcode.com/problems/binary-tree-paths/
* Easy
* 
* Conception: 
*  1. 
*
* Given a binary tree, return all root-to-leaf paths.
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
private:
    void helper(TreeNode* root, string path, vector<string>& paths){
        if(root != nullptr){
            path += to_string(root->val);
            if(root->left == nullptr && root->right == nullptr){
                paths.push_back(path);
            }else{
                path += "->";
                helper(root->left, path, paths);
                helper(root->right, path, paths);
            }
        }
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> paths;
        helper(root, "", paths);
        return paths;
    }
};