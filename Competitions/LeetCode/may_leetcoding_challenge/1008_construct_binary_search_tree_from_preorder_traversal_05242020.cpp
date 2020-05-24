/*******************************************************************
* https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/
* Medium
* 
* Conception: 
*  1. preorder
*
* Return the root node of a binary search tree that matches the given preorder traversal.
*
* Example:
*
* Key:
*  1.
*
* Reference:
*  1. https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/discuss/252273/C%2B%2B-O(n-log-n)-and-O(n)
*
*******************************************************************/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if (preorder.size() == 0) 
            return NULL;
        return helper(preorder, 0, preorder.size());
    }
private:
    TreeNode* helper(vector<int>& preorderArray, int start, int end){

        if(start == end) return NULL;

        TreeNode* root = new TreeNode(preorderArray[start]);
        int split = start;
        while(split < end && preorderArray[start] >= preorderArray[split]){
            split++;
        }
        
        root->left = helper(preorderArray, start+1, split);
        root->right = helper(preorderArray, split, end);
        return root;
    }
};