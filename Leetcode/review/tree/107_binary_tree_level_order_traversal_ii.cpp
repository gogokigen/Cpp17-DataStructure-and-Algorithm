/*******************************************************************
* https://leetcode.com/problems/binary-tree-level-order-traversal-ii/
* Easy
* 
* Conception: 
*  1. 
*
* Given a binary tree, return the bottom-up level order traversal of its nodes' values.
* (ie, from left to right, level by level from leaf to root).
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
/**
 * Definition for a binary tree node.
 * pqruct TreeNode {
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        // Itachi is our ans vector and ace is a temporary vector created for every new level
        stack<TreeNode*> st;
        queue<TreeNode*> pq;

        // Now insert the element from right to left
        pq.push(root); pq.push(NULL);

        vector<vector<int>> itachi;

        // If its a empty tree
        if(!root){
            return itachi;
        }

        st.push(root) ;
        while(!pq.empty()){
            auto it = pq.front(); pq.pop();

            // Insert a NULL character so as to ensure the beginning of a new level
            if(it == NULL and pq.size()){
                st.push(NULL);
                pq.push(NULL);
                continue;
            }
            st.push(it);

            // Insert the right child first because its a stack (LIFO)
            if(it != NULL and it -> right != NULL){
                pq.push(it -> right);
            }
            if(it != NULL and it -> left != NULL){
                pq.push(it -> left);
            }
        }
        
        vector<int>ace;
        while(!st.empty()){
            auto it = st.top(); st.pop();
            // Whenever there is a NULL just insert current level into our 2d vector
            if(it == NULL or st.size() == 0){
                if(ace.size())
                itachi.push_back(ace); ace.clear();
                continue;
            }
            ace.push_back(it -> val);
        }
        return itachi;
    }
};

class Solution {
public:
    int maxDepth(TreeNode* root){
        if(root==NULL) return -1;
        return max(1 + maxDepth(root->left), 1+ maxDepth(root->right));
    }
    void dfs(TreeNode* root, vector<vector<int>> &ans, int level){
        if(root==NULL){
            return ;
        }
        ans[level].push_back(root->val);
        dfs(root->left, ans, level + 1);
        dfs(root->right, ans, level + 1);
    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL)
            return ans;
        int depth = maxDepth(root);   //maxDepth function will find number of levels present in the binary tree
        ans.resize(1 + depth);
        dfs(root, ans, 0);
        reverse(ans.begin(),ans.end()); //Reversing the array to make it bottom up traversal
        return ans;
    }
};
