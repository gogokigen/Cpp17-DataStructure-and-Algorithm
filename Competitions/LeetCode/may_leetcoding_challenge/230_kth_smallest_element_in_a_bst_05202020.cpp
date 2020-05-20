/*******************************************************************
* https://leetcode.com/problems/kth-smallest-element-in-a-bst/
* Medium
* 
* Conception: 
*  1. 
*
* Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.
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
private:

    void inorder(TreeNode* root, int k, vector<int> &tbl) {
        if(root == NULL) return;
        //out << "left" << endl;
        inorder(root->left, k, tbl);
        
        //cout << "in" << endl;
        tbl.push_back(root->val);
        if(tbl.size() == k) return;
        //cout << "right" << endl;
        inorder(root->right, k, tbl);
    }

public:
    int kthSmallest(TreeNode* root, int k) {
        if(root == NULL) return -1;
        vector<int> tbl;
        inorder(root, k, tbl);
        
        //if(tbl.size() < k) return -1;
        
        return tbl[k-1];
    }
};