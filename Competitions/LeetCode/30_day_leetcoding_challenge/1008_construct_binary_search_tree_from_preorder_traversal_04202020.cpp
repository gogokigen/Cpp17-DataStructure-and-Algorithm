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
//Method 1:
    TreeNode* bstFromPreorder_Stack(vector<int>& preorder) {
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

// Method 2
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if (preorder.size() == 0) 
            return NULL;

        return helper(preorder, 0, preorder.size());
    }
private:
    TreeNode* helper(vector<int>& preorder, int start, int end){
        if(start >= end) return NULL;
        
        TreeNode* root = new TreeNode(preorder[start]);
        int split = start;
        while(split < end && preorder[start] >= preorder[split] ){
            ++split;
            //i = star+1 .. split, preorder[i] <= preorder[start]
        }

        root->left = helper(preorder, start+1, split); // smaller in left
        root->right = helper(preorder, split, end); // larger in right
        return root;
    }
};