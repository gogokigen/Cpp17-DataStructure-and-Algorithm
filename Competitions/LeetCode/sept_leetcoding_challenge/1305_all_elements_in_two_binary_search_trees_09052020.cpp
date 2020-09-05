/*******************************************************************
* https://leetcode.com/problems/all-elements-in-two-binary-search-trees/
* Medium
* 
* Conception: 
*  1. 
*
* Given two binary search trees root1 and root2.
* Return a list containing all the integers from both trees sorted in ascending order.
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
    void getElements(TreeNode* root, vector<int> &res){
        if(root == nullptr ){
            return;
        }
        
         getElements(root->left, res);
         res.push_back(root->val);
         getElements(root->right, res);    
    }
    
    vector<int> merge(vector<int>& list1, vector<int>& list2 ){
        int size1 = list1.size();
        int size2 = list2.size();
        
        vector<int> result (size1 + size2);
        
        int i = 0, j = 0, k = 0;
        while(i < size1 && j < size2){
            if(list1[i] < list2[j])
                result[k++] = list1[i++];
            else
                result[k++] = list2[j++];
        }
        
        while(i < size1)
            result[k++] = list1[i++];
        while(j < size2)
            result[k++] = list2[j++];
        
        return result;
    }

    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> list1, list2;
        getElements(root1, list1);
        getElements(root2, list2);
        vector<int> res = merge(list1, list2);
        return res;
    }
};