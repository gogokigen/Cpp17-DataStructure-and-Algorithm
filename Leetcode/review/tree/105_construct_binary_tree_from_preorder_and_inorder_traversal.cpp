/*******************************************************************
* https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
* Medium
* 
* Conception: 
*  1. 
*
* Given preorder and inorder traversal of a tree, construct the binary tree.
*
*
* Example:
*
*
* Key:
*  1. 
*
* Reference:
*  1. https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/discuss/340504/C%2B%2B-simple-recursive-(%2B-detail-explanation)
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
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int& rootIdx, int left, int right) {
        if (left > right) return NULL;
        int pivot = left;
        while(inorder[pivot] != preorder[rootIdx]) pivot++;
        
        rootIdx++;
        TreeNode* newRoot = new TreeNode(inorder[pivot]);
        newRoot->left = build(preorder, inorder, rootIdx, left, pivot-1);
        newRoot->right = build(preorder, inorder, rootIdx, pivot + 1, right);
        return newRoot;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int rootIdx = 0;
        return build(preorder, inorder, rootIdx, 0, inorder.size()-1);
    }
};