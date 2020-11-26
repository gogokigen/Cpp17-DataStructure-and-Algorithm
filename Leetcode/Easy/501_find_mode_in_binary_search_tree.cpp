/*******************************************************************
* https://leetcode.com/problems/find-mode-in-binary-search-tree/
* Easy
* 
* Conception: 
*  1. 
*
* Given a binary search tree (BST) with duplicates,
* find all the mode(s) (the most frequently occurred element) in the given BST.
*
*
* Key:
*  1. inoeder of BST is an increasing array.
*
* Explanation:
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
    void help(TreeNode* root, vector<int>& ans, int& maxFreq, int& count, int& prev){
        if(!root) return;
        
        help(root->left, ans, maxFreq, count, prev);
        
        if(root->val == prev){
            count++;
        }else{
            count = 1;
        }
        
        if(count > maxFreq){
            ans.clear();
            ans.push_back(root->val);
            maxFreq = count;
        } else if(count == maxFreq){
            ans.push_back(root->val);
        }
        
        prev = root->val;

        help(root->right, ans, maxFreq, count, prev);
    }

public:
    vector<int> findMode(TreeNode* root) {
        vector<int> ans;
        int maxFreq = INT_MIN;
        int count = 0;
        int prev = -1;
        
        help(root, ans, maxFreq, count, prev);
        
        return ans;
    }
};