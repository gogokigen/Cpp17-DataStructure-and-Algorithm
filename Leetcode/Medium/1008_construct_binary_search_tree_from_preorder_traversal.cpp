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

        TreeNode* root = new TreeNode(preorder[0]);
        stack<TreeNode*> s;
        s.push(root);

        for(int i = 1; i < preorder.size(); i++){
            if(s.top()->val > preorder[i]){
                TreeNode * temp = new TreeNode(preorder[i]);
                s.top()->left = temp;
                s.push(temp); 
            }else {
                TreeNode* temp = NULL;
                while(!s.empty()
                      &&s.top()->val < preorder[i]){
                    temp = s.top();
                    s.pop();
                }
                TreeNode * newNode = new TreeNode(preorder[i]);
                temp->right = newNode;
                s.push(newNode);
            }
        }
        return root;
    }
};