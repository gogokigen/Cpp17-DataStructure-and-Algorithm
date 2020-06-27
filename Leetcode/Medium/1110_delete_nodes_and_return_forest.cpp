/*******************************************************************
* https://leetcode.com/problems/delete-nodes-and-return-forest/
* Medium
* 
* Conception: 
*  1. 
*
* Given a positive integer n, find the least number of perfect square numbers
* (for example, 1, 4, 9, 16, ...) which sum to n.
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
    TreeNode* help(TreeNode* root, unordered_set<int>& delList, vector<TreeNode*>& result){
        if (!root) return NULL;
        
        root->left = help(root->left, delList, result);
        root->right = help(root->right, delList, result);
        if(delList.count(root->val)){
            if(root->left){
                //cout<< "root->left: " << root->left->val <<endl;
                result.push_back(root->left);
            }
            if(root->right){
                //cout<< "root->right: " << root->right->val <<endl;
                result.push_back(root->right);
            }
            
            //replace "the node in delList as NULL"
            return NULL;
        }
        return root;
    }
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> result;
        unordered_set<int> delList(to_delete.begin(), to_delete.end());
        if(help(root, delList, result)){
            //add original tree (which has been removed some nodes) in the end
            result.push_back(root);
        }
        return result;
    }
};