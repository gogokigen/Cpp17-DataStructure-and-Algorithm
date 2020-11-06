/*******************************************************************
* https://leetcode.com/problems/same-tree/
* Easy
* 
* Conception: 
*  1. 
*
* Given two binary trees, write a function to check if they are the same or not.
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
	bool isSameTree(TreeNode* p, TreeNode* q) {
		
		if(p==NULL && q!=NULL)return false;
		if(q==NULL && p!=NULL)return false;

		if(p==NULL && q==NULL)return true;

		bool l = false;
		bool r = false;

		if(p->val == q->val){
			l = isSameTree(p->left,q->left);
			r = isSameTree(p->right,q->right);
		}

		return l&r;        
	}
};
